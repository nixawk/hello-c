#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)	/* copy input to output */
		putchar(c);

	return 0;
}
