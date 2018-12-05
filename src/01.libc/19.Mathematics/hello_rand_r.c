#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// int rand_r(unsigned int *seed)

// This function returns a random number in the range 0 to RAND_MAX just as
// rand does. However, all its state is stored in the seed argument. This
// means the RNG's state can only have as many bits as the type unsigned int
// has. This is far too few to provide a good RNG.

// If your program requires a reentrant RNG, we recommend you use the reentrant
// GNU extensions to the SVID random number generator. The POSIX.1 interface
// should only be used when the GNU extensions are not available.

void rand_r_usage(void)
{
	int i, n;
	unsigned int seed;

	seed = (unsigned int)time(NULL);

	for (i = 0; i < 10; i++) {
		n = rand_r(&seed);
		printf("%02d. random num: %d\n", i, n);
	}
}

int main(void)
{
	rand_r_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/ISO-Random.html#ISO-Random
