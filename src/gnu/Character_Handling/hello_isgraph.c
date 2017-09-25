#include <ctype.h>
#include <stdio.h>
#include <string.h>


// int isgraph (int c)

// Returns true if c is a graphic character; that is, a character that has a glyph associated with it.
// The whitespace characters are not considered graphic.


void
isgraph_usage(void)
{
    char string[] = "1 A\t;!z2@";
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (isgraph(string[i]))
        {
            printf("[+] [%c] is a graphic character.\n", string[i]);
        } else {
            printf("[-] [%c] is not a graphic character.\n", string[i]);
        }
    }
}


int
main(void)
{
    isgraph_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters