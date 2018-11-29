#include <stdio.h>
#include <sodium.h>

// void randombytes_buf(void * const buf, const size_t size);

// The randombytes_buf() function fills bytes starting at buf with an
// unpredictable sequence of bytes.

#ifndef BUFSZIE
#define BUFSIZE 32
#endif

int main(void)
{
	unsigned char buf[BUFSIZE];
	char hex[BUFSIZE * 2 + 1];

	if (sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		exit(EXIT_FAILURE);
	}

	randombytes_buf(buf, BUFSIZE);
	sodium_bin2hex(hex, BUFSIZE * 2 + 1, buf, BUFSIZE);
	printf("%s\n", hex);

	return 0;
}

// https://download.libsodium.org/doc/generating_random_data
