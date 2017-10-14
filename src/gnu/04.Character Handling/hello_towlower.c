#include <wctype.h>
#include <stdio.h>

// wint_t towlower (wint_t wc)

// If wc is an upper-case letter, towlower returns the corresponding lower-case letter.
// If wc is not an upper-case letter, wc is returned unchanged.

// towlower can be implemented using

    // towctrans (wc, wctrans ("tolower"))


void
towlower_usage(void)
{
    wchar_t ch = L'A';

    printf("[%c] -> [%c]\n", ch, towlower(ch));
}


int
main(void)
{
    towlower_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Wide-Character-Case-Conversion.html#Wide-Character-Case-Conversion