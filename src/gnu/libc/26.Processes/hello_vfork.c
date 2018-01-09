#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// The [fork] function creates a new process.

// If the operation is successful, there are then both parent and child
// processes and both see [fork] return, but with different values: it
// returns a value of 0 in the child process and returns the child's ID
// in the parent process.

// If process creation failed, [fork] returns a value of -1 in the parent
// process. The following [errno] error conditions are defined for [fork].

// fork VS vfork

void
vfork_usage(void)
{
    int istack = 222;

    switch (vfork())
    {
        case -1:
            perror("vfork");
            exit(EXIT_FAILURE);

        case 0:        /* Child executes first, in parent's memory space */
            sleep(3);  /* Even if we sleep for a while, parent still is not scheduled. */
            write(STDOUT_FILENO, "Child executing\n", 16);
            istack *= 3;
            exit(EXIT_SUCCESS);

        default:
            write(STDOUT_FILENO, "Parent executing\n", 17);
            printf("istack=%d\n", istack);
            exit(EXIT_SUCCESS);
    }
}


int
main(void)
{
    vfork_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Creating-a-Process.html