// Count Words in a string
// Counts the number of individual words in a string.
// For added complexity read these strings in from a text file
// and generate a summary.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int
count_words(const char *s)
{
    int i, w;

    for (i = 0, w = 0; i < strlen(s); i++)
    {
        if (!isspace(*(s+i)))
        {
            w++;
            while (!isspace(*(s+i)) && *(s+i) != '\0')
            {
                i++;
            }
        }
    }

    return w;
}

int
main(int argc, const char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("[*] Usage: %s <str1> <str2> ...\n", argv[0]);
        return -1;
    }

    for (i = 1; i < argc; i++)
    {
        printf("s = %s, w= %d\n ", argv[i], count_words(argv[i]));
    }

    return 0;
}

/*

$ ./a.out " a b " "a b c " "a b c d"
s =  a b , w= 2
 s = a b c , w= 3
 s = a b c d, w= 4

*/
