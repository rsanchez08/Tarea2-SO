#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/syscall.h>
#include <termios.h>
#include "syscall_map.h"

#define MAX_ARGS 100

int syscall_counts[MAX_SYSCALL_NUM] = {0};
int verbose = 0;
int wait_key = 0;

void wait_for_key() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void execute_target(char **argv) {
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execvp(argv[0], argv);
    perror("execvp");
    exit(EXIT_FAILURE);
}

void trace_child(pid_t pid) {
    int status;
    struct user_regs_struct regs;

    while (1) {
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) break;

        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        long syscall_num = regs.ARM_r7;  // ARM usa r7 para syscalls

        if (syscall_num < MAX_SYSCALL_NUM) {
            syscall_counts[syscall_num]++;
        }

        if (verbose && syscall_num < MAX_SYSCALL_NUM) {
            printf("[+] Syscall: %s (%ld)\n", syscall_names[syscall_num], syscall_num);
            if (wait_key) {
                printf("Presiona cualquier tecla para continuar...");
                wait_for_key();
            }
        }
    }
}


int main(int argc, char **argv) {
    init_syscall_names();

    int opt;
    while ((opt = getopt(argc, argv, "vV")) != -1) {
        switch (opt) {
            case 'v': verbose = 1; break;
            case 'V': verbose = 1; wait_key = 1; break;
            default:
                fprintf(stderr, "Uso: %s [-vV] Prog [opciones...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Error: Debes especificar un programa para ejecutar.\n");
        exit(EXIT_FAILURE);
    }

    char **prog_argv = &argv[optind];
    pid_t pid = fork();

    if (pid == 0) {
        execute_target(prog_argv);
    } else if (pid > 0) {
        trace_child(pid);
        printf("\n=== Resumen de syscalls ===\n");
        for (int i = 0; i < MAX_SYSCALL_NUM; i++) {
            if (syscall_counts[i] > 0) {
                printf("%-20s: %d\n", syscall_names[i], syscall_counts[i]);
            }
        }
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}