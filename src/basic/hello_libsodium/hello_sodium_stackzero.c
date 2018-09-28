#include <sodium.h>

/*

void sodium_stackzero(const size_t len);

The sodium_stackzero() function clears len bytes above the current stack pointer,
to overwrite sensitive values that may have been temporarily stored on the stack.

*/

void
sodium_stackzero_usage(void)
{
    const size_t len = 1024;

    if (sodium_init() < 0)
    {
        exit(EXIT_FAILURE);
    }

    sodium_stackzero(len);
}


int
main(void)
{
    sodium_stackzero_usage();
    return 0;
}


// reference
// https://download.libsodium.org/doc/helpers#clearing-the-stack