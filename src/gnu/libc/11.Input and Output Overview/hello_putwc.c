#include <stdio.h>
#include <wchar.h>


// wint_t putwc (wchar_t wc, FILE *stream)

// This is just like [fputwc], except that it can be implement as a macto,
// making it faster. Once consequence is that it may evaluate the stream
// argument more than once, which is an exception to the general rule for
// macro. [putwc] is usually the best function to use for writing a
// single wide character.

// wint_t putwc_unlocked (wchar_t wc, FILE *stream)

// The [putwc_unlocked] function is equivlent to the [putwc] function
// except that it does not implicitly lock the stream.


void
putwc_usage(void)
{
    wchar_t ch = L'A';

    putwc(ch, stdout);
}


int
main(void)
{
    putwc_usage();
    return 0;
}