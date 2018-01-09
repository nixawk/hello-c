#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// int fcntl (int filedes, int command, …)

// This function performs the operation specified by command on the file descriptor
// filedes. Some commands require additional arguments to be supplied. These additional
// arguments and the return value and error conditions are given in the detailed
// descriptions of the individual commands.
    
    // F_DUPFD
    // F_GETFD
    // F_SETFD
    // F_GETFL
    // F_SETFL
    // F_GETLK
    // F_SETLK
    // F_SETLKW
    // F_OFD_GETLK
    // F_OFD_SETLF
    // F_OFD_SETLKW
    // F_GETOWN
    // F_SETOWN

// This function is a cancellation point in multi-threaded programs. This is a problem 
// if the thread allocates some resources (like memory, file descriptors, semaphores or
// whatever) at the time fcntl is called. If the thread gets canceled these resources 
// stay allocated until the program ends. To avoid this calls to fcntl should be protected
// using cancellation handlers.


void
set_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        fprintf(stderr, "fcntl() failed: %s\n.", strerror(errno));
        exit(1);
    }

    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0)
    {
        fprintf(stderr, "fcntl() failed: %s\n.", strerror(errno));
        exit(1);
    }
}


void
clr_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        fprintf(stderr, "fcntl() failed: %s\n.", strerror(errno));
        exit(1);
    }

    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0)
    {
        fprintf(stderr, "fcntl() failed: %s\n.", strerror(errno));
        exit(1);
    }
}


int
main(void)
{
    set_fl(STDOUT_FILENO, O_SYNC);
    clr_fl(STDOUT_FILENO, O_SYNC);
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Control-Operations.html