#include <wchar.h>
#include <stdio.h>

// wchar_t * wcsstr (const wchar_t *haystack, const wchar_t *needle)

// This is like wcschr, except that it searches haystack for a substring 
// needle rather than just a single wide character. It returns a pointer
// into the string haystack that is the first wide character of the 
// substring, or a null pointer if no match was found. If needle is an
// empty string, the function returns haystack.

void wcsstr_usage(void)
{
	wchar_t *ws = L"hello, world";
	wchar_t *ws_ = wcsstr(ws, L"lo");

	if (ws_ != NULL) {
		wprintf(L"%ls\n", ws_);
	}
}

int main(void)
{
	wcsstr_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
