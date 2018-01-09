#include <stdio.h>
#include <wchar.h>

// wint_t getwchar (void)

// The getwchar function is equivalent to getwc with stdin as the value of the stream argument.

//  wint_t getwchar_unlocked (void)

m
void
getwchar_usage(void)
{
    putwchar(getwchar());
}


int
main(void)
{
    getwchar_usage();
    return 0;
}



// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input