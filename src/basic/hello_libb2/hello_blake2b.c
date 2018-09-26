#include <stddef.h>
#include <stdint.h>
#include <blake2.h>
#include <string.h>
#include <stdio.h>

/* Tested on ubuntu 18.04         */
/* sudo apt-get install libb2-dev */
/* gcc test_blake2b.c -lb2        */

void
blake2b_usage()
{

    uint8_t out[BLAKE2B_OUTBYTES];                         // MAX: BLAKE2B_OUTBYTES
    char in[] = "helloworld";
    char key[BLAKE2B_KEYBYTES] = "this is my secret key";  // MAX: BLAKE2B_KEYBYTES

    memset(out, 0, BLAKE2B_OUTBYTES);
    blake2b(out, in, key, BLAKE2B_OUTBYTES, strlen(in), strlen(key));

    for (int i=0; i < BLAKE2B_OUTBYTES; i++) {
        printf("%02X ", out[i]);
    }
}

int
main(int argc, const char *argv[])
{
    blake2b_usage();
    return 0;
}

// reference
// https://blake2.net/
// https://github.com/BLAKE2/libb2/blob/master/src/blake2b.c#L410
