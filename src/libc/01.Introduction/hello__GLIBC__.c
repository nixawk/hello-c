#include <stdio.h>

/*

There are two means by which an application program can determine the version of
the GNU C library on the system: by testing constants or by calling a library
function. From version 2.0 onward, glibc defines two constants, __GLIBC__ and
__GLIBC_MINOR__, that can be tested at compile time (in #ifdef statements).
However, these constants are of limited use in a program that is compiled on one
system but run on another system with a different glibc. To handle this
possibility, a program can call the gnu_get_glibc_version() function to determine
the version of glibc available at run time.

*/

void glibc_version(void)
{
	printf("__GLIBC__ == %d\n", __GLIBC__);
	printf("__GLIBC_MINOR__ == %d\n", __GLIBC_MINOR__);
}

int main(void)
{
	glibc_version();
	return 0;
}

/*

$ ldd /bin/cat | grep libc
    libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xb75b3000)

$ /lib/i386-linux-gnu/libc.so.6
GNU C Library (Debian GLIBC 2.24-12) stable release version 2.24, by Roland McGrath et al.
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
Compiled by GNU CC version 6.3.0 20170516.
Available extensions:
    crypt add-on version 2.1 by Michael Glad and others
    GNU Libidn by Simon Josefsson
    Native POSIX Threads Library by Ulrich Drepper et al
    BIND-8.2.3-T5B
libc ABIs: UNIQUE IFUNC
For bug reporting instructions, please see:
<http://www.debian.org/Bugs/>.

$ gcc test.c 
$ ./a.out 
__GLIBC__ == 2
__GLIBC_MINOR__ == 24


*/
