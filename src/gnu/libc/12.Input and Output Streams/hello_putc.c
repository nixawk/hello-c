// int putc (int c, FILE *stream)

// This is just like fputc, except that most systems implement it as a macro,
// making it faster. One consequence is that it may evaluate the stream
// argument more than once, which is an exception to the general rule for
// macros. putc is usually the best function to use for writing a single character.

// Function: int putchar (int c)

// The putchar function is equivalent to putc with stdout as the value of the
// stream argument.

#include <stdio.h>

void putc_and_putchar(void)
{
	char c = 'A';

	putc(c, stdout);
	putchar(c);
}

int main(void)
{
	putc_and_putchar();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output
