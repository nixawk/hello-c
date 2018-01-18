#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

void
mmap_cat(char *filename)
{
    int fd;               /* file descriptor */
    struct stat statbuf;  /* file stat */
    void *maddr;          /* mmap addr */

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &statbuf) == -1)
    {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    maddr = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (maddr == MAP_FAILED)  /* MAP_FAILED == (void *) -1 */
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    printf("mmap addr: %p\n\n", maddr);

    if (write(STDOUT_FILENO, maddr, statbuf.st_size) != statbuf.st_size)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // if (msync(maddr, statbuf.st_size, MS_ASYNC) == -1)
    // {
    //     perror("msync");
    //     exit(EXIT_FAILURE);
    // }

    if (munmap(maddr, statbuf.st_size) == -1)
    {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

int
main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("[*] Usage: %s FILE\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    mmap_cat(argv[1]);
    exit(EXIT_SUCCESS);
}

// https://www.gnu.org/software/libc/manual/html_node/Memory_002dmapped-I_002fO.html
// https://stackoverflow.com/questions/23169241/what-are-the-advantages-of-using-fstat-vs-stat
// http://man7.org/linux/man-pages/man2/mmap.2.html
// http://man7.org/linux/man-pages/man2/msync.2.html