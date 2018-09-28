#include <sodium.h>

/*

int sodium_compare(const void * const b1_, const void * const b2_, size_t len);

Given b1_ and b2_, two len bytes numbers encoded in little-endian format, this
function returns:

    -1 if b1_ is less than b2_
    0 if b1_ equals b2_
    1 if b1_ is greater than b2_

The comparison is done in constant time for a given length.
This function can be used with nonces, in order to prevent replay attacks.

*/

void
sodium_compare_usage(void)
{
    unsigned char a[crypto_generichash_BYTES];
    unsigned char b[crypto_generichash_BYTES];
    char ahex[crypto_generichash_BYTES * 2 + 1];
    char bhex[crypto_generichash_BYTES * 2 + 1];
    int sodium_compare_retval;

    if (sodium_init() < 0)
    {
        exit(EXIT_FAILURE);
    }

    randombytes_buf(a, crypto_generichash_BYTES);
    randombytes_buf(b, crypto_generichash_BYTES);

    sodium_compare_retval = sodium_compare(a, b, crypto_generichash_BYTES);

    sodium_bin2hex(ahex, crypto_generichash_BYTES * 2 + 1, a, crypto_generichash_BYTES);
    sodium_bin2hex(bhex, crypto_generichash_BYTES * 2 + 1, b, crypto_generichash_BYTES);

    printf("a = %s\nb = %s\n", ahex, bhex);
    printf("sodium_compare(a, b) = %d\n", sodium_compare_retval);
}


int
main(void)
{
    sodium_compare_usage();
    return 0;
}

/*

$ ./hello_sodium_compare
a = c50127cc68e847e2105c12f3dce2a84a7cbe4c033b5df447be60034621cd556b
b = 3bea5bede7f6e1cc79c127eb992c33f7bae9ae0cf13e5ee8ca5d5eb52edd9c02
sodium_compare(a, b) = 1

*/

// reference
// https://download.libsodium.org/doc/helpers#comparing-large-numbers