#include <wctype.h>
#include <stdio.h>


// int iswdigit (wint_t wc)

// Returns true if wc is a digit (e.g., ‘0’ through ‘9’). Please note that this function
// does not only return a nonzero value for decimal digits, but for all kinds of digits. 

// This function can be implemented using

    // iswctype (wc, wctype ("digit"))


void
iswdigit_usage(void)
{
    wchar_t ch = L'9';

    if (iswdigit(ch))
    {
        printf("[%c] is a digit.\n", ch);
    }
}


int
main(void)
{
    iswdigit_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters