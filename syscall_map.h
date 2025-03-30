#ifndef SYSCALL_MAP_H
#define SYSCALL_MAP_H

#include <sys/syscall.h>
#include <unistd.h>

// Estructura para mapear números de syscall a nombres
typedef struct {
    int number;
    const char *name;
} SyscallEntry;

// Función para obtener el nombre de un syscall
const char *get_syscall_name(int syscall_number);

// Tabla de syscalls (definida en syscall_map.c)
extern const SyscallEntry syscall_table[];
extern const int syscall_table_size;

#endif // SYSCALL_MAP_H