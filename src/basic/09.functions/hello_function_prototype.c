#include <errno.h>
#include <stdio.h>
// #include <string.h>

/*

This program will work fine on x86 architecture, but will crash on x86_64 architecture.

Let us see what was wrong with code. Carefully go through the program,
deliberately I haven’t included prototype of “strerror()” function.
This function returns “pointer to character”, which will print error
message which depends on errno passed to this function. Note that x86
architecture is ILP-32 model, means integer, pointers and long are 32-bit wide,
that’s why program will work correctly on this architecture. But x86_64
is LP-64 model, means long and pointers are 64 bit wide. In C language,
when we don’t provide prototype of function, the compiler assumes that
function returns an integer. In our example, we haven’t included “string.h”
header file (strerror’s prototype is declared in this file),
that’s why compiler assumed that function returns integer.
But its return type is pointer to character. In x86_64, pointers are 64-bit
wide and integers are 32-bits wide, that’s why while returning from function,
the returned address gets truncated (i.e. 32-bit wide address, which is size
of integer on x86_64) which is invalid and when we try to dereference this address,
the result is segmentation fault.

*/
int main(int argc, char *argv[])
{
	FILE *fp;

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));	/* IA86 - works good, IA64 - Segmentation fault (core dumped) */
		return errno;
	}

	printf("file exist\n");

	fclose(fp);

	return 0;
}

// http://www.geeksforgeeks.org/importance-of-function-prototype-in-c/
