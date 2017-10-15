#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// ssize_t write (int filedes, const void *buffer, size_t size)

// The [write] function writes up to [size] bytes from buffer to the file with
// descriptor [filedes]. The data in buffer is not necessarily a character string
// and a null character is output like any other character.

// The return value is the number of bytes actually written. This may be [size],
// but can always be smaller. You program should always call write in a loop,
// iterating until all the data is written.


// ssize_t pwrite (int filedes, const void *buffer, size_t size, off_t offset)
// ssize_t pwrite64 (int filedes, const void *buffer, size_t size, off64_t offset)


void
write_usage(void)
{
    int fd;
    ssize_t n;

    char *path = "/tmp/testfile";
    char *data = "hello, world\n";

    fd = open(path, O_WRONLY | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        fprintf(stderr, "open() failed\n");
    } else {
        n = write(fd, data, strlen(data));
        printf("write [%lu] bytes into [%s]\n", n, path);
        close(fd);
    }
}


int
main(void)
{
    write_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/I_002fO-Primitives.html#I_002fO-Primitives
// http://man7.org/linux/man-pages/man2/open.2.html