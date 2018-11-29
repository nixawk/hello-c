#include <stdio.h>
#include <wchar.h>

// int putchar (int c)
// wint_t putwchar (wchar_t wc)
// int putchar_unlocked (int c)
// wint_t putwchar_unlocked (wchar_t wc)

void putwchar_usage(void)
{
	wchar_t ch = L'A';

	putwchar(ch);
}

int main(void)
{
	putwchar_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output
