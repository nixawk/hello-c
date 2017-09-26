#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// int fchdir (int filedes)

// This function is used to set the process's working directory to directory
// associated with the file descriptor [filedes].

// The normal, successful return value from [fchdir] is 0. A value of -1 is returned
// to indicate an error.

    // EACCES  - Read permission is denied for the directory named by dirname.
    // EBADF   - The [filedes] argument is not a valid file descriptor.
    // ENOTDIR - The file descriptor [filedes] is not associated with a directory.
    // EINTR   - The function call was interrupt by a signal.
    // EIO     - An I/O error occurred.

void getcwd_usage(void);
void fchdir_usage(void);

#define PATH_MAX 4096


void
getcwd_usage(void)
{
    char path[PATH_MAX] = "";
    if (path == getcwd(path, PATH_MAX))
    {
        printf("current directory: %s\n", path);
    }
}


void
fchdir_usage(void)
{
    int fd, ret;

    getcwd_usage();

    /* open a file object */
    fd = open("/tmp/", O_RDONLY, S_IRWXU);
    if (fd == -1)
    {
        fprintf(stderr, "open() failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    ret = fchdir(fd);
    if (ret == -1)
    {
        fprintf(stderr, "fchdir() failed: %s.\n", strerror(errno));
    }

    getcwd_usage();

    close(fd);
}


int
main(void)
{
    fchdir_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Working-Directory.html#Working-Directory
// https://stackoverflow.com/questions/503878/how-to-know-what-the-errno-means