#include <unistd.h>
#include <stdio.h>

// char * ttyname (int filedes)


// If the file descriptor filedes is associated with a terminal device,
// the ttyname function returns a pointer to a statically-allocated,
// null-terminated string containing the file name of the terminal file.
// The value is a null pointer if the file descriptor isn't associated
// with a terminal, or the file name cannot be determined.


void
show_ttyname(void)
{
    int fds[] = {0, 1, 2};
    int i;

    for (i = 0; i < sizeof(fds) / sizeof(*fds); i++)
    {
        printf("fd: %d, ttyname: %s\n", fds[i], ttyname(fds[i]));
    }
}


int
main(void)
{
    show_ttyname();
    return 0;
}


// $ ./a.out
// fd: 0, ttyname: /dev/ttys000
// fd: 1, ttyname: /dev/ttys000
// fd: 2, ttyname: /dev/ttys000


// https://www.gnu.org/software/libc/manual/html_node/Is-It-a-Terminal.html#Is-It-a-Terminal