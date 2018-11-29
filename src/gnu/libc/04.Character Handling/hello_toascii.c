#include <ctype.h>
#include <stdio.h>

void toascii_usage(void)
{
	int c = 97;
	printf("[%d] toascii [%c]", c, toascii(c));
}

int main(void)
{
	toascii_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Case-Conversion.html#Case-Conversions
