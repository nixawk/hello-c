#include <stdio.h>

// int fputc (int c, FILE *stream)

// The fputc function converts the character c to type unsigned char, and writes it to
// the stream. EOF is returned if a write error occurs; otherwise the character c is
// returned.

//  int fputc_unlocked (int c, FILE *stream)

// The [fputc_unlocked] function is equivalent to the [fputc] function except that it does
// not implicitly lock the stream.

void fputc_usage(void)
{
	char ch = 'A';
	fputc(ch, stdout);
}

int main(void)
{
	fputc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output
