#include <stdio.h>
#include <wchar.h>

// wint_t btowc (int c)

// The btowc function ("byte to wide character") converts a valid single byte
// character c in the initial shift state into the wide character equivalent
// using the conversion rules from the curently selected locale of the LC_CTYPE
// category.

// If (unsigned char) c is no valid single byte multibyte character or if c is
// EOF, the function returns WEOF.

void btowc_usage(void)
{
	int c = 1234;
	wint_t wc = btowc(c);

	wprintf(L"%ld\n", wc);
}

int main(void)
{
	btowc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
