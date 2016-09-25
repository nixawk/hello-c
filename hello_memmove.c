#include <string.h>
#include <stdio.h>

/*

void *memmove(void *dst, const void *src, size_t len);

copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy();

str1   - This is a pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
str2   - This is a pointer to the source of data to be copied, type-casted to a pointer of type void*.
n      - This is the number of bytes to be copied.

This function returns a pointer to the destination, which is str1.

*/

int main()
{
    char dest[256];
    const char src[] = "this is a demo string";

    memset(dest, 0, sizeof(dest));
    memmove(dest, src, sizeof(src));
    printf("destination string: %s\n", dest);
    return 0;
}
