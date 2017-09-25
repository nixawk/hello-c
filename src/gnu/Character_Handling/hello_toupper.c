#include <ctype.h>
#include <stdio.h>

// int toupper (int c)

// If c is a lower-case letter, toupper returns the corresponding upper-case letter.
// Otherwise c is returned unchanged.

void
toupper_usage(void)
{
    char ch = 'a';

    printf("[%c] toupper [%c]", ch, toupper(ch));
}


int
main(void)
{
    toupper_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Case-Conversion.html#Case-Conversion