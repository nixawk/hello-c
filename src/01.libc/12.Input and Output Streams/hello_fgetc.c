#include <stdio.h>

// Function: int fgetc (FILE *stream)
// Function: int getc (FILE *stream)

// This is just like fgetc, except that it is permissible (and typical) for it
// to be implemented as a macro that evaluates the stream argument more than
// once. getc is often optimized, so it is usually the best function to use to
// read a single character.

void fgetc_and_getc(void)
{
	int ch;

	puts("Input a character: ");
	while ((ch = getc(stdin)) != 'D') {	/* Input D to exit. */
		putchar(ch);
	}
}

int main(void)
{
	fgetc_and_getc();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
