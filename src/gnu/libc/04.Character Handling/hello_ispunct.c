#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int ispunct (int c)

// Returns true if c is a punctuation character. This means any printing
// character that is not alphanumeric or a space character.


void
ispunct_usage(void)
{
    char string[] = ";? ";
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (ispunct(string[i]))
        {
            printf("[%c] is a punctuation character.\n", string[i]);
        } else {
            printf("[%c] is not a punctuation character.\n", string[i]);
        }
    }
}


int
main(void)
{
    ispunct_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters