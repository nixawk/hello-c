#include <gnu/libc-version.h>
#include <stdio.h>

void glibc_ver(void)
{
	printf("gnu_get_libc_version() = %s\n", gnu_get_libc_version());
}

int main(void)
{
	glibc_ver();
	return 0;
}

/*

$ gcc test.c 
$ ./a.out 
gnu_get_libc_version() = 2.24

*/
