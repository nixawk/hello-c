#include <sodium.h>

/*

int sodium_is_zero(const unsigned char *n, const size_t nlen);

This function returns 1 is the nlen bytes vector pointed by n contains only
zeros. It returns 0 if non-zero bits are found.

*/

#ifndef BUFSIZE
#define BUFSIZE 32
#endif

void
sodium_is_zero_usage(void)
{
    unsigned char buf[BUFSIZE];

    if (sodium_init() < 0)
    {
        exit(EXIT_FAILURE);
    }

    randombytes_buf(buf, BUFSIZE);

    if (sodium_is_zero(buf, BUFSIZE) == 1)
    {
        printf("buf is filled by 0\n");
    } else {
        printf("buf is not filled by 0\n");
    }

    sodium_memzero(buf, BUFSIZE);

    if (sodium_is_zero(buf, BUFSIZE) == 1)
    {
        printf("buf is filled by 0\n");
    } else {
        printf("buf is not filled by 0\n");
    }
}


int
main(void)
{
    sodium_is_zero_usage();
    return 0;
}

// reference
// https://download.libsodium.org/doc/helpers#testing-for-all-zeros
// https://github.com/jedisct1/libsodium/blob/master/src/libsodium/sodium/utils.c#L103
// https://github.com/jedisct1/libsodium/blob/master/src/libsodium/sodium/utils.c#L229