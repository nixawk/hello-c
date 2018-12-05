#include <stdio.h>
#include <errno.h>
#include <string.h>

// Error Reporting

// Many functions in the GNU C Library detect and report error conditions,
// and sometimes your programs need to check for these error conditions.

// Many library functions return a sepcial value to indicate that they have failed.
// To find out what kind of error it was, you need to look at the error code stored
// in the variable errno.

// This variable is declared in the header file [errno.h]

    /* volatile int errno */

    // The variable [errno] is declared [volatile], it might be changed asynchronously
    // by a signal handler; However, a properly written signal handler saves and
    // restores the value of [errno], so you generally do not need to worry about
    // this possibility except when writing signal handlers.

    // The initial value of [errno] at program startup is zero. Many library functions
    // are guaranteed to set it to certain nonzero values when they encounter certain
    // kinds of errors. These error conditions are listed for each function. These
    // function do not change [errno] when they succeed; thus, the value of [errno]
    // after a successful call is not necessarily zero; and you should not use [errno]
    // to determine whether a call failed. The proper way to do that is documented for
    // each function. If the call failed, you can examine [errno].

void errno_print(int err)
{
	fprintf(stderr, "errno: %d, %s\n", err, strerror(err));
}

void errno_usage(void)
{
	errno_print(errno);	// default errno is 0
	errno_print(EPERM);
	errno_print(ENOENT);
	errno_print(ESRCH);
	errno_print(EINTR);
	errno_print(0xFF);	// errmsg for an unknown error code
}

int main(void)
{
	errno_usage();
	return 0;
}

/*

$ ./hello_errno

errno: 0, Undefined error: 0
errno: 1, Operation not permitted
errno: 2, No such file or directory
errno: 3, No such process
errno: 4, Interrupted system call
errno: 255, Unknown error: 255

*/

// https://www.gnu.org/software/libc/manual/html_node/Error-Reporting.html#Error-Reporting
// https://www.gnu.org/software/libc/manual/html_node/Checking-for-Errors.html#Checking-for-Errors
// https://www.gnu.org/software/libc/manual/html_node/Error-Codes.html#Error-Codes
// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages
