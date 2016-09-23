#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*

int tolower(int c)
- This function converts uppercase letters to lowercase.

int toupper(int c)
- This function converts lowercase letters to uppercase.

*/

int main()
{
    char aStr[] = "HELLOWORLD";
    int i = 0;

    printf("%c\n", tolower('A'));
    printf("%c\n", toupper('a'));

    for (i = 0; i < strlen(aStr); ++i)
    {
        fputc(tolower(aStr[i]), stdout);
    }
    return 0;
}
