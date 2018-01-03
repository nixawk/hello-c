#include <unistd.h>
#include <stdlib.h>
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
    pid_t childpid;

    switch (childpid = fork())
    {
        case -1:  /* fork() failed */
            perror("fork()");
            exit(EXIT_FAILURE);

        case 0:   /* child process */
            printf("Child's  processID: %d\n", getpid());
            printf("Parent's processID: %d\n", getppid());
            break;

        default:  /* parent process*/
            sleep(3);  // Give child a chance to execute
            printf("default processID: %d\n", getpid());
            break;
    }

    exit(EXIT_SUCCESS);
}


int
main(void)
{
    fork_usage();
    return 0;
}

/*

$ ./a.out                                                                                                                                                git:master*
Child's  processID: 23619
Parent's processID: 23618
default processID: 23618

*/

// https://www.gnu.org/software/libc/manual/html_node/Creating-a-Process.html#Creating-a-Process
// http://man7.org/linux/man-pages/man2/fork.2.html