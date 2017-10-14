#include <wctype.h>
#include <stdio.h>


// int iswupper (wint_t wc)

// Returns true if wc is an upper-case letter. The letter need not be from the Latin alphabet,
// any alphabet representable is valid.

// This function can be implemented using

    // iswctype (wc, wctype ("upper"))

void
iswupper_usage(void)
{
    wchar_t ch = L'A';

    if (iswupper(ch))
    {
        printf("[%c] is a upper-case letter.\n", ch);
    }
}


int
main(void)
{
    iswupper_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters