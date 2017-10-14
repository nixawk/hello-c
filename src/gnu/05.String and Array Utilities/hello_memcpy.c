#include <string.h>
#include <stdio.h>


// void * memcpy(void *restrict dst, const void *restrict src, size_t n);
// void * memmove(void *dst, const void *src, size_t len);


// Most of funtions do not work properly if the source and destination arrays overlap.
// For example, if the beginning of destination array overlaps the end of the source
// array, the original contents of that part of the source array may get overwritten
// before it is copied. Even worse, in the case of the string functions, the null byte
// marking the end of the string may be lost, and the copy function might get stuck
// in a loop trashing all the memory allocated to your program.

    // memcpy   : 123456789abcdef | 16789abcdabcdef | 1234523456789ef |
    // memmove  : 123456789abcdef | 123456789abcdef | 1234523456789ef |


void
memcpy_str(void)
{
    char string[16] = "123456789abcdef";
    char strtmp[16];

    strcpy(strtmp, string);
    printf("\nmemcpy   : ");
    printf("%s | ", strtmp);

    strcpy(strtmp, string);
    memcpy(strtmp+1, strtmp+5, 8);    /* attention here */
    printf("%s | ", strtmp);

    strcpy(strtmp, string);
    memcpy(strtmp+5, strtmp+1, 8);
    printf("%s | ", strtmp);

}


void
memmove_str(void)
{
    char string[16] = "123456789abcdef";
    char strmov[16];

    strcpy(strmov, string);
    printf("\nmemmove  : ");
    printf("%s | ", strmov);

    strcpy(strmov, string);
    memmove(strmov+1, strmov+5, 8);    /* attention here */
    printf("%s | ", string);

    strcpy(strmov, string);
    memmove(strmov+5, strmov+1, 8);
    printf("%s | ", strmov);
}


int
main(void)
{
    memcpy_str();
    memmove_str();

    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Copying-Strings-and-Arrays.html#Copying-Strings-and-Arrays
// https://stackoverflow.com/questions/1201319/what-is-the-difference-between-memmove-and-memcpy
// https://stackoverflow.com/questions/4415910/memcpy-vs-memmove
// https://www.pixelstech.net/article/1302786310-memcpy%28%29-vs-memmove%28%29-in-C