
// int isatty(int filedes)

// This function returns 1 if filedes is a file descriptor associated with an
// open terminal device, and 0 otherwise.

#include <unistd.h>
#include <stdio.h>


void
isatty_usage(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (isatty(i) == 1)
        {
            printf("fd: %d is a terminal device\n", i);
        }
    }
}


int
main(void)
{
    isatty_usage();
    return 0;
}


// $ ./a.out
// fd: 0 is a terminal device
// fd: 1 is a terminal device
// fd: 2 is a terminal device


// https://www.gnu.org/software/libc/manual/html_node/Is-It-a-Terminal.html#Is-It-a-Terminal
// http://man7.org/linux/man-pages/man3/isatty.3.html