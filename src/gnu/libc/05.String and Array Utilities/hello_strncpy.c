#include <string.h>
#include <stdio.h>

/*

char *strncpy(char *dest, const char *src, size_t n);

copies up to n characters from the string pointed to, by src to dest. In a case where the length of src is less than that of n, the remainder of dest will be padded with null bytes.

dest - This is the pointer to the destination array where the content is to be copied.
src  - This is the string to be copied.
n    - The number of characters to be copied from source.

*/

int main(void)
{
    char src[256];
    char dest[256];
    char *pointer;

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "This is a demo string");
    strncpy(dest, src, 10);
    printf("string : %s\n", dest);
    return 0;
}
