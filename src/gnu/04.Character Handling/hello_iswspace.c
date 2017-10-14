#include <wctype.h>
#include <stdio.h>

// int iswspace (wint_t wc)

// Returns true if wc is a whitespace character. In the standard "C" locale,
// iswspace returns true for only the standard whitespace characters:

    // ' '  - space
    // '\f' - formfeed
    // '\n' - newline
    // '\r' - carriage return
    // '\t' - horizontal tab
    // '\v' - vertical tab

// This function can be implemented using

    // iswctype (wc, wctype ("space"))


void
iswspace_usage(void)
{
    wchar_t ch = L'\t';

    if (iswspace(ch))
    {
        printf("[\\t] is a whitespace character.\n");
    }
}


int
main(void)
{
    iswspace_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters