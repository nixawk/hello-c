#include <ctype.h>
#include <stdio.h>

// int isascii (int c)

// Returns true if c is a 7-bit unsigned char value that fits into the US/UK ASCII character set.
// This function is a BSD extension and is also an SVID extension.

void isascii_usage(void)
{
	char ch = '?';

	if (isascii(ch)) {
		printf("[?] is a ascii character.\n");
	}
}

int main(void)
{
	isascii_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
