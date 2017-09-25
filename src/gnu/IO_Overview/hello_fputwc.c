#include <stdio.h>
#include <wchar.h>

// wint_t fputwc (wchar_t wc, FILE *stream)

// The fputwc function writes the wide character wc to the stream stream.
// WEOF is returned if a write error occurs; otherwise the character wc is returned.


// wint_t fputwc_unlocked (wchar_t wc, FILE *stream)

// The [fputwc_unlocked] function is equivalent to the [fputwc] function
// except that it does not implicitly lock the stream.


void
fputwc_usage(void)
{
    wchar_t ch = L'A';

    fputwc(ch, stdout);
}


int
main(void)
{
    fputwc_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output