#include <sodium.h>

/*

void sodium_memzero(void * const pnt, const size_t len);

After use, senstive data should be overwritten, but memset() and hand-written
code can be silently stripped out by an optimizing compiler or by the linker.

The sodium_memzero() function tries to effectively zero len bytes starting at
pnt, even if optimizations are being applied to the code.

*/

#ifndef BUFSIZE
#define BUFSIZE 32
#endif

void
sodium_memzero_usage(void)
{
    char buf[BUFSIZE] = "helloworld";

    if (sodium_init() < 0)
    {
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);
    sodium_memzero(buf, BUFSIZE);
    printf("%s\n", buf);
}

int
main(void)
{
    sodium_memzero_usage();
    return 0;
}

// reference
// https://download.libsodium.org/doc/memory_management#zeroing-memory