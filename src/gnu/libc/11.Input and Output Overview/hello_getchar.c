#include <stdio.h>

// int getchar (void)

// The getchar function is equivalent to getc with stdin as the value of the stream argument.

void getchar_usage(void)
{
	putchar(getchar());
}

int main(void)
{
	getchar_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
