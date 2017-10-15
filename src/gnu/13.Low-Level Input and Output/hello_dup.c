#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int dup (int old)

// The [dup()] function copies descriptor [old] to the first available
// descriptor number (the first number not currently open). It is equivalent
// to:

    // fcntl(old, F_DUPFD, 0) 


// int dup2(int oldfd, int newfd);

// This function copies the descriptor [old] to descriptor number [new].
// If [old] is an invalid descriptor, then [dup2] does nothing; it does not close [new].
// Otherwise, the new duplicate of [old] replaces any previous meaning of descriptor [new],
// as if [new] were closed first.

// If [old] and [new] are different numbers, and [old] is a valid descriptor number,
// then [dup2] is equivalent to:

    // close(new);
    // fcntl(old, F_DUPFD, 0);


void
dup_usage(void)
{
    int oldfd, newfd;
    char buf[] = "hello,world";

    oldfd = creat("/tmp/filename", S_IRWXU);
    if (oldfd != -1)
    {
        printf("old file descriptor: %d\n", oldfd);

        newfd = dup(oldfd);  // Be equivalent to ` dup2(oldfd, newfd); `
        close(oldfd);

        printf("new file descriptor: %d\n", newfd);

        write(newfd, buf, strlen(buf));
        close(newfd);
    }
}


void
dup2_usage(void)
{
    int oldfd, newfd;
    char buf[] = "hello,world";

    oldfd = creat("/tmp/filename2", S_IRWXU);
    if (oldfd != -1)
    {
        printf("old file descriptor: %d\n", oldfd);

        // 1. if [oldfd] is opened,
            // 1.1 if [oldfd == newfd], return [oldfd],
            // 1.2 if [oldfd != newfd], close [oldfd], and return [newfd], 
        // 2. if [oldfd] is closed, [FD_CLOEXEC] flag is cleared.

        dup2(oldfd, newfd);

        printf("new file descriptor: %d\n", newfd);

        write(newfd, buf, strlen(buf));
        close(newfd);
    }
}


int
main(void)
{
    dup_usage();
    dup2_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Duplicating-Descriptors.html#Duplicating-Descriptors
// http://man7.org/linux/man-pages/man2/dup.2.html