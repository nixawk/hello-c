#include <ctype.h>
#include <stdio.h>


// int islower (int c)

// Returns true if c is lower-case letter. The letter need not be from the Latin alphalet,
// any alphabet representable is valid.


void
islower_usage(void)
{
    char ch = 'a';

    if (islower(ch))
    {
        printf("[%c] is a lower-case letter.\n", ch);
    }
}


int
main(void)
{
    islower_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters