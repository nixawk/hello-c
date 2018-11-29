#include <err.h>

    // void warn (const char *format, …)

// The warn function is roughly equivalent to a call like

    //  error (0, errno, format, the parameters)

// except that the global variables error respects and modifies are not used.

void warn_usage(void)
{
	warn("this is a warn message");
	warn("this is another warn message");
}

int main(void)
{
	warn_usage();
	return 0;
}

/*
$ ./a.out
a.out: this is a warn message: Undefined error: 0
a.out: this is another warn message: Undefined error: 0
*/

// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages
