#include <wctype.h>
#include <wchar.h>
#include <stdio.h>


// int iswalpha (wint_t wc)

// Returns true if wc is an alphabetic character (a letter).
// If iswlower or iswupper is true of a character, then iswalpha is also true.


// This function can be implemented using:

    // iswctype (wc, wctype ("alpha"))


void
iswalpha_usage(void)
{
    wchar_t string[] = L"hello, world";
    int i;

    for (i = 0; i < wcslen(string); i++)
    {
        if (iswalpha(string[i]))
        {
            printf("[+] [%c] is an alphabetic character.\n", string[i]);
        } else {
            printf("[+] [%c] is not an alphabetic character.\n", string[i]);
        }
    }
}


int
main(void)
{
    iswalpha_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters