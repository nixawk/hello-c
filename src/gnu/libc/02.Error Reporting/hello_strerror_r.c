#include <string.h>
#include <errno.h>
#include <stdio.h>

    // char * strerror_r (int errnum, char *buf, size t n)

// The [strerror_r] function works like [strerror] but instead of returning
// the error message in a statically allocated buffer shared by all threads
// in the process, it returns a private copy for the thread. This might be
// either some permanent global data or a message string in the user supplied
// buffer starting at buf with the length of n bytes. At most n characters
// are written (including the NUL byte) so it is up to the user to select
// a buffer large enough.

// This function should always be used in multi-threaded programs since
// there is no way to guarantee the string returned by [strerror] really
// belongs to the last call of the current thread.

// The function [strerror_r] is a [GNU] extension and it is declared in
// string.h

#define BUFFSIZE    512

void strerror_r_usage(void)
{
	char buf[BUFFSIZE] = { 0 };

	errno = 1;
	strerror_r(errno, buf, BUFFSIZE);
	fprintf(stderr, "errno: %d, %s\n", errno, buf);
}

int main(void)
{
	strerror_r_usage();
	return 0;
}

/*
$ ./hello_strerror_r
errno: 1, Operation not permitted
*/

// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages
