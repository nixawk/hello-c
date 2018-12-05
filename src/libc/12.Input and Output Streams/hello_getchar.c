#include <stdio.h>

void fgetc_getc_getchar(void)
{
	int c1, c2, c3;

	/* Input a character */

	c1 = fgetc(stdin);
	c2 = getc(stdin);
	c3 = getchar();

	/* Output a character */

	putchar(c1);
	putchar(c2);
	putchar(c3);
}

int main(void)
{
	fgetc_getc_getchar();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
