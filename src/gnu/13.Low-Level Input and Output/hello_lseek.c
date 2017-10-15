#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


// off_t lseek (int filedes, off_t offset, int whence)

// The [lseek] function is used to change the file position of the file with descriptor [filedes].
// The [whence] argument specifies how the [offset] should be interpreted, in the same way as for
// the [fseek] function, and it must be one of the symbolic constants:

    // SEEK_SET - Specifies that [offset] is a count of characters from the beginning of the file.
    // SEEK_CUR - Specifies that [offset] is a count of characters from the current file position. (may be positive or negative)
    // SEEK_END - Specifies that [offset] is a count of characters from the end of the file.
               // A negative count specifies a position within the current extent of the file;
               // A positive count specifies a position past the curent end.

// The return value from [lseek] is normally the resulting file position, measured in bytes from
// the beginning of the file.

// off64_t lseek64 (int filedes, off64_t offset, int whence)


void
lseek_usage(void)
{
    int fd;
    char data[64] = "";

    fd = open("/etc/passwd", O_RDONLY, S_IRWXU);
    if (fd == -1)
    {
        fprintf(stderr, "open() failed\n");
    } else {
        lseek(fd, -10, SEEK_END);       /* read the last 10 characters */
        read(fd, data, sizeof(data));
        printf("read data: %s\n", data);
        close(fd);
    }
}


int
main(void)
{
    lseek_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/File-Position-Primitive.html#File-Position-Primitive
// https://stackoverflow.com/questions/18688971/c-char-array-initialization
// https://stackoverflow.com/questions/2589749/how-to-initialize-array-to-0-in-c