#include <stdio.h>

int main(void)
{
	/*

	   printf never supplies a newline automatically

	   \n represents only a single character. An escape sequence
	   like \n provides a general and extension mechanism for
	   represneting hard-to-type or invisible characters.

	   \n for newline
	   \t for tab
	   \b for backspace
	   \" for double quote
	   \\ for the backslash itself

	 */

	printf("hello, world\n");

	return 0;
}

/*

$ gcc helloc.c
helloc.c: In function ‘main’:
helloc.c:7:12: warning: unknown escape sequence: '\c'
     printf("hello, world\c");
            ^~~~~~~~~~~~~~~~

*/
