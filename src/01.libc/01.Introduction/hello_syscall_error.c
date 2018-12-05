#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

/*

When a system call fails, it sets the global integer variable errno
to a positive value that identifies the specific error. Including
the <errno.h> header file provides a declaration of errno, as well
as a set of constants for the various error numbers. All of these
sysbolic names commence with E. The section headed ERRORS in each
manual page provides a list of possible errno values that can be
returned by each system call.

Successful system calls and library functions never reset errno to 0,
so this variable may have a nonzero value as a consequence of an error
from a previous call. Further more, SUSv3 permits a successful function
call to set errno to a nonzero value (although few functions do this).
Therefore, when checking for an error, we should always first check if
the function return value indicates an error, and only then examine
errno to determine the cause of the error.

*/

void syscall_error(void)
{
	syscall(__NR_access, "invalid-file-path", R_OK);
	printf("errno = %d\n", errno);
	perror("syscall_error");
}

int main(void)
{
	syscall_error();
	return 0;
}

/*

Error(s):
syscall_error: No such file or directory
errno = 2

*/
