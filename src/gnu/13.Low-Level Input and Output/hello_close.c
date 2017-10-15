#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// int close (int filedes)

// The function [close] closes the file descriptor filedes. Closing
// a file has the following consequences:

    // The file descriptor is deallocated.
    // Any record locks owned by the process on the file are unlocked.
    // When all file descriptors associated with a pipe or FIFO have been closed, any unread data is discarded.

// This function is a cancellation point in multi-threaded programs. 
// This is a problem if the thread allocates some resources (like memory, 
// file descriptors, semaphores or whatever) at the time close is called. 
// If the thread gets canceled these resources stay allocated until the program ends. 
// To avoid this, calls to close should be protected using cancellation handlers.

// The normal return value from close is 0; a value of -1 is returned in case of failure.
// The following errno error conditions are defined for this function:

    // EBADF
    // EINTR
    // ENOSPC
    // EIO
    // EDQUOT

void
close_usage(void)
{
    int fd, cret;

    fd = creat("/tmp/testfile", S_IRWXU);
    if (fd != -1)
    {
        cret = close(fd);
        printf("close status: %d\n", cret);
    }
}


int
main(void)
{
    close_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Opening-and-Closing-Files.html#Opening-and-Closing-Files