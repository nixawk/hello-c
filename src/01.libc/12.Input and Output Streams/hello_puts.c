#include <stdio.h>

// Function: int fputs (const char *s, FILE *stream)
// Function: int puts (const char *s)

void fputs_and_puts(void)
{
	char s[] = "hello, world\n";

	fputs(s, stdout);
	puts(s);
}

int main(void)
{
	fputs_and_puts();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output
