#include <stdio.h>

// Function: int printf (const char *template, …)

// The printf function prints the optional arguments under the control of the
// template string to the stream stdout. It returns the number of characters
// printed, or a negative value if there was an output error.

void printf_usage(void)
{
	int cnt;
	const char s[] = "Hello, World !";

	cnt = printf("%s\n", s);	/* print characters into stdout stream */
	printf("%d\n", cnt);	/* show printed characters count */
}

int main(void)
{
	printf_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Formatted-Output-Functions
