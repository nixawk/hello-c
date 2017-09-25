#include <wctype.h>
#include <stdio.h>


// int iswblank (wint_t wc)

// Returns true if wc is a blank character; that is, a space or a tab.
// This function was originally a GNU extension, but was added in ISO C99. It is declared in wchar.h.

void
iswblank_usage(void)
{
    wchar_t ch = L'\t';

    if (iswblank(ch))
    {
        printf("[\\t] is a blank character.\n");
    }
}


int
main(void)
{
    iswblank_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters