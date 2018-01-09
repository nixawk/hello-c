#include <wchar.h>
#include <stdio.h>


// wchar_t * wmemset (wchar_t *block, wchar_t wc, size_t size)

// This function copies the value of wc into each of the first size wide
// characters of the object beginning at block. It returns the value of
// block.

#define BUFSIZE 32


void
wmemset_usage(void)
{
    wchar_t ws[BUFSIZE];
    wmemset(ws, L'A', wcslen(ws));
    wprintf(ws);
}


int
main(void)
{
    wmemset_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling