#include <string.h>
#include <stdio.h>
#include <errno.h>

/*

char *strerror(int errnum)

errnum - This is the error number, usually errno.

This function returns a pointer to the error string describing error errnum.

*/

int main()
{
    FILE *fp;

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("Error: %s\n", strerror(errno));
    }

    return 0;
}
