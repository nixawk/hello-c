#include <stdio.h>
#include <ctype.h>
#include <errno.h>

char *
capitalize(char *buf)
{
    int c;

    if (buf == NULL)
    {
        errno = EFAULT;
        return NULL;
    }

    c = (unsigned char)*buf;
    *buf = toupper(c);

    return buf;
}

int
main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("%s <str1> <str2> ...\n", argv[0]);
        return -1;
    }

    for (i = 1; i < argc; i++)
    {
        printf("%s\n", capitalize(argv[i]));
    }

    return 0;
}

// https://stackoverflow.com/questions/20036553/c-function-to-capitalize-first-letter-of-words-in-an-array
// https://codereview.stackexchange.com/questions/187644/c-function-to-capitalize-first-word-in-a-sentence-handles-arbitrary-spaces