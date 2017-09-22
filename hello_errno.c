#include <stdio.h>
#include <errno.h>
#include <string.h>

// Error Reporting

// Many functions in the GNU C Library detect and report error conditions,
// and sometimes your programs need to check for these error conditions.


// Checking for Errors

// Many library functions return a sepcial value to indicate that they have failed.
// To find out what kind of error it was, you need to look at the error code stored
// in the variable errno.

// This variable is declared in the header file [errno.h]

/* volatile int errno */


// Error Codes


// Error Message
// char * strerror (int errnum)
// char * strerror_r (int errnum, char *buf, size_t n)


int main(void)
{
    // char *err = strerror(1);
    fprintf(stderr, "Value of errno: %d\n", EPERM);
    fprintf(stderr, "Error msg: %s", strerror(1));
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Error-Reporting.html#Error-Reporting
// https://www.gnu.org/software/libc/manual/html_node/Checking-for-Errors.html#Checking-for-Errors
// https://www.gnu.org/software/libc/manual/html_node/Error-Codes.html#Error-Codes
// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages