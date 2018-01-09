#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUF_SIZE /* Allow "cc -D" to override definition */
#define BUF_SIZE 4096
#endif

void
copyfile(const char *src, const char *dst)
{
    char buf[BUF_SIZE];

    int sfd, dfd;         /* file descriptor */
    int sflags, dflags;   /* file flags */
    mode_t smode, dmode;  /* file mode */

    int rc, wc;           /* count for read/write */

    /* read data from src file */

    sflags = O_RDONLY;
    smode = S_IRUSR | S_IRGRP | S_IROTH;

    sfd = open(src, sflags, smode);
    if (sfd == -1)
    {
        perror("open() src file");
        exit(EXIT_FAILURE);
    }

    /* write data into dst file */

    dflags = O_RDWR | O_TRUNC | O_CREAT;
    dmode = S_IRUSR | S_IRGRP | S_IROTH;

    dfd = open(dst, dflags, dmode);
    if (dfd == -1)
    {
        perror("open() dst file");
        exit(EXIT_FAILURE);
    }

    while ((rc = read(sfd, buf, BUF_SIZE)) > 0)
    {
        wc = (rc < BUF_SIZE) ? rc : BUF_SIZE;
        if ((wc = write(dfd, buf, wc)) == -1)
        {
            perror("write() dst file");
            exit(EXIT_FAILURE);
        }
    }

    /* close file descriptor, and avoid memory leak */

    if (close(sfd) == -1)
    {
        perror("close() src file");
        exit(EXIT_FAILURE);
    }

    if (close(dfd) == -1)
    {
        perror("close() dst file");
        exit(EXIT_FAILURE);
    }
}

int
main(int argc, const char *argv[])
{
    if ((argc != 3) || (strcmp("--help", argv[1]) == 0))
    {
        printf("[*] %s <src-file> <dst-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copyfile(argv[1], argv[2]);
    exit(EXIT_SUCCESS);
}


/*

$ gcc -DBUF_SIZE=1 hello_copyfile.c

$ ./a.out 1.txt /dev/tty
123

$ strace ./a.out 1.txt 2.txt
execve("./a.out", ["./a.out", "1.txt", "2.txt"], [/ * 45 vars * /]) = 0
brk(NULL)                               = 0x814da000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap2(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb7742000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat64(3, {st_mode=S_IFREG|0644, st_size=128249, ...}) = 0
mmap2(NULL, 128249, PROT_READ, MAP_PRIVATE, 3, 0) = 0xb7722000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/i386-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\1\1\1\3\0\0\0\0\0\0\0\0\3\0\3\0\1\0\0\0\360\203\1\0004\0\0\0"..., 512) = 512
fstat64(3, {st_mode=S_IFREG|0755, st_size=1787812, ...}) = 0
mmap2(NULL, 1796636, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0xb756b000
mmap2(0xb771c000, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0xb771c000
mmap2(0xb771f000, 10780, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0xb771f000
close(3)                                = 0
set_thread_area({entry_number:-1, base_addr:0xb77447c0, limit:1048575, seg_32bit:1, contents:0, read_exec_only:0, limit_in_pages:1, seg_not_present:0, useable:1}) = 0 (entry_number:6)
mprotect(0xb771c000, 8192, PROT_READ)   = 0
mprotect(0x800b5000, 4096, PROT_READ)   = 0
mprotect(0xb776d000, 4096, PROT_READ)   = 0
munmap(0xb7722000, 128249)              = 0
open("1.txt", O_RDONLY)                 = 3
open("2.txt", O_RDWR|O_CREAT|O_TRUNC, 0444) = 4
read(3, "1", 1)                         = 1
write(4, "1", 1)                        = 1
read(3, "2", 1)                         = 1
write(4, "2", 1)                        = 1
read(3, "3", 1)                         = 1
write(4, "3", 1)                        = 1
read(3, "\n", 1)                        = 1
write(4, "\n", 1)                       = 1
read(3, "", 1)                          = 0
close(3)                                = 0
close(4)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++


*/