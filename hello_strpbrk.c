#include <string.h>
#include <stdio.h>

/*
char *strpbrk(const char *str1, const char *str2);

str1 - This is the C string to be scanned.
str2 - This is the C string containing the characters to match.

This function returns a pointer to the character in str1 that matches one of the characters in str2, or NULL if no such character is found.

*/

int main(void)
{
    const char str1[] = "helloworld123";
    const char str2[] = "love";
    char *pointer;

    pointer = strpbrk(str1, str2);
    printf("pointer: %p - %c\n", pointer, *pointer);

    return 0;
}
