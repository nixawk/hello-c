#include <stdio.h>

// int getw (FILE *stream)

// This function reads a word (that is, an int) from stream. It’s provided for compatibility with SVID.
// We recommend you use fread instead (see Block Input/Output). Unlike getc, any int value could be a valid result.
// getw returns EOF when it encounters end-of-file or an error, but there is no way to distinguish this from an input
// word with value -1.

void getw_usage(void)
{
	putw(getw(stdin), stdout);
}

int main(void)
{
	getw_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
