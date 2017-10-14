#include <malloc.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>

    // int mallopt (int param, int value)

// When calling [mallopt], the param argument specifies the parameter to be set,
// and value the new value to be set.

    // M_MMAP_MAX

    // The maximum number of chunks to allocate with [mmap]. Setting this to zero
    // disables all use of [mmap].
    // The default value of this parameter is 65536.
    // This parameter can also be set for the process at startup by setting the
    // environment variable [MALLOC_MMAP_MAX_] to the desired value.

    // M_MMAP_THRESHOLD
    // M_PERTURB
    // M_TOP_PAD
    // M_TRIM_THRESHOLD
    // M_ARENA_TEST
    // M_ARENA_MAX

void
mmap_usage(void)
{
    void *map;
    int fd, err;
    struct stat stbuf;

    fd = open("/etc/passwd", O_RDONLY);
    if (fd < 0)
    {
        error(EXIT_FAILURE, errno, "open() failed");
    }

    err = fstat(fd, &stbuf);
    if (err != 0)
    {
        error(EXIT_FAILURE, errno, "fstat() failed");
    }

    map = mmap(NULL, stbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mmap == MAP_FAILED)
    {
        error(EXIT_FAILURE, errno, "mmap() failed");
    }

    munmap(map, stbuf.st_size);
    close(fd);
}


void
mallopt_usage(void)
{
    mallopt(M_MMAP_MAX, 0);   // disable all use of mmap
}


int
main(void)
{
    mallopt_usage();
    mmap_usage();
    return 0;
}


/*

$ strace ./hello_mallopt 
execve("./hello_mallopt", ["./hello_mallopt"], [* 60 vars *]) = 0
brk(NULL)                               = 0x5573ccf6b000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fa4363a0000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=118087, ...}) = 0
mmap(NULL, 118087, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fa436383000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\20\5\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1856752, ...}) = 0
mmap(NULL, 3959200, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fa435db7000
mprotect(0x7fa435f75000, 2093056, PROT_NONE) = 0
mmap(0x7fa436174000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7fa436174000
mmap(0x7fa43617a000, 14752, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fa43617a000
close(3)                                = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fa436381000
arch_prctl(ARCH_SET_FS, 0x7fa436381700) = 0
mprotect(0x7fa436174000, 16384, PROT_READ) = 0
mprotect(0x5573cc099000, 4096, PROT_READ) = 0
mprotect(0x7fa4363a3000, 4096, PROT_READ) = 0
munmap(0x7fa436383000, 118087)          = 0
open("/etc/passwd", O_RDONLY)           = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=2550, ...}) = 0
mmap(NULL, 2550, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fa43639f000
munmap(0x7fa43639f000, 2550)            = 0
close(3)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++


*/

// https://www.gnu.org/software/libc/manual/html_node/Malloc-Tunable-Parameters.html#Malloc-Tunable-Parameters