#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int fsync (int fildes)

// The [fsync] function can be used to make sure all data associated with
// the open file [fildes] is written to the device associated with the
// descriptor. The function call does not return unless all actions have
// finished.

// This function is a cancellation point in multi-threaded programs. This
// is a problem if the thread allocates some resources (like memory, file
// descriptors, semaphores, or whatever) at the time [fsync] is called. If
// the thread gets canceled these resources stay allocated until the program
// ends. To avoid this, calls to [fsync] should be protected using cancellation
// handlers.

// The return value of the function is zero if no error occurred. Otherwise
// it is -1 and the global variable [errno] is set to the following values:

    // EBADF  : The [descriptor] fildes is not valid.
    // EINVAL : No synchronization is possible since the system does not implement this.


void
fsync_usage(void)
{
    int fd;
    int i;
    char str[] = "hello, world\n";

    fd = creat("/tmp/filename", S_IRWXU);
    if (fd != -1)
    {
        for (i = 0; i < 10; i++)
        {
            write(fd, str, strlen(str));
            fsync(fd);
            printf("write %d times\n", i + 1);
        }
        close(fd);
    }
}


int
main(void)
{
    fsync_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Synchronizing-I_002fO.html