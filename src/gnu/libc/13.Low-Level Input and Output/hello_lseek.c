#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif


void
get_openfile_offset(const char *filename)
{
    int fd;               /* file descriptor */
    int rc;               /* count of read */
    char buf[BUF_SIZE];   /* buffer for read */
    off_t offset;         /* offset of the open file */

    /* open file */

    if ((fd = open(filename, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH)) == -1)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    /* read file, and move file cursor position */

    if ((rc = read(fd, buf, BUF_SIZE)) == -1)
    {
        perror("read()");
        exit(EXIT_FAILURE);
    }

    /* get file cursor position */
    if ((offset = lseek(fd, (off_t) 0, SEEK_CUR)) == -1)
    {
        perror("lseek()");
        exit(EXIT_FAILURE);
    }

    printf("file cursor position: %ld\n", (long) offset);

    /* close file, and avoid memory leak */

    if (close(fd) == -1)
    {
        perror("close()");
        exit(EXIT_FAILURE);
    }
}


int
main(int argc, char *argv[])
{
    if ((argc != 2) || (strcmp("--help", argv[1])) == 0)
    {
        printf("[*] %s <filename>", argv[0]);
        exit(EXIT_FAILURE);
    }

    get_openfile_offset(argv[1]);

    exit(EXIT_SUCCESS);
}

/*

$ gcc -DBUF_SIZE=2 hello_lseek.c
$ ./a.out 1.txt
file cursor position: 2

$ gcc -DBUF_SIZE=3 hello_lseek.c
$ ./a.out 1.txt
file cursor position: 3

*/


// https://www.gnu.org/software/libc/manual/html_node/File-Position-Primitive.html#File-Position-Primitive
// https://stackoverflow.com/questions/18688971/c-char-array-initialization
// https://stackoverflow.com/questions/2589749/how-to-initialize-array-to-0-in-c