#include <wchar.h>
#include <stdio.h>


// int wmemcmp (const wchar_t *a1, const wchar_t *a2, size_t size)

// The function wmemcmp compares the size wide characters beginning
// at a1 against the size wide characters beginning at a2. The value
// returned is smaller than or larger than zero depending on whether
// the first differing wide character is a1 is smaller or larger than
// the corresponding wide character in a2.

// If the contents of the two blocks are equal, wmemcmp returns 0.


void
wmemcmp_usage(void)
{
    wchar_t *ws1 = L"hello, world";
    wchar_t *ws2 = L"hello, c";

    if (0 == wmemcmp(ws1, ws2, 5))
    {
        wprintf(L"ws1 == ws2\n");
    }
}


int
main(void)
{
    wmemcmp_usage();
    return 0;
}


// http://www.gnu.org/software/libc/manual/html_mono/libc.html#Representation-of-Strings