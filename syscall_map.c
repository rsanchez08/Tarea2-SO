#include "syscall_map.h"
#include <sys/syscall.h>  // Cabecera para números de syscall en ARM

const char *syscall_names[MAX_SYSCALL_NUM];

void init_syscall_names() {
    for (int i = 0; i < MAX_SYSCALL_NUM; i++) {
        syscall_names[i] = "unknown";
    }

    // Mapeo de syscalls para ARM (ejemplos)
    syscall_names[SYS_write]    = "write";
    syscall_names[SYS_read]     = "read";
    syscall_names[SYS_open]     = "open";
    syscall_names[SYS_close]    = "close";
    syscall_names[SYS_stat]     = "stat";
    syscall_names[SYS_fstat]    = "fstat";
    syscall_names[SYS_execve]   = "execve";
    syscall_names[SYS_fork]     = "fork";
    // ... Agrega todos los syscalls necesarios desde <sys/syscall.h>
}