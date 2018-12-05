#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Function: void srandom(unsigned int seed)

// The srandom function sets the state of the random number generator based on
// the integer seed. If you supply a seed value of 1, this will cause random
// to reproduce the default set of random numbers.

// To produce a different set of pseudo-random numbers each time your program
// runs, do srandom (time(0))

void srandom_usage(void)
{
	int i, n;
	srandom(time(0));

	for (i = 0; i < 10; i++) {
		n = random();
		printf("%d. random num: %d\n", i, n);
	}
}

int main(void)
{
	srandom_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/BSD-Random.html#BSD-Random
