#include <ctype.h>
#include <string.h>
#include <stdio.h>

// int isdigit (int c)

// Returns true if c is a decimal digit (‘0’ through ‘9’).


void
isdigit_usage(void)
{
    char string[] = "A0-B1-C2-D3";
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (isdigit(string[i]))
        {
            printf("[+] [%c] is a digit\n", string[i]);
        } else {
            printf("[-] [%c] is not a digit\n", string[i]);
        }
    }    
}


int
main(void)
{
    isdigit_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters