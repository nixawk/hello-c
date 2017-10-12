#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// The [fork] function creates a new process.

// If the operation is successful, there are then both parent and child processes
// and both see [fork] return, but with different values: it returns a value of
// 0 in the child process and returns the child's ID in the parent process.

// If process creation failed, [fork] returns a value of -1 in the parent process.
// The following [errno] error conditions are defined for [fork].

int x = 0;

void
vfork_usage(void)
{
    pid_t pid = vfork();

    if (pid < 0)
    {
        printf("vfork() failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        x += 1;
        printf("child  process, x = %d\n", x);
        exit(0);  // Child process must exit, and parent process continues
    }
    else
    {
        x += 1;
        printf("parent process, x = %d\n", x);
    }
}


int
main(void)
{
    vfork_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Creating-a-Process.html