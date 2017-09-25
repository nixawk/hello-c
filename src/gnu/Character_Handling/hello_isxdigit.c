#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int isxdigit (int c)

// Return true if c is a hexiadecimal digit. Hexadecimal digits include the normal
// decimal digits '0' through '9' and the letters 'A' through 'F' and 'a' through 'f'.


void
isxdigit_usage(void)
{
    char string[] = "-0fF";
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (isxdigit(string[i]))
        {
            printf("[%c] is a hexadecimal digit\n", string[i]);
        } else {
            printf("[%c] is not a hexadecimal digit\n", string[i]);
        }
    }

}


int
main(void)
{
    isxdigit_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters