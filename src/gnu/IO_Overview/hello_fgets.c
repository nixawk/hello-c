#include <stdio.h>
#include <stdlib.h>


// char * fgets (char *s, int count, FILE *stream)

// The fgets function reads characters from the stream stream up to and including a 
// newline character and stores them in the string s, adding a null character to mark
// the end of the string. You must supply count characters worth of space in s, but 
// the number of characters read is at most count - 1. The extra character space is 
// used to hold the null character at the end of the string.


// wchar_t * fgetws (wchar_t *ws, int count, FILE *stream)
// char * fgets_unlocked (char *s, int count, FILE *stream)
// wchar_t * fgetws_unlocked (wchar_t *ws, int count, FILE *stream)


#define SIZE 512


void
fgets_usage(void)
{
    char *s = NULL;

    s = calloc(SIZE, sizeof(char));
    if (s != NULL)
    {
        if (fgets(s, SIZE, stdin) != NULL)
        {
            printf("%s\n", s);
        }

        free(s);
    }
}


int
main(void)
{
    fgets_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html#Line-Input