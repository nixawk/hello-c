#include <wctype.h>
#include <stdio.h>

// wctrans_t wctrans (const char *property)
// wint_t towctrans (wint_t wc, wctrans_t desc)

// The wctrans function has to be used to find out whether a named mapping is defined in the
// current locale selected for the LC_CTYPE category. If the returned value is non-zero, you
// can use it afterwards in calls to towctrans. If the return value is zero no such mapping
// is known in the current locale.

void
wctrans_usage(void)
{
    wchar_t ch = L'A';

    printf("[%c] -> [%c]", ch, towctrans(ch, wctrans("tolower")));
}


int
main(void)
{
    wctrans_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Wide-Character-Case-Conversion.html#Wide-Character-Case-Conversionh