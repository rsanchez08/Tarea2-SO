#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <signal.h>
#include <errno.h>
#include "syscall_map.h"

// Estructura para contar syscalls
typedef struct {
    const char *name; // Nombre del syscall
    int count; // Cantidad de veces que se llamó
} SyscallCount; 

// Variables globales para opciones
int verbose = 0; // Flag para mostrar detalles de cada syscall
int wait_for_key = 0; // Flag para pausar después de cada syscall

// Función para mostrar ayuda, se despliega ./rastreador -h
void show_help() {
    printf("Uso: rastreador [opciones] PROG [opciones de Prog]\n");
    printf("Opciones:\n");
    printf("  -v  Mostrar detalles de cada syscall\n");
    printf("  -V  Como -v pero pausa después de cada syscall\n");
    printf("  -h  Mostrar esta ayuda\n");
}

// Función para parsear argumentos
void parse_args(int argc, char *argv[], int *prog_index) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strcmp(argv[i], "-v") == 0) {
                verbose = 1;
            } else if (strcmp(argv[i], "-V") == 0) {
                verbose = 1;
                wait_for_key = 1;
            } else if (strcmp(argv[i], "-h") == 0) {
                show_help();
                exit(0);
            } else {
                fprintf(stderr, "Opción INVÁLIDA: %s\n", argv[i]);
                exit(1);
            }
        } else {
            *prog_index = i;
            return;
        }
    }

    fprintf(stderr, "No se especificó un programa para rastrear\n");
    exit(1);
}

// Función para agregar o incrementar un syscall en la lista de conteo
void add_syscall(SyscallCount **counts, int *size, int *capacity, const char *name) {
    // Busca si el syscall ya está registrado
    for (int i = 0; i < *size; i++) {
        if (strcmp((*counts)[i].name, name) == 0) {
            (*counts)[i].count++;
            return;
        }
    }
    
    // Si no existe, agregarlo
    if (*size >= *capacity) {
        *capacity *= 2;
        *counts = realloc(*counts, *capacity * sizeof(SyscallCount));
    }
    
    (*counts)[*size].name = name;
    (*counts)[*size].count = 1;
    (*size)++;
}

// Función para comparar syscalls
int compare_syscalls(const void *a, const void *b) {
    const SyscallCount *sa = (const SyscallCount *)a;
    const SyscallCount *sb = (const SyscallCount *)b;
    return strcmp(sa->name, sb->name);
}

// Función principal de rastreo
void trace_child(pid_t child_pid) {
    int status;
    int syscall_count_size = 0;
    int syscall_count_capacity = 32;
    SyscallCount *syscall_counts = malloc(syscall_count_capacity * sizeof(SyscallCount));
    
    // Esperar a que el hijo se detenga en el primer syscall
    waitpid(child_pid, &status, 0);
    
    while (1) {
        // Verificar si el proceso hijo terminó
        if (WIFEXITED(status) || WIFSIGNALED(status)) {
            break;
        }
        
        // Obtener el número del syscall
        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
        
        #ifdef __x86_64__
        long syscall_num = regs.orig_rax;
        #elif defined(__i386__)
        long syscall_num = regs.orig_eax;
        #else
        #error "Arquitectura no soportada"
        #endif
        
        const char *syscall_name = get_syscall_name(syscall_num);
        
        // Registrar el syscall
        add_syscall(&syscall_counts, &syscall_count_size, &syscall_count_capacity, syscall_name);
        
        // Mostrar detalles si es necesario
        if (verbose) {
            printf("Syscall: %s (%ld)\n", syscall_name, syscall_num);
            
            // Mostrar argumentos si es posible
            #ifdef __x86_64__
            printf("  Args: %ld, %ld, %ld, %ld, %ld, %ld\n", 
                   regs.rdi, regs.rsi, regs.rdx, regs.r10, regs.r8, regs.r9);
            #elif defined(__i386__)
            printf("  Args: %ld, %ld, %ld, %ld, %ld, %ld\n", 
                   regs.ebx, regs.ecx, regs.edx, regs.esi, regs.edi, regs.ebp);
            #endif
            
            if (wait_for_key) {
                printf("Presione cualquier tecla para continuar...");
                getchar();
            }
        }
        
        // Continuar la ejecución hasta el próximo syscall
        ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
        waitpid(child_pid, &status, 0);
    }
    
    // Ordenar los syscalls por nombre
    qsort(syscall_counts, syscall_count_size, sizeof(SyscallCount), compare_syscalls);
    
    // Mostrar el resumen
    printf("\nResumen de syscalls:\n");
    printf("--------------------\n");
    printf("%-20s %s\n", "Syscall", "Count");
    printf("--------------------\n");
    
    for (int i = 0; i < syscall_count_size; i++) {
        printf("%-20s %d\n", syscall_counts[i].name, syscall_counts[i].count);
    }
    
    free(syscall_counts);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_help();
        return 1;
    }
    
    int prog_index = 1;
    parse_args(argc, argv, &prog_index);
    
    pid_t child_pid = fork();
    
    if (child_pid == 0) {
        // Proceso hijo
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execvp(argv[prog_index], &argv[prog_index]);
        perror("execvp");
        exit(1);
    } else if (child_pid > 0) {
        // Proceso padre
        trace_child(child_pid);
    } else {
        perror("fork");
        return 1;
    }
    
    return 0;
}