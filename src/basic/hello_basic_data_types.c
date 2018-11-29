#include <stdio.h>

int main(void)
{
	/*

	   char   - character - a single byte
	   int    - integer
	   short  - short integer
	   long   - long integer
	   float  - single-precision floating point
	   double - double-precision floating point

	   The size of these objects are also machine-dependent.
	   There are also arrays, structures and unions of these basic types,
	   pointers to them, and functions that return them.

	 */

	/*
	   printf is not part of the C language; there is not input
	   or output defined in C itself.

	   printf is just a useful function from the standard library
	   of functions that are normally accessible to C programs.
	   The behavior of printf is defined in the ANSI standard.

	 */

	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(short) = %lu\n", sizeof(short));
	printf("sizeof(long) = %lu\n", sizeof(long));
	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));

	return 0;
}

/*

root@lab:/tmp# ./a.out 
sizeof(char) = 1
sizeof(int) = 4
sizeof(short) = 2
sizeof(long) = 4
sizeof(float) = 4
sizeof(double) = 8

root@lab:/tmp# uname -r
4.6.0-kali1-686-pae

*/
