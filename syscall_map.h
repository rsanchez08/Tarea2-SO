#ifndef SYSCALL_MAP_H
#define SYSCALL_MAP_H

#define MAX_SYSCALL_NUM 350

extern const char *syscall_names[];
void init_syscall_names(void);

#endif