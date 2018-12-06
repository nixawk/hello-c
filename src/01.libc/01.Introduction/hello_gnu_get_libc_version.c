#include <gnu/libc-version.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("GNU libc version: %s\n", gnu_get_libc_version());
	printf("GNU libc release: %s\n", gnu_get_libc_release());
	exit(EXIT_SUCCESS);
}

/*

$ ./a.out 
GNU libc version: 2.27
GNU libc release: stable

*/
