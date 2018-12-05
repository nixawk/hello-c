#include <errno.h>
#include <error.h>
#include <stdlib.h>

// void error (int status, int errnum, const char *format, …)

// The [error] function can be used to report general problems during program execution.
// The [format] argument is a format string just like those given to the [printf] family
// of functions. The arguments required for the format can follow the format parameter.
// Just like [perror], [error] also can report an error code in textual form. But unlike
// [perror] the error value is explicitly passed to the function in the [errnum] parameter.
// This eliminates the problem mentioned above that the error reporting function must be
// called immediately after the function causing the error since otherwise [errno] might
// have a different value.

// [error] prints first the program name. If the application defined a global variable 
// error_print_progname and points it to a function this function will be called to 
// print the program name. Otherwise the string from the global variable program_name 
// is used. The program name is followed by a colon and a space which in turn is 
// followed by the output produced by the format string. If the errnum parameter is 
// non-zero the format string output is followed by a colon and a space, followed by 
// the error message for the error code errnum. In any case is the output terminated
// with a newline.

// The output is directed to the stderr stream. If the stderr wasn't oriented before
// the call it will be narrow-oriented afterwards.

// The function will return unless the status parameter has a non-zero value. In this
// case the function will call exit with the status value for its parameter and 
// therefore never return. If error returns, the global variable error_message_count
//  is incremented by one to keep track of the number of errors reported.

void error_usage(void)
{
	errno = 1;
	error(EXIT_FAILURE, errno, "errno: %d, %s", errno,
	      "custom error message");
}

int main(void)
{
	error_usage();
	return 0;
}

/*
$ ./hello_error
./hello_error: errno: 1, custom error message: Operation not permitted
*/

// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages
