#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

// void abort (void)

// The [abort] function causes abnormal program termination.
// This does not execute cleanup functions registered with [atexit] or [on_exit].
// This function actually terminates the process by raising a [SIGABRT] signal,
// and your program can include a handler to interrupt this signal;

/*

$ ./a.out
signal_callback, Abort trap: 6
[1]    85681 abort      ./a.out

*/

void signal_callback(int signum)
{
	printf("signal_callback, %s\n", strsignal(signum));
}

void abort_usage(void)
{
	signal(SIGABRT, signal_callback);
	abort();		// raise a [SIGABRT] signal;
}

int main(void)
{
	abort_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Aborting-a-Program.html#Aborting-a-Program
