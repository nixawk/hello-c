#include <wctype.h>
#include <stdio.hg>

// int iswlower (wint_t wc)

// Returns true if wc is a lower-case letter. The letter need not be from the Latin alphabet,
// any alphabet representable is valid.

// This function can be implemented using

    // iswctype (wc, wctype ("lower"))


void
iswlower_usage(void)
{
    wchar_t ch = L'a';

    if (iswlower(ch))
    {
        printf("[%c] is a lower letter.\n", ch);
    }
}


int
main(void)
{
    iswlower_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters