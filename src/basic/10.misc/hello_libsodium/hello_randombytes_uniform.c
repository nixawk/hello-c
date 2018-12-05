#include <stdio.h>
#include <sodium.h>

// uint32_t randombytes_uniform(const uint32_t upper_bound);

// The randombytes_uniform() function returns an unpredictable value between
// 0 and upper_bound(excluded). Unlike randombytes_random() % upper_bound,
// it guarantees a uniform distribution of the possible output values even
// when upper_bound is not a power of 2. Note that an upper_bound < 2 leaves
// only a single element to be chosen, namely 0.

int main(void)
{
	const uint32_t upper_bound = 1000;

	if (sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		exit(EXIT_FAILURE);
	}

	printf("randombytes_uniform(const uint32_t) = %d\n",
	       randombytes_uniform(upper_bound)
	    );

	return 0;
}

// https://download.libsodium.org/doc/generating_random_data
