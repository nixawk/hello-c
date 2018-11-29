#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Function: char *initstate(unsigned int seed, char *state, size_t size)

// The initstate function is used to initialize the random number generator
// state. The argument state is an array of size bytes, used to hold the state
// information. It is initialized based on seed. The size must be between 8 and
// 256 bytes, and should be a power of two. The bigger the state array, the better.

// The return value is the previous value of the state information array.
// You can use this value later as an argument to setstate to restore the state

// Function: char *setstate(char *state)

// The setstate function restores the random number state information state.
// The argument must have been result of a previous call to initstate or setstate.
// The return value is the previous of the state information array. You can
// use this value later as an argument to setstate to restore that state.
// If the function fails the return value is NULL

// The four functions described so far in this section all work on a state
// which is shared by all threads. The state is not directly accessible to
// the user and can only be modified by these functions. This makes it hard
// to deal with situations where each thread should have its own pseudo-random
// number generator.

// Data Type: struct random_data
// Function: int random_r (struct random_data *restrict buf, int32_t *restrict result)
// Function: int srandom_r (unsigned int seed, struct random_data *buf)
// Function: int initstate_r (unsigned int seed, char *restrict statebuf, size_t statelen, struct random_data *restrict buf)
// Function: int setstate_r (char *restrict statebuf, struct random_data *restrict buf)

#define SIZE 1024
#define STATE_SIZE 256		// from 8 to 256

void initstate_usage(void)
{
	char state[SIZE];
	if (initstate(time(NULL), state, STATE_SIZE) == NULL) {
		fprintf(stderr, "initstate failed\n");
		exit(EXIT_FAILURE);
	} else {
		fprintf(stderr, "initstate success\n");
	}

	if (setstate(state) == NULL) {
		fprintf(stderr, "setstate failed\n");
		exit(EXIT_FAILURE);
	} else {
		fprintf(stderr, "setstate success\n");
		exit(EXIT_SUCCESS);
	}
}

int main(void)
{
	initstate_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/BSD-Random.html#BSD-Random
// http://pubs.opengroup.org/onlinepubs/009695399/functions/initstate.html
// https://ubuntuforums.org/showthread.php?t=328761
