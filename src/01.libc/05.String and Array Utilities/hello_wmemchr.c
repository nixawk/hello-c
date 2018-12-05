#include <wchar.h>
#include <stdio.h>

// wchar_t * wmemchr (const wchar_t *block, wchar_t wc, size_t size)

// The function finds the first occurrence of the wide character wc in
// the initial size wide characters of the object beginning at block.
// The return value is a pointer to the located wide character, or a null
// pointer if no match was found.

void wmemchr_usage(void)
{
	wchar_t *ws = L"hello, world";
	wchar_t *ws_ = wmemchr(ws, L'l', wcslen(ws));

	if (ws_ != NULL) {
		wprintf(L"%ls\n", ws_);
	}
}

int main(void)
{
	wmemchr_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
