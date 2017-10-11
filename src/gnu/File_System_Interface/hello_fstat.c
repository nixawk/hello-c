#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

// int fstat (int filedes, struct stat *buf)
// The [fstat] function is like [stat], except that it takes an open file descriptor
// as an argument instead of a file name.

// Like [stat], [fstat] returns 0 on success and -1 on failure.

// struct stat {
//    dev_t     st_dev;         /* ID of device containing file */
//    ino_t     st_ino;         /* inode number */
//    mode_t    st_mode;        /* protection */
//    nlink_t   st_nlink;       /* number of hard links */
//    uid_t     st_uid;         /* user ID of owner */
//    gid_t     st_gid;         /* group ID of owner */
//    dev_t     st_rdev;        /* device ID (if special file) */
//    off_t     st_size;        /* total size, in bytes */
//    blksize_t st_blksize;     /* blocksize for filesystem I/O */
//    blkcnt_t  st_blocks;      /* number of 512B blocks allocated */

//    /* Since Linux 2.6, the kernel supports nanosecond
//       precision for the following timestamp fields.
//       For the details before Linux 2.6, see NOTES. */

//    struct timespec st_atim;  /* time of last access */
//    struct timespec st_mtim;  /* time of last modification */
//    struct timespec st_ctim;  /* time of last status change */

// #define st_atime st_atim.tv_sec      /* Backward compatibility */
// #define st_mtime st_mtim.tv_sec
// #define st_ctime st_ctim.tv_sec
// };


void
fstat_usage(void)
{
    int fd, err;
    struct stat st;

    fd = open("/etc/passwd", O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "open() failed: %s\n", strerror(errno));
        exit(1);
    }

    err = fstat(fd, &st);
    if (err == -1)
    {
        fprintf(stderr, "fstat() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("total size: %lld bytes\n", st.st_size);

    close(fd);
}


int
main(void)
{
    fstat_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Reading-Attributes.html
// https://stackoverflow.com/questions/10634629/what-are-the-usage-differences-between-size-t-and-off-t
// https://elixir.free-electrons.com/linux/latest/source/include/linux/types.h#L20