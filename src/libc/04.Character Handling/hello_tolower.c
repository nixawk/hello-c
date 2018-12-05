#include <ctype.h>
#include <stdio.h>

// int tolower (int c)

// If c is an upper-case letter, tolower returns the corresponding lower-case letter.
// If c is not an upper-case letter, c is returned unchanged.

void tolower_usage(void)
{
	char ch = 'A';

	printf("[%c] tolower [%c].\n", ch, tolower(ch));
}

int main(void)
{
	tolower_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Case-Conversion.html#Case-Conversion
