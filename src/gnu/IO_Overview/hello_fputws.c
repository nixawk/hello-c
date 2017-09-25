#include <stdio.h>
#include <wchar.h>

// int fputws (const wchar_t *ws, FILE *stream)
// int fputws_unlocked (const wchar_t *ws, FILE *stream)

// The function fputws writes the wide character string ws to the stream stream.
// The terminating null character is not written. This function does not add a newline character,
// either. It outputs only the characters in the string.


void
fputws_usage(void)
{
    wchar_t string[] = L"hello, world\n";

    fputws(string, stdout);
}


int
main(void)
{
    fputws_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output