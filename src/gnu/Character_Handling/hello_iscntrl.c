#include <ctype.h>
#include <stdio.h>


// int iscntrl (int c)

// Returns true if c is a control character (that is, a character that is not a printing character).


void
iscntrl_usage(void)
{
    char ch = '\b';

    if (iscntrl(ch))
    {
        printf("[\\b] is a control character.\n");
    }
}


int
main(void)
{
    iscntrl_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters