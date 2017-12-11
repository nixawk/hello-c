#include <wchar.h>
#include <stdio.h>


// size_t wcsnlen (const wchar_t *ws, size_t maxlen)

// wcsnlen is the wide character equivalent to strnlen. The maxlen parameter
// specifies the maximum number of wide characters.


void
wcsnlen_usage(void)
{
	wchar_t *ws = L"hello, world";
	size_t wc = wcsnlen(ws, 5);

	wprintf(L"%lu\n", wc);
}


int
main(void)
{
	wcsnlen_usage();
	return 0;
}


// http://www.gnu.org/software/libc/manual/html_mono/libc.html#Representation-of-Strings