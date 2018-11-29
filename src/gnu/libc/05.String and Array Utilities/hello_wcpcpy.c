#include <wchar.h>
#include <stdio.h>

// wchar_t * wcpcpy (wchar_t *restrict wto, const wchar_t *restrict wfrom)

// This function is like wcscpy, except that it returns a pointer to the end of
// the string wto (that is, the address of the terminating null wide character
// wto + wcslen (wform)) rather than the beginning.

// wcpcpy is a GNU extension and is declared in wchar.h

#define BUFSIZE 512

void wcpcpy_usage(void)
{
	wchar_t src[BUFSIZE] = L"hello, world";
	wchar_t dst[BUFSIZE];

	wchar_t *ws = wcpcpy(dst, src);
	wprintf(L"%p - %ls\n", dst, dst);
	wprintf(L"%p - %ls\n", ws, ws);
}

int main(void)
{
	wcpcpy_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
