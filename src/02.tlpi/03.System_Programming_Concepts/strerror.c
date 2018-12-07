/*
 * When a system call fails, it sets the global integer variable errno to a
 * positive value that identifies the specific error. Including the <errno.h>
 * header file provides a declaration of errno, as well as a set of constants
 * for the various error numbers.
 *
 * Successful system calls and library functions never reset errno to 0, so
 * this variable may have a nonzero value as a consequence of an error from
 * a previous call.
 *
 * A few system calls (e.g., getpriority()) can legitimately return -1 on
 * success.
 * */

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	printf("errno = %d\n", errno);
	errno = 1;
	printf("strerror(%d) = %s\n", errno, strerror(errno));
	return 0;
}
