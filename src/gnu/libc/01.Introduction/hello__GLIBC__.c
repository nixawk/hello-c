#include <stdio.h>


void
glibc(void)
{
    printf("__GLIBC__ == %d\n", __GLIBC__);
    printf("__GLIBC_MINOR__ == %d\n", __GLIBC_MINOR__);
}


int
main(void)
{
    glibc();
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