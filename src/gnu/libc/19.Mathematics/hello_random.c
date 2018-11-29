#include <stdlib.h>
#include <stdio.h>

// Function: long int random(void)

// This function returns the next pseudo-random number in the sequence.
// The value returned ranges from 0 to 2147483647.

// NB: Temporarily this function was defined to return a int32_t value
// to indicate that the return value always contains 32 bits even if
// long int is wider. The standard demands it differently. Users must
// always be aware of the 32-bit limitation, through.

void random_usage(void)
{
	int i, n;

	for (i = 0; i < 10; i++) {
		n = random();
		printf("%d. random num: %d\n", i, n);
	}
}

int main(void)
{
	random_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/BSD-Random.html#BSD-Random
