#include <stdio.h>
#include <wchar.h>

// int wctob (wint_t c)

// The wctob function ("wide character to byte") takes as the parameter a valid
// wide character. If the multibyte represnetation for this character in the
// initiali state is exactly one byte long, the return value of this function
// is this character. Otherwise the return value is EOF.

void
wctob_usage(void)
{
    wint_t wc = 210L;
    int c = wctob(wc);

    printf("%d\n", c);   
}


int
main(void)
{
    wctob_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling