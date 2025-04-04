#include "syscall_map.h"

// Tabla de mapeo de syscalls (puede ser extendida según necesidad)
const SyscallEntry syscall_table[] = {
    {SYS_read, "read"},
    {SYS_write, "write"},
    {SYS_open, "open"},
    {SYS_close, "close"},
    {SYS_stat, "stat"},
    {SYS_fstat, "fstat"},
    {SYS_lstat, "lstat"},
    {SYS_poll, "poll"},
    {SYS_lseek, "lseek"},
    {SYS_mmap, "mmap"},
    {SYS_mprotect, "mprotect"},
    {SYS_munmap, "munmap"},
    {SYS_brk, "brk"},
    {SYS_rt_sigaction, "rt_sigaction"},
    {SYS_rt_sigprocmask, "rt_sigprocmask"},
    {SYS_rt_sigreturn, "rt_sigreturn"},
    {SYS_ioctl, "ioctl"},
    {SYS_pread64, "pread64"},
    {SYS_pwrite64, "pwrite64"},
    {SYS_readv, "readv"},
    {SYS_writev, "writev"},
    {SYS_access, "access"},
    {SYS_pipe, "pipe"},
    {SYS_select, "select"},
    {SYS_sched_yield, "sched_yield"},
    {SYS_mremap, "mremap"},
    {SYS_msync, "msync"},
    {SYS_mincore, "mincore"},
    {SYS_madvise, "madvise"},
    {SYS_shmget, "shmget"},
    {SYS_shmat, "shmat"},
    {SYS_shmctl, "shmctl"},
    {SYS_dup, "dup"},
    {SYS_dup2, "dup2"},
    {SYS_pause, "pause"},
    {SYS_nanosleep, "nanosleep"},
    {SYS_getitimer, "getitimer"},
    {SYS_alarm, "alarm"},
    {SYS_setitimer, "setitimer"},
    {SYS_getpid, "getpid"},
    {SYS_sendfile, "sendfile"},
    {SYS_socket, "socket"},
    {SYS_connect, "connect"},
    {SYS_accept, "accept"},
    {SYS_sendto, "sendto"},
    {SYS_recvfrom, "recvfrom"},
    {SYS_sendmsg, "sendmsg"},
    {SYS_recvmsg, "recvmsg"},
    {SYS_shutdown, "shutdown"},
    {SYS_bind, "bind"},
    {SYS_listen, "listen"},
    {SYS_getsockname, "getsockname"},
    {SYS_getpeername, "getpeername"},
    {SYS_socketpair, "socketpair"},
    {SYS_setsockopt, "setsockopt"},
    {SYS_getsockopt, "getsockopt"},
    {SYS_clone, "clone"},
    {SYS_fork, "fork"},
    {SYS_vfork, "vfork"},
    {SYS_execve, "execve"},
    {SYS_exit, "exit"},
    {SYS_wait4, "wait4"},
    {SYS_kill, "kill"},
    {SYS_uname, "uname"},
    {SYS_semget, "semget"},
    {SYS_semop, "semop"},
    {SYS_semctl, "semctl"},
    {SYS_shmdt, "shmdt"},
    {SYS_msgget, "msgget"},
    {SYS_msgsnd, "msgsnd"},
    {SYS_msgrcv, "msgrcv"},
    {SYS_msgctl, "msgctl"},
    {SYS_fcntl, "fcntl"},
    {SYS_flock, "flock"},
    {SYS_fsync, "fsync"},
    {SYS_fdatasync, "fdatasync"},
    {SYS_truncate, "truncate"},
    {SYS_ftruncate, "ftruncate"},
    {SYS_getdents, "getdents"},
    {SYS_getcwd, "getcwd"},
    {SYS_chdir, "chdir"},
    {SYS_fchdir, "fchdir"},
    {SYS_rename, "rename"},
    {SYS_mkdir, "mkdir"},
    {SYS_rmdir, "rmdir"},
    {SYS_creat, "creat"},
    {SYS_link, "link"},
    {SYS_unlink, "unlink"},
    {SYS_symlink, "symlink"},
    {SYS_readlink, "readlink"},
    {SYS_chmod, "chmod"},
    {SYS_fchmod, "fchmod"},
    {SYS_chown, "chown"},
    {SYS_fchown, "fchown"},
    {SYS_lchown, "lchown"},
    {SYS_umask, "umask"},
    {SYS_gettimeofday, "gettimeofday"},
    {SYS_getrlimit, "getrlimit"},
    {SYS_getrusage, "getrusage"},
    {SYS_sysinfo, "sysinfo"},
    {SYS_times, "times"},
    {SYS_ptrace, "ptrace"},
    {SYS_getuid, "getuid"},
    {SYS_syslog, "syslog"},
    {SYS_getgid, "getgid"},
    {SYS_setuid, "setuid"},
    {SYS_setgid, "setgid"},
    {SYS_geteuid, "geteuid"},
    {SYS_getegid, "getegid"},
    {SYS_setpgid, "setpgid"},
    {SYS_getppid, "getppid"},
    {SYS_getpgrp, "getpgrp"},
    {SYS_setsid, "setsid"},
    {SYS_setreuid, "setreuid"},
    {SYS_setregid, "setregid"},
    {SYS_getgroups, "getgroups"},
    {SYS_setgroups, "setgroups"},
    {SYS_setresuid, "setresuid"},
    {SYS_getresuid, "getresuid"},
    {SYS_setresgid, "setresgid"},
    {SYS_getresgid, "getresgid"},
    {SYS_getpgid, "getpgid"},
    {SYS_setfsuid, "setfsuid"},
    {SYS_setfsgid, "setfsgid"},
    {SYS_getsid, "getsid"},
    {SYS_capget, "capget"},
    {SYS_capset, "capset"},
    {SYS_rt_sigpending, "rt_sigpending"},
    {SYS_rt_sigtimedwait, "rt_sigtimedwait"},
    {SYS_rt_sigqueueinfo, "rt_sigqueueinfo"},
    {SYS_rt_sigsuspend, "rt_sigsuspend"},
    {SYS_sigaltstack, "sigaltstack"},
    {SYS_utime, "utime"},
    {SYS_mknod, "mknod"},
    {SYS_uselib, "uselib"},
    {SYS_personality, "personality"},
    {SYS_ustat, "ustat"},
    {SYS_statfs, "statfs"},
    {SYS_fstatfs, "fstatfs"},
    {SYS_sysfs, "sysfs"},
    {SYS_getpriority, "getpriority"},
    {SYS_setpriority, "setpriority"},
    {SYS_sched_setparam, "sched_setparam"},
    {SYS_sched_getparam, "sched_getparam"},
    {SYS_sched_setscheduler, "sched_setscheduler"},
    {SYS_sched_getscheduler, "sched_getscheduler"},
    {SYS_sched_get_priority_max, "sched_get_priority_max"},
    {SYS_sched_get_priority_min, "sched_get_priority_min"},
    {SYS_sched_rr_get_interval, "sched_rr_get_interval"},
    {SYS_mlock, "mlock"},
    {SYS_munlock, "munlock"},
    {SYS_mlockall, "mlockall"},
    {SYS_munlockall, "munlockall"},
    {SYS_vhangup, "vhangup"},
    {SYS_modify_ldt, "modify_ldt"},
    {SYS_pivot_root, "pivot_root"},
    {SYS__sysctl, "_sysctl"},
    {SYS_prctl, "prctl"},
    {SYS_arch_prctl, "arch_prctl"},
    {SYS_adjtimex, "adjtimex"},
    {SYS_setrlimit, "setrlimit"},
    {SYS_chroot, "chroot"},
    {SYS_sync, "sync"},
    {SYS_acct, "acct"},
    {SYS_settimeofday, "settimeofday"},
    {SYS_mount, "mount"},
    {SYS_umount2, "umount2"},
    {SYS_swapon, "swapon"},
    {SYS_swapoff, "swapoff"},
    {SYS_reboot, "reboot"},
    {SYS_sethostname, "sethostname"},
    {SYS_setdomainname, "setdomainname"},
    {SYS_iopl, "iopl"},
    {SYS_ioperm, "ioperm"},
    {SYS_create_module, "create_module"},
    {SYS_init_module, "init_module"},
    {SYS_delete_module, "delete_module"},
    {SYS_get_kernel_syms, "get_kernel_syms"},
    {SYS_query_module, "query_module"},
    {SYS_quotactl, "quotactl"},
    {SYS_nfsservctl, "nfsservctl"},
    {SYS_getpmsg, "getpmsg"},
    {SYS_putpmsg, "putpmsg"},
    {SYS_afs_syscall, "afs_syscall"},
    {SYS_tuxcall, "tuxcall"},
    {SYS_security, "security"},
    {SYS_gettid, "gettid"},
    {SYS_readahead, "readahead"},
    {SYS_setxattr, "setxattr"},
    {SYS_lsetxattr, "lsetxattr"},
    {SYS_fsetxattr, "fsetxattr"},
    {SYS_getxattr, "getxattr"},
    {SYS_lgetxattr, "lgetxattr"},
    {SYS_fgetxattr, "fgetxattr"},
    {SYS_listxattr, "listxattr"},
    {SYS_llistxattr, "llistxattr"},
    {SYS_flistxattr, "flistxattr"},
    {SYS_removexattr, "removexattr"},
    {SYS_lremovexattr, "lremovexattr"},
    {SYS_fremovexattr, "fremovexattr"},
    {SYS_tkill, "tkill"},
    {SYS_time, "time"},
    {SYS_futex, "futex"},
    {SYS_sched_setaffinity, "sched_setaffinity"},
    {SYS_sched_getaffinity, "sched_getaffinity"},
    {SYS_set_thread_area, "set_thread_area"},
    {SYS_io_setup, "io_setup"},
    {SYS_io_destroy, "io_destroy"},
    {SYS_io_getevents, "io_getevents"},
    {SYS_io_submit, "io_submit"},
    {SYS_io_cancel, "io_cancel"},
    {SYS_lookup_dcookie, "lookup_dcookie"},
    {SYS_epoll_create, "epoll_create"},
    {SYS_epoll_ctl_old, "epoll_ctl_old"},
    {SYS_epoll_wait_old, "epoll_wait_old"},
    {SYS_remap_file_pages, "remap_file_pages"},
    {SYS_getdents64, "getdents64"},
    {SYS_set_tid_address, "set_tid_address"},
    {SYS_restart_syscall, "restart_syscall"},
    {SYS_semtimedop, "semtimedop"},
    {SYS_fadvise64, "fadvise64"},
    {SYS_timer_create, "timer_create"},
    {SYS_timer_settime, "timer_settime"},
    {SYS_timer_gettime, "timer_gettime"},
    {SYS_timer_getoverrun, "timer_getoverrun"},
    {SYS_timer_delete, "timer_delete"},
    {SYS_clock_settime, "clock_settime"},
    {SYS_clock_gettime, "clock_gettime"},
    {SYS_clock_getres, "clock_getres"},
    {SYS_clock_nanosleep, "clock_nanosleep"},
    {SYS_exit_group, "exit_group"},
    {SYS_epoll_wait, "epoll_wait"},
    {SYS_epoll_ctl, "epoll_ctl"},
    {SYS_tgkill, "tgkill"},
    {SYS_utimes, "utimes"},
    {SYS_mbind, "mbind"},
    {SYS_set_mempolicy, "set_mempolicy"},
    {SYS_get_mempolicy, "get_mempolicy"},
    {SYS_mq_open, "mq_open"},
    {SYS_mq_unlink, "mq_unlink"},
    {SYS_mq_timedsend, "mq_timedsend"},
    {SYS_mq_timedreceive, "mq_timedreceive"},
    {SYS_mq_notify, "mq_notify"},
    {SYS_mq_getsetattr, "mq_getsetattr"},
    {SYS_kexec_load, "kexec_load"},
    {SYS_waitid, "waitid"},
    {SYS_add_key, "add_key"},
    {SYS_request_key, "request_key"},
    {SYS_keyctl, "keyctl"},
    {SYS_ioprio_set, "ioprio_set"},
    {SYS_ioprio_get, "ioprio_get"},
    {SYS_inotify_init, "inotify_init"},
    {SYS_inotify_add_watch, "inotify_add_watch"},
    {SYS_inotify_rm_watch, "inotify_rm_watch"},
    {SYS_migrate_pages, "migrate_pages"},
    {SYS_openat, "openat"},
    {SYS_mkdirat, "mkdirat"},
    {SYS_mknodat, "mknodat"},
    {SYS_fchownat, "fchownat"},
    {SYS_futimesat, "futimesat"},
    {SYS_newfstatat, "newfstatat"},
    {SYS_unlinkat, "unlinkat"},
    {SYS_renameat, "renameat"},
    {SYS_linkat, "linkat"},
    {SYS_symlinkat, "symlinkat"},
    {SYS_readlinkat, "readlinkat"},
    {SYS_fchmodat, "fchmodat"},
    {SYS_faccessat, "faccessat"},
    {SYS_pselect6, "pselect6"},
    {SYS_ppoll, "ppoll"},
    {SYS_unshare, "unshare"},
    {SYS_set_robust_list, "set_robust_list"},
    {SYS_get_robust_list, "get_robust_list"},
    {SYS_splice, "splice"},
    {SYS_tee, "tee"},
    {SYS_sync_file_range, "sync_file_range"},
    {SYS_vmsplice, "vmsplice"},
    {SYS_move_pages, "move_pages"},
    {SYS_utimensat, "utimensat"},
    {SYS_epoll_pwait, "epoll_pwait"},
    {SYS_signalfd, "signalfd"},
    {SYS_timerfd_create, "timerfd_create"},
    {SYS_eventfd, "eventfd"},
    {SYS_fallocate, "fallocate"},
    {SYS_timerfd_settime, "timerfd_settime"},
    {SYS_timerfd_gettime, "timerfd_gettime"},
    {SYS_accept4, "accept4"},
    {SYS_signalfd4, "signalfd4"},
    {SYS_eventfd2, "eventfd2"},
    {SYS_epoll_create1, "epoll_create1"},
    {SYS_dup3, "dup3"},
    {SYS_pipe2, "pipe2"},
    {SYS_inotify_init1, "inotify_init1"},
    {SYS_preadv, "preadv"},
    {SYS_pwritev, "pwritev"},
    {SYS_rt_tgsigqueueinfo, "rt_tgsigqueueinfo"},
    {SYS_perf_event_open, "perf_event_open"},
    {SYS_recvmmsg, "recvmmsg"},
    {SYS_fanotify_init, "fanotify_init"},
    {SYS_fanotify_mark, "fanotify_mark"},
    {SYS_prlimit64, "prlimit64"},
    {SYS_name_to_handle_at, "name_to_handle_at"},
    {SYS_open_by_handle_at, "open_by_handle_at"},
    {SYS_clock_adjtime, "clock_adjtime"},
    {SYS_syncfs, "syncfs"},
    {SYS_sendmmsg, "sendmmsg"},
    {SYS_setns, "setns"},
    {SYS_getcpu, "getcpu"},
    {SYS_process_vm_readv, "process_vm_readv"},
    {SYS_process_vm_writev, "process_vm_writev"},
    {SYS_kcmp, "kcmp"},
    {SYS_finit_module, "finit_module"},
    {SYS_sched_setattr, "sched_setattr"},
    {SYS_sched_getattr, "sched_getattr"},
    {SYS_renameat2, "renameat2"},
    {SYS_seccomp, "seccomp"},
    {SYS_getrandom, "getrandom"},
    {SYS_memfd_create, "memfd_create"},
    {SYS_bpf, "bpf"},
    {SYS_execveat, "execveat"},
    {SYS_userfaultfd, "userfaultfd"},
    {SYS_membarrier, "membarrier"},
    {SYS_mlock2, "mlock2"},
    {SYS_copy_file_range, "copy_file_range"},
    {SYS_preadv2, "preadv2"},
    {SYS_pwritev2, "pwritev2"},
    {SYS_pkey_mprotect, "pkey_mprotect"},
    {SYS_pkey_alloc, "pkey_alloc"},
    {SYS_pkey_free, "pkey_free"},
    {SYS_statx, "statx"},
    {SYS_io_pgetevents, "io_pgetevents"},
    {SYS_rseq, "rseq"},
    {SYS_pidfd_send_signal, "pidfd_send_signal"},
    {SYS_io_uring_setup, "io_uring_setup"},
    {SYS_io_uring_enter, "io_uring_enter"},
    {SYS_io_uring_register, "io_uring_register"},
    {SYS_open_tree, "open_tree"},
    {SYS_move_mount, "move_mount"},
    {SYS_fsopen, "fsopen"},
    {SYS_fsconfig, "fsconfig"},
    {SYS_fsmount, "fsmount"},
    {SYS_fspick, "fspick"},
    {SYS_pidfd_open, "pidfd_open"},
    {SYS_clone3, "clone3"},
    {SYS_close_range, "close_range"},
    {SYS_openat2, "openat2"},
    {SYS_pidfd_getfd, "pidfd_getfd"},
    {SYS_faccessat2, "faccessat2"},
    {SYS_process_madvise, "process_madvise"},
    {SYS_epoll_pwait2, "epoll_pwait2"},
    {SYS_mount_setattr, "mount_setattr"},
    {SYS_quotactl_fd, "quotactl_fd"},
    {SYS_landlock_create_ruleset, "landlock_create_ruleset"},
    {SYS_landlock_add_rule, "landlock_add_rule"},
    {SYS_landlock_restrict_self, "landlock_restrict_self"},
    {SYS_memfd_secret, "memfd_secret"},
    {SYS_process_mrelease, "process_mrelease"},
    {SYS_futex_waitv, "futex_waitv"},
    {SYS_set_mempolicy_home_node, "set_mempolicy_home_node"}
};

const int syscall_table_size = sizeof(syscall_table) / sizeof(SyscallEntry);

const char *get_syscall_name(int syscall_number) {
    for (int i = 0; i < syscall_table_size; i++) {
        if (syscall_table[i].number == syscall_number) {
            return syscall_table[i].name;
        }
    }
    return "unknown";
}