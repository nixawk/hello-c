#include <stdio.h>

// int putc (int c, FILE *stream)

// This is just like [fputc], except that most systems implement it as a macro,
// making it faster. One consequence is that it may evaluate the stream argument
// more than once, which is an exception to the general rule for macros.
// putc is usually the best function to use for writing a single character.

// int putc_unlocked (int c, FILE *stream)

// The [putc_unlocked] function is equivalent to the putc function except that it
// does not implicitly lock the stream.

void putc_usage(void)
{
	char ch = 'A';

	putc(ch, stdout);	// similar to [putchar]
}

int main(void)
{
	putc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Outputg
