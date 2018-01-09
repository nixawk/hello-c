#include <malloc.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>


// int mallopt (int param, int value)

    // When calling [mallopt], the param argument specifies the parameter
    // to be set, and value the new value to be set.


// M_MMAP_MAX

    // The maximum number of chunks to allocate with [mmap]. Setting this to 
    // zero disables all use of [mmap].
    // The default value of this parameter is 65536.
    // This parameter can also be set for the process at startup by setting the
    // environment variable [MALLOC_MMAP_MAX_] to the desired value.

// M_MMAP_THRESHOLD

    // All chunks larger than this value are allocated outside the normal heap,
    // using the mmap system call. This way it is guaranteed that the memory
    // for these chunks can be returned to the system on free. Note that 
    // requests smaller that this threshold might still be allocated via mmap.

    // If this parameter is not set, the default value is 128KiB and the 
    // threshold is adjusted dynamically to suite the allocation patterns of
    // the program. If the parameter is set, the dynamic adjustment is 
    // disabled and the value is set statically to the input value.

    // The parameter can also be set for the process at startup by setting the
    // environemnt variable [MALLOC_MMAP_THRESHOLD_] to the desired value.

// M_PERTURB

    // If non-zero, memory blocks are filled with values depending on some low
    // order bits of this parameter when they are allocated (except when 
    // allocated by calloc) and freed. This can be used to debug the use of 
    // uninitialized or freed heap memory. Note that this option does not 
    // guarantee that the freed block will have any specific values. It only
    // guarantees that the content the block had before it was freed will be
    // overwritten.

    // The default value of this parameter is 0.

    // This parameter can also be set for the process at startup by setting
    // the environment variable [MALLOC_MMAP_PERTURB_] to the desired value.

// M_TOP_PAD

    // This parameter determines the amount of extra memory to obtain from
    // the system when an arena needs to be extended. If also specifies the
    // number of bytes to retain when shrinking an arena. This provides the
    // necessary hysteresis in heap size such that excessive amounts of system
    // calls can be avoided.

    // The default value of this parameter is 0.

    // This parameter can also be set for the process at startup by setting 
    // the environment variable [MALLOC_TOP_PAD_] to the desired value.

// M_TRIM_THRESHOLD

    // This is the minimum size (in bytes) of the top-most, releasable chunk
    // that will trigger a system call in order to return memory to the system.

    // If this parameter is not set, the default value is set as 128KiB and
    // the threshold is adjusted dynamically to suit the allocation patterns
    // of the program. If the parameter is set, the dynamic adjustment is 
    // disabled and the value is set statically to the provided input.

    // This parameter can also be set for the process at startup by setting
    // the environment variable [MALLOC_TRIM_THRESHOLD_] to the desired value.

// M_ARENA_TEST

    // This parameter sepcifies the number of arenas that can be created before
    // the test on the limit to the number of arenas is conducted. The value is
    // ignored if [M_ARENA_MAX] is set.

    // The default value of this parameter is 2 on 32-bit systems and 8 on
    // 64-bit systems.

    // This parameter can also be set for the process at startup by setting the
    // environment [MALLOC_ARENA_TEST] to the desired value.

// M_ARENA_MAX

    // This parameter sets the number of arenas to use regardless of the number
    // of cores in the system.

    // The default value of this tunable is 0, meaning that the limit on the
    // number of arenas by the number of of CPU cores online. For 32-bit
    // systems the limit is twice the number of cores online and on 64-bit 
    // systems, it is eight times the number of cores online. Note that the
    // default value is not derived from the default value of [M_ARENA_TEST]
    // and is computed independently.

    // This parameter can also be set for the process at startup by setting
    // the environment variable [MALLOC_ARENA_MAX] to the desired value.


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