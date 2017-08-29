#include <string.h>
#include <stdio.h>

/*

void memcpy(void *str1, const void *str2, size_t n);

copies n characters from memory area str2 memory area str1.

str1  - This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*
str2  - This is pointer to the source of data to be copied, type-casted to a pointer of type void*.
n     - This is the number of bytes to be copied.

The function returns a pointer to destination, which is str1.

*/

int main(void)
{
    const char src[32] = "this is a demo string";
    char dest[32];

    memset(dest, 'A', sizeof(dest));
    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src, sizeof(src));
    printf("After memcpy dest = %s\n", dest);
    return 0;
}
