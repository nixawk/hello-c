#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

void
file_hole(const char *filename)
{
    int fd;             /* file descriptor */
    int wc;             /* count of write data */
    off_t offset;       /* file offset */
    char buf[BUF_SIZE]; /* garbage buffer */

    /* open file */

    if ((fd = open(filename, O_RDWR, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    /* file hole with lseek */

    if ((offset = lseek(fd, BUF_SIZE, SEEK_END)) == -1)
    {
        perror("lseek()");
        exit(EXIT_FAILURE);
    }

    if ((wc = write(fd, buf, BUF_SIZE)) == -1)
    {
        perror("write()");
        exit(EXIT_FAILURE);
    }

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
    if ((argc != 2) || (strcmp("--help", argv[1]) == 0))
    {
        printf("[*] Usage: %s <filename>\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    file_hole(argv[1]);
    exit(EXIT_SUCCESS);
}

/*

$ ll 1.txt 
-rw-r--r-- 1 root root 4 Jan  9 03:06 1.txt

$ ./a.out 1.txt 
$ ll 1.txt 
-rw-r--r-- 1 root root 2052 Jan  9 03:08 1.txt

*/

// https://stackoverflow.com/questions/5315428/how-to-create-a-file-with-file-holes