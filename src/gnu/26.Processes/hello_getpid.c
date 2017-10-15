#include <unistd.h>
#include <stdio.h>

// Process Creation Concepts

// Each process is named by a process ID number. A unique process ID is allocated to each process
// when it is created. The [lifetime] of a process ends when its termination is reported to its
// parent process; at that time, all of the process resources, including its process ID, are freed.

// Processes are created with the [fork] system call (so the operation of creating a new process
// is sometimes called forking a process). The child process created by [fork] is a copy of the
// original parent process, except that it has its own process ID.

// After forking a child process, both the parent and child processes continue to execute normally.
// If you want your program to wait for a child process to finish executing before continuing, you
// must do this explicitly after the fork operation, by calling [wait] and [waitpid]. These functions
// give you limited information about why the child terminated, ex: its exit status code.

// pid_t getpid (void)

// The [pid_t] data type is a signed integer type which is a capable of representing a process ID.
// In the GNU C Library, this is an [int].
// The [getpid] function returns the process ID of the current process.

// pid_t getppid (void)

// The [getpid] function returns the process ID of the parent of the current process.


void
getpid_usage(void)
{
    pid_t pid = getpid();    /* current process id */
    pid_t ppid = getppid();  /* parent  process id */

    printf("current process id: %d\n", pid);
    printf("parent  process id: %d\n", ppid);
}


int
main(void)
{
    getpid_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Process-Creation-Concepts.html#Process-Creation-Concepts
// https://www.gnu.org/software/libc/manual/html_node/Process-Identification.html#Process-Identification