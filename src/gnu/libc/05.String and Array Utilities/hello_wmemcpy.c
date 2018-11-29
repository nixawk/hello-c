#include <wchar.h>
#include <stdio.h>

    // wchar_t * wmemcpy (wchar_t *restrict wto, const wchar_t *restrict wfrom, size_t size)

// The wmemcpy function copies size wide characters from the object beginning
// at wfrom into the object beginning at wtp. The behavior of this function
// is underfined if the two arrays wto and wfrom overlap; use wmemmove instead
// if overlapping is possible.

#define BUFSIZE 512

void wmemcpy_usage(void)
{
	wchar_t src[BUFSIZE] = L"hello, world";
	wchar_t dst[BUFSIZE] = { };

	wmemcpy(dst, src, wcslen(src));
	wprintf(dst);
}

int main(void)
{
	wmemcpy_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
