// The system starts a C program by calling the function [main].
// It is up to you to write a function named [main] - otherwise, you won't
// even be able to link your program without errors.

// In ISO C you can define [main] either to take no arguments, or to take two arguments that
// represent the command line arguments to the program, like this:

    // int main(int argc, char *argv[])

// The value of the [argc] argument is the number of command line arguments.
// The argv argument is a vector of C strings; its elements are the individual command line
// argument strings. The file name of the program being run is also include in the vector as
// the first element; the value of [argc] counts this element.
// A null pointer always follows the last element: argv[argc] is this null pointer.

// In Unix systems you can define [main] a third way, using three arguments:

    // int main(int argc, char *argv[], char *envp[])

// The first two arguments are just the same.
// The third argument [envp] gives the program's environment; it is the same as the value of
// [environ]. 

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc: %d\n", argc);
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html#Program-Arguments
