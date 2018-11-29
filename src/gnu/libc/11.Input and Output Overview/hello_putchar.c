#include <stdio.h>

// int putchar (int c)
// wint_t putwchar (wchar_t wc)
// int putchar_unlocked (int c)
// wint_t putwchar_unlocked (wchar_t wc)

void putchar_usage(void)
{
	char ch = 'A';

	putchar(ch);
}

int main(void)
{
	putchar_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output
