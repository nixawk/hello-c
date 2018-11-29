#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>

    // void perror (const char *message)

// This function prints an error message to the stream [stderr]; The orientation of
// [stderr] is not changed.

// If you call [perror] with a message that is either a null pointer or an empty string,
// [perror] just prints the error message corresponding to [errno], adding a trailling
// newline.

// If you supply a non-null message argument, then [perror] prefixs its output with this
// string, It adds a colon and a space character to separate the [message] from the error
// string corresponding to [errno].

// The function [perror] is declared in stdio.h.

void perror_usage(void)
{
	errno = 1;
	perror(NULL);
	perror("xxxx");
}

int main(void)
{
	perror_usage();
	return 0;
}

/*

$ ./hello_perror
Operation not permitted
xxxx: Operation not permitted

*/

// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages
