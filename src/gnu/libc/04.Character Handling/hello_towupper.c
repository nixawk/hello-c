#include <wctype.h>
#include <stdio.h>

// wint_t towupper (wint_t wc)

// If wc is a lower-case letter, towupper returns the corresponding upper-case letter.
// Otherwise wc is returned unchanged.

// towupper can be implemented using

    // towctrans (wc, wctrans ("toupper"))


void
toupper_usage(void)
{
    wchar_t ch = L'a';

    printf("[%c] -> [%c]\n", ch, towupper(ch));
}


int
main(void)
{
    toupper_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Wide-Character-Case-Conversion.html#Wide-Character-Case-Conversion