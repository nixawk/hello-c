#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Function: void srand(unsigned int seed)

// This function establishes seed as the seed for a new series of pseudo-random
// numbers. If you can rand before a seed has been established with srand, it
// uses the value 1 as a default seed.

// To produce a different pseudo-random series each time your program is run,
// do srand(time(0))

void srand_usage(void)
{
	int i;
	time_t t;

	t = time(NULL);
	srand(t);		// random seed

	for (i = 0; i < 10; i++) {
		printf("%d. rand num: %d\n", i, rand());
	}
}

int main(void)
{
	srand_usage();
	return 0;
}

// https://stackoverflow.com/questions/471248/what-is-ultimately-a-time-t-typedef-to
// https://stackoverflow.com/questions/16569239/how-to-use-function-srand-with-time-h
// https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
