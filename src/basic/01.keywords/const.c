/*
 * Objects declared with const-qualified types may be placed in read-only memory
 * by the compiler, and if the address of a const object is never taken in a
 * program, it may not be stored at all.
 *
 */

#include <stdio.h>
#include <stdlib.h>

const char program_name[] = "keyword_const";

int main(int argc, const char *argv[])
{
	if (argc < 2) {
		printf("[*] usage: %s arg1 arg2 [...]\n", program_name);
		exit(1);
	}

	for (int i = 1; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/const */
