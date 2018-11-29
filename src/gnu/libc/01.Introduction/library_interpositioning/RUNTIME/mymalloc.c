#ifdef RUNTIME

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* malloc wrapper function */
void *malloc(size_t size)
{
	void *(*mallocp) (size_t size);
	void *ptr;

	mallocp = dlsym(RTLD_NEXT, "malloc");	/* Get address of libc malloc */
	if (mallocp == NULL) {
		// fprintf(stderr, "%s:%d:%s", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}

	ptr = mallocp(size);
	// printf("malloc(%zu) = %p\n", size, ptr);  // Segmentation fault
	return ptr;
}

/* free wrapper function */
void free(void *ptr)
{
	void (*freecp) (void *) = NULL;

	if (!ptr)
		return;

	freecp = dlsym(RTLD_NEXT, "free");	/* Get address of libc free */
	if (freecp == NULL) {
		// fprintf(stderr, "%s:%d:%s", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}

	freecp(ptr);
	// printf("free(%p)\n", ptr);
}

#endif

/*

$ gdb -q --nh ./hello_intpos 
Reading symbols from ./hello_intpos...(no debugging symbols found)...done.
(gdb) set environment LD_PRELOAD=./mymalloc.so
(gdb) run 
Starting program: /tmp/intpos/RUNTIME/hello_intpos 

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff795448f in do_sym (handle=0xffffffffffffffff, name=0x7ffff7bd582d "malloc", who=0x7ffff7bd576f <malloc+31>, vers=vers@entry=0x0, flags=flags@entry=2)
    at dl-sym.c:89
89  dl-sym.c: No such file or directory.

(gdb) bt
#0  0x00007ffff795448f in do_sym (handle=0xffffffffffffffff, name=0x7ffff7bd582d "malloc", who=0x7ffff7bd576f <malloc+31>, vers=vers@entry=0x0, flags=flags@entry=2)
    at dl-sym.c:89
#1  0x00007ffff79549ad in _dl_sym (handle=<optimized out>, name=<optimized out>, who=<optimized out>) at dl-sym.c:273
#2  0x00007ffff760b014 in dlsym_doit (a=a@entry=0x7fffff7ff1b0) at dlsym.c:50
#3  0x00007ffff7de7874 in _dl_catch_error (objname=0x7ffff780d0d0 <last_result+16>, errstring=0x7ffff780d0d8 <last_result+24>, mallocedp=0x7ffff780d0c8 <last_result+8>, 
    operate=0x7ffff760b000 <dlsym_doit>, args=0x7fffff7ff1b0) at dl-error.c:187
#4  0x00007ffff760b581 in _dlerror_run (operate=operate@entry=0x7ffff760b000 <dlsym_doit>, args=args@entry=0x7fffff7ff1b0) at dlerror.c:163
#5  0x00007ffff760b068 in __dlsym (handle=<optimized out>, name=<optimized out>) at dlsym.c:70
#6  0x00007ffff7bd576f in malloc () from ./mymalloc.so
#7  0x00007ffff787c342 in __GI__IO_file_doallocate (fp=0x7ffff7bd0600 <_IO_2_1_stdout_>) at filedoalloc.c:101
#8  0x00007ffff788b816 in __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7bd0600 <_IO_2_1_stdout_>) at genops.c:398
#9  0x00007ffff788a9e8 in _IO_new_file_overflow (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, ch=-1) at fileops.c:828
#10 0x00007ffff78890dd in _IO_new_file_xsputn (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, data=<optimized out>, n=7) at fileops.c:1339
#11 0x00007ffff785b996 in _IO_vfprintf_internal (s=0x7ffff7bd0600 <_IO_2_1_stdout_>, format=0x7ffff7bd5834 "malloc(%zu) = %p\n", ap=ap@entry=0x7fffff7ff8c8)
    at vfprintf.c:1320
#12 0x00007ffff78645a9 in __printf (format=<optimized out>) at printf.c:33
#13 0x00007ffff7bd57b1 in malloc () from ./mymalloc.so
#14 0x00007ffff787c342 in __GI__IO_file_doallocate (fp=0x7ffff7bd0600 <_IO_2_1_stdout_>) at filedoalloc.c:101
#15 0x00007ffff788b816 in __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7bd0600 <_IO_2_1_stdout_>) at genops.c:398
#16 0x00007ffff788a9e8 in _IO_new_file_overflow (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, ch=-1) at fileops.c:828
#17 0x00007ffff78890dd in _IO_new_file_xsputn (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, data=<optimized out>, n=7) at fileops.c:1339
#18 0x00007ffff785b996 in _IO_vfprintf_internal (s=0x7ffff7bd0600 <_IO_2_1_stdout_>, format=0x7ffff7bd5834 "malloc(%zu) = %p\n", ap=ap@entry=0x7fffff800078)
    at vfprintf.c:1320
#19 0x00007ffff78645a9 in __printf (format=<optimized out>) at printf.c:33
#20 0x00007ffff7bd57b1 in malloc () from ./mymalloc.so
#21 0x00007ffff787c342 in __GI__IO_file_doallocate (fp=0x7ffff7bd0600 <_IO_2_1_stdout_>) at filedoalloc.c:101
#22 0x00007ffff788b816 in __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7bd0600 <_IO_2_1_stdout_>) at genops.c:398
#23 0x00007ffff788a9e8 in _IO_new_file_overflow (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, ch=-1) at fileops.c:828
#24 0x00007ffff78890dd in _IO_new_file_xsputn (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, data=<optimized out>, n=7) at fileops.c:1339
#25 0x00007ffff785b996 in _IO_vfprintf_internal (s=0x7ffff7bd0600 <_IO_2_1_stdout_>, format=0x7ffff7bd5834 "malloc(%zu) = %p\n", ap=ap@entry=0x7fffff800828)
    at vfprintf.c:1320
#26 0x00007ffff78645a9 in __printf (format=<optimized out>) at printf.c:33
#27 0x00007ffff7bd57b1 in malloc () from ./mymalloc.so
#28 0x00007ffff787c342 in __GI__IO_file_doallocate (fp=0x7ffff7bd0600 <_IO_2_1_stdout_>) at filedoalloc.c:101
#29 0x00007ffff788b816 in __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7bd0600 <_IO_2_1_stdout_>) at genops.c:398
#30 0x00007ffff788a9e8 in _IO_new_file_overflow (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, ch=-1) at fileops.c:828
#31 0x00007ffff78890dd in _IO_new_file_xsputn (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, data=<optimized out>, n=7) at fileops.c:1339
#32 0x00007ffff785b996 in _IO_vfprintf_internal (s=0x7ffff7bd0600 <_IO_2_1_stdout_>, format=0x7ffff7bd5834 "malloc(%zu) = %p\n", ap=ap@entry=0x7fffff800fd8)
    at vfprintf.c:1320
#33 0x00007ffff78645a9 in __printf (format=<optimized out>) at printf.c:33
#34 0x00007ffff7bd57b1 in malloc () from ./mymalloc.so
#35 0x00007ffff787c342 in __GI__IO_file_doallocate (fp=0x7ffff7bd0600 <_IO_2_1_stdout_>) at filedoalloc.c:101
#36 0x00007ffff788b816 in __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7bd0600 <_IO_2_1_stdout_>) at genops.c:398
#37 0x00007ffff788a9e8 in _IO_new_file_overflow (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, ch=-1) at fileops.c:828
#38 0x00007ffff78890dd in _IO_new_file_xsputn (f=0x7ffff7bd0600 <_IO_2_1_stdout_>, data=<optimized out>, n=7) at fileops.c:1339
#39 0x00007ffff785b996 in _IO_vfprintf_internal (s=0x7ffff7bd0600 <_IO_2_1_stdout_>, format=0x7ffff7bd5834 "malloc(%zu) = %p\n", ap=ap@entry=0x7fffff801788)
    at vfprintf.c:1320
#40 0x00007ffff78645a9 in __printf (format=<optimized out>) at printf.c:33
#41 0x00007ffff7bd57b1 in malloc () from ./mymalloc.so
#42 0x00007ffff787c342 in __GI__IO_file_doallocate (fp=0x7ffff7bd0600 <_IO_2_1_stdout_>) at filedoalloc.c:101
#43 0x00007ffff788b816 in __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7bd0600 <_IO_2_1_stdout_>) at genops.c:398
---Type <return> to continue, or q <return> to quit---

*/

// http://blog.csdn.net/imred/article/details/77418323
// http://www.nongnu.org/failmalloc/
