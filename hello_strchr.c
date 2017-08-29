#include <string.h>
#include <stdio.h>

/*

char *strchr(const  char *str, int c);

searches for the first occurrence of the character c (an unsigned char) in the string pointed to by the argument str.

str    - This is the C string to be scanned.
c      - This is the character to be searched in str.

This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.

*/

int main(void)
{
    const char aStr[] = "helloworld";
    int c = 'e';
    char *pointer;

    pointer = strchr(aStr, c);

    printf("pointer is : %p\n", pointer);

    return 0;
}
