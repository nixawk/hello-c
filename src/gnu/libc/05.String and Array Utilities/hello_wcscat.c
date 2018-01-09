#include <wchar.h>
#include <stdio.h>


// wchar_t * wcscat (wchar_t *restrict wto, const wchar_t *restrict wfrom)

// The wcscat function is similar to wcscpy, except that the wide characters
// from wfrom are concatenated or appended to the end of wto, instead of
// overwriting it. That is, the first wide character from wfrom overwrites
// the null wide character marking the end of wto.


#define BUFSIZE 512


void
wcscat_usage(void)
{
    wchar_t ws_hello[BUFSIZE] = L"hello";
    wchar_t ws_world[BUFSIZE] = L"world";

    wchar_t *ws = wcscat(ws_hello, ws_world);

    wprintf(L"ws_hello: %p\n", ws_hello);
    wprintf(L"ws_world: %p\n", ws_world);
    wprintf(L"ws      : %p\n", ws);

    wprintf(L"%ls\n", ws);
}


int
main(void)
{
    wcscat_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling