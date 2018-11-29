#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>

// char * program_invocation_name

// The variable's value is the name that was used to invoke the program
// running in the current process. It is the same as argv[0].
// Note that this is not necessarily a useful file name; often it contains
// no directory names.

// The variable is a GNU extension and is declared in errno.h

/*
$ gcc hello_program_invocation_name.c -o hello_program_invocation_name
$ ~/src/glibc/hello_program_invocation_name
/home/code/src/glibc/hello_program_invocation_name

*/

void show_program_invocation_name(void)
{
	printf("%s\n", program_invocation_name);
}

int main(void)
{
	show_program_invocation_name();
	return 0;
}

/*

error: ‘program_invocation_name’ undeclared (first use in this function)

#define _GNU_SOURCE

*/
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Error-Reporting
