#include <string.h>
#include <stdio.h>

/*
size_t strcspn(const char *str1, const char *str2);

calculates the length of the initial segment of str1, which consists entirely of characters not in str2.

str1 - This is the main C string to be scanned.
str2 - This is the string containing a list of characters to match in str1.

This function returns the number of characters in the initial segment of string str1 which are not in the string str2.

*/

int main(void)
{
    int len;
    const char str1[] = "ABCDEF4960910";
    const char str2[] = "013";

    len = strcspn(str1, str2);
    printf("First matched character is at %d\n", len + 1);
    return 0;
}
