#include <string.h>
#include <stdio.h>

/*
void *memchr(const void *str, int c, size_t n);

Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.

str - This is the pointer to the block of memory where the search is performed.
c   - This is the value to be passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value.
n   - This is the number of bytes to be analyzed.

This function returns a pointer to the matching byte or NULL if the character does not occur in the given memory area.
*/

int main()
{
    char aStr[] = "helloworld";
    // void *pointer;
    char *pointer;
    const char ch = 'e';

    pointer = memchr(aStr, ch, sizeof(aStr));

    if ( pointer != NULL)
    {
        printf("aStr pointer : %p\n", aStr);
        printf("e pointer    : %p\n", pointer);
        return 0;
    }
    return 0;
}
