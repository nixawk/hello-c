#include <stdio.h>
#include <sodium.h>

/*
 * sudo aot-get install libsodium-dev
 *
 */

// uint32_t randombytes_random(void);
// The randombytes_random() function returns an unpredictable value between 0
// and 0xffffffff(included)

int main(void)
{
	if (sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		exit(EXIT_FAILURE);
	}

	printf("randombytes_random() = %d\n", randombytes_random());
	return 0;
}

// https://download.libsodium.org/doc/quickstart
// https://download.libsodium.org/doc/generating_random_data
