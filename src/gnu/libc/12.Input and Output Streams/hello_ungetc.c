#include <stdio.h>

// Function: int ungetc (int c, FILE *stream)

// The ungetc function pushes back the character c onto the input stream
// stream. So the next input from stream will read c before anything else.

// If c is EOF, ungetc does nothing and just returns EOF. This lets you call
// ungetc with the return value of getc without needing to check for an error
// from getc.

void ungetc_usage(void)
{
	int ch = 'A';

	ungetc(ch, stdin);
	putchar(getc(stdin));
}

int main(void)
{
	ungetc_usage();
	return 0;
}

// http://man7.org/linux/man-pages/man3/ungetc.3.html
// https://www.gnu.org/software/libc/manual/html_node/How-Unread.html#How-Unread
