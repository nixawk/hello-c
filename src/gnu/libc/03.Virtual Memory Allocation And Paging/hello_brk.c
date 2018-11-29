#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>

    // int brk (void *addr)

// [brk] sets the high end of the calling process's data segment to addr.
// The address of the end of a segment is defined to be the address of the
// last byte in the segment plus + 1.

// The function has no effect if addr is lower than the low end of the data segment.
// (This is considered success, by the way.)

// The function fails if it would cause the data segment to overlap another segment
// to overlap another segment or exceed the process' data storage limit.

// The function is named for a common historical case where data storage and the
// stack are in the same segment. Data storage allocation grows upward from the
// bottom of the segment while the stack grows downward toward it from the top
// of the segment and the curtain between them is called the break.

// The return value is zero on success. On failure, 
//the return value is -1 and errno is set accordingly. 

    // memory layout
    // stack layout

#define SIZE    512

void brk_usage(void)
{
	void *ptr;

	ptr = malloc(SIZE);
	if (ptr == NULL) {
		error(EXIT_FAILURE, errno, "malloc() failed");
	}

	if (brk(ptr + 0x400) != 0) {
		error(EXIT_FAILURE, errno, "brk() failed");
	}

	free(ptr);
}

int main(void)
{
	brk_usage();
	return 0;
}

/*
$ ./hello_brk 
./hello_brk: brk() failed: Cannot allocate memory

$ strace ./hello_brk 
execve("./hello_brk", ["./hello_brk"], [* 60 vars *]) = 0
brk(NULL)                               = 0x5598f93fb000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fa88a5b4000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=118087, ...}) = 0
mmap(NULL, 118087, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fa88a597000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\20\5\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1856752, ...}) = 0
mmap(NULL, 3959200, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fa889fcb000
mprotect(0x7fa88a189000, 2093056, PROT_NONE) = 0
mmap(0x7fa88a388000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7fa88a388000
mmap(0x7fa88a38e000, 14752, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fa88a38e000
close(3)                                = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fa88a595000
arch_prctl(ARCH_SET_FS, 0x7fa88a595700) = 0
mprotect(0x7fa88a388000, 16384, PROT_READ) = 0
mprotect(0x5598f79f8000, 4096, PROT_READ) = 0
mprotect(0x7fa88a5b7000, 4096, PROT_READ) = 0
munmap(0x7fa88a597000, 118087)          = 0
brk(NULL)                               = 0x5598f93fb000
brk(0x5598f941c000)                     = 0x5598f941c000
brk(0x5598f93fb410)                     = 0x5598f93fb410
exit_group(0)                           = ?

*/

// https://www.gnu.org/software/libc/manual/html_node/Resizing-the-Data-Segment.html#Resizing-the-Data-Segment
