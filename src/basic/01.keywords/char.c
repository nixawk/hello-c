/* type specifier for the character types (char, signed char, signed char) */

#include <stdio.h>

void keyword_char(void)
{
	char c = 0xff;
	unsigned char uc = 0xff;
	signed char sc = 0xff;

	if (c == uc)
		printf("char is unsigned char\n");
	else if (c == sc)
		printf("char is signed char\n");
	else
		printf("unknowm");
}

int main(void)
{
	keyword_char();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/char */
