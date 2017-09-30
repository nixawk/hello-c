#include <unistd.h>
#include <stdio.h>

// pid_t fork (void)

// The [fork] function is the primitive for creating a process.
// If the operation is successful, there are then both parent and child processes
// and both see [fork] return, but with different values: 
// it returns a value of 0 in the child process and 
// returns the child's process ID in the parent process.

// If process creation failed, fork returns a value of -1 in the parent process.

void
fork_usage(void)
{
    pid_t pid = fork();

    if (pid == (pid_t) 0)  // child process
    {
        printf("In child process\n");
    }
    else if (pid > (pid_t) 0)
    {
        printf("In parent process, child process id: %d\n", pid);
    }
    else
    {
        fprintf(stderr, "fork() failed.\n");
    }

    // output:
    // In parent process, child process id: 53401
    // In child process
}


int
main(void)
{
    fork_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Creating-a-Process.html#Creating-a-Process