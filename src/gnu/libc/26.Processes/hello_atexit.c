#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// atexit  - register a function to be called at normal process termination

// int atexit(void (*function)(void));

// The atexit() function returns the value 0 if successful; otherwise it
// returns a nonzero value.

void atexit_handler1(void)
{
	printf("1st atexit handler called\n");
}

void atexit_handler2(void)
{
	printf("2nd atexit handler called\n");
}

void atexit_usage(void)
{

	printf("_SC_ATEXIT_MAX: %ld\n", sysconf(_SC_ATEXIT_MAX));

	atexit(atexit_handler1);
	atexit(atexit_handler2);

	printf("atexit demo func\n");
	exit(EXIT_SUCCESS);

	/* If _exit, atexit hander will not be called. */
	// _exit(EXIT_SUCCESS);
}

int main(void)
{
	atexit_usage();
	return 0;
}

/*

$ ./a.out                                                                                                                                                atexit demo func
2nd atexit handler called
1st atexit handler called

*/

// http://man7.org/linux/man-pages/man3/atexit.3.html
