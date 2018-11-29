#include <stdio.h>

// int getc (FILE *stream)
// wint_t getwc (FILE *stream)

// int getc_unlocked (FILE *stream)
// wint_t getwc_unlocked (FILE *stream)

void getc_usage(void)
{
	putchar(getc(stdin));
}

int main(void)
{
	getc_usage();
	return 0;
}
