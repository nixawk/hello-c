#include <string.h>
#include <stdio.h>

/*

int memcmp(const void *str1, const void *str2, size_t n);

compares the first n bytes of memory area str1 and memory area str2

str1 - This is the pointer to a block of memory.
str2 - This is the pointer to a block of memory.
n    - This is the number of bytes to be compared.

if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal than str2.

*/

int main(void)
{
    char str1[] = "helloworld";
    char str2[] = "helloc";
    int ret;

    if (sizeof(str2) < sizeof(str1))
    {
        ret = memcmp(str1, str2, sizeof(str2));
        printf("(sizeof(str1) > sizeof(str2)) - return value : %d\n", ret);
        printf("%c - %c = %d\n", 'w', 'c', 'w' - 'c');
    }
    else
    {
        ret = memcmp(str1, str2, sizeof(str1));
        printf("(sizeof(str1) < sizeof(str2)) - return value : %d\n", ret);
    }
    return 0;
}
