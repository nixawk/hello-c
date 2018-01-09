#include <wchar.h>
#include <stdio.h>

    // wchar_t * wcsdup (const wchar_t *ws)

// This function copies the wide string ws into a newly allocated string.
// The string is allocated using malloc; If malloc cannot allocate space
// for the new string, wcsdup returns a null pointer. Otherwise it returns
// a pointer to the new wide string.

void
wcsdup_usage()
{
    wchar_t *ws = L"hello, world";
    wchar_t *ws_new = wcsdup(ws);

    if (ws_new != NULL)
    {
        wprintf(L"%ls\n", ws_new);
    }
}


int
main(void)
{
    wcsdup_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling