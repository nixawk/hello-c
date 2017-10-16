#define _GNU_SOURCE
#include <errno.h>
#include <string.h>
#include <stdio.h>

// The library has functions and variables designed to make it easy for your program
// to report information error messages in the customary format about the failure of
// a library call. The functions [strerror] and [perror] give you the standard error
// message for a given error code; the variable [program_invocation_short_name] gives
// you convenient access to the name of the program that encountered the error.

    // char * strerror (int errnum)

// The [strerror] function maps the error code specified by the [errnum] argument
// to a descriptive error message string. The return value is a pointer to this
// string.

// The value [errnum] normally comes from the variable [errno].
// You should not modify the string returned by [strerror]. Also, if you make subsequent
// calls to [strerror], the string might be overwritten.

// The function [strerror] is declared in [string.h]


void
strerror_usage(void)
{
    errno = 1;  // raise an error status

    // printf("program name: %s\n", program_invocation_short_name);  // #define _GNU_SOURCE
    // printf("program err : %s\n", strerror(errno));                // errno is global.

    // 4.4 Formatting Error Messages
    printf("%s:%d:%s:%s", __FILE__, __LINE__, __FUNCTION__, strerror(errno));
}


int main(void)
{
    strerror_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages
// https://linux.die.net/man/3/program_invocation_short_name
// https://www.gnu.org/prep/standards/standards.html#Errors