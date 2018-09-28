#include <sodium.h>

/*

void sodium_add(unsigned char *a, const unsigned char *b, const size_t len);

The sodium_add() function accepts two pointers to unsigned numbers encoded
in little-endian format, a and b, both of size len bytes.

It computes (a + b) mod 2^(8*len) in constant time for a given length, and
overwrites a with the result.

*/

void
sodium_add_uage(void)
{
    unsigned char a[crypto_generichash_BYTES];
    unsigned char b[crypto_generichash_BYTES];

    if (sodium_init() < 0)
    {
        exit(EXIT_FAILURE);
    }

    sodium_add(a, b, crypto_generichash_BYTES);
}


int
main(void)
{
    sodium_add_uage();
    return 0;
}

// reference
// https://download.libsodium.org/doc/helpers#adding-large-numbers
// https://github.com/jedisct1/libsodium/blob/master/src/libsodium/sodium/utils.c#L288