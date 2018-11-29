#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>

// char * program_invocation_short_name

// The variable is the name that was used to invoke the program running
// in the currnt process, with directory names removed.(That is to say,
// it is the same as program_invocation_name minus everything up to the
// last slash, if any.)

// The variable is GNU extension and is declared in errno.h

/*

$ gcc hello_program_invocation_short_name.c -o hello_program_invocation_short_name
$ ~/src/glibc/hello_program_invocation_short_name 
hello_program_invocation_short_name
*/

void show_program_invocation_short_name(void)
{
	printf("%s\n", program_invocation_short_name);
}

int main(void)
{
	show_program_invocation_short_name();
	return 0;
}

/*

error: ‘program_invocation_name’ undeclared (first use in this function)

#define _GNU_SOURCE

*/
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Error-Reporting
