#include <ctype.h>
#include <stdio.h>


// int isprint (int c)
// Returns true if c is a printing character.
// Printing characters include all the graphic characters, plus the space (‘ ’) character.

// What's the difference between isgraph() with isprint() ?


void
isprint_usage(void)
{
    char ch = ' ';

    if (isprint(ch))
    {
        printf("[%c] is a printing character.\n", ch);
    }
}


int
main(void)
{
    isprint_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters