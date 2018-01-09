#include <wctype.h>
#include <stdio.h>


// int iswpunct (wint_t wc)

// Returns true if wc is a punctuation character. This means any printing character that is
// not alphanumeric or a space character.

// This function can be implemented using

    // iswctype (wc, wctype ("punct"))


void
iswpunct_usage(void)
{
    wchar_t ch = L'?';

    if (iswpunct(ch))
    {
        printf("[%c] is a punctuation character.\n", ch);
    }
}


int
main(void)
{
    iswpunct_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters