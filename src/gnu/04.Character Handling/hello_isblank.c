#include <ctype.h>
#include <stdio.h>

// int isblank (int c)
// Returns true if c is a blank character; that is, a space or a tab. This function was
// originally a GNU extension, but was added in ISO C99.


void
isblank_usage(void)
{
    char ch = ' ';

    if (isblank(ch))
    {
        printf("[%c] is a blank character.\n", ch);
    }
}


int
main(void)
{
    isblank_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters