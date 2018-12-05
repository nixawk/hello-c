#include <stdio.h>

// int fgetc (FILE *stream)

// This function reads the next character as an unsigned char from the stream stream and returns its value, 
// converted to an int. If an end-of-file condition or read error occurs, EOF is returned instead.

// int fgetc_unlocked (FILE *stream)

void fgetc_usage(void)
{
	putchar(fgetc(stdin));
}

int main(void)
{
	fgetc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
