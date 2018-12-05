#include <unistd.h>
#include <stdio.h>

// int ttyname_r (int filedes, char *buf, size_t len)

// The ttyname_r function is similar to the ttyname function except that it
// places its result into the user-specified buffer starting at buf with
// length len.

// The normal return value from ttyname_r is 0. Otherwise an error number
// is returned to indicate the error. The following errno conditions are
// defined for this function:

    // EBADF  - The filedes argument is not a valid file descriptor.
    // ENOTTY - The filedes is not associated with a terminal.
    // ERANGE - The buffer length len is too small to store the string to be returned.

#define SIZE 1024

void ttyname_r_usage(void)
{
	char buf[SIZE] = { '\0' };
	int filedes = 0;

	if ((ttyname_r(filedes, buf, SIZE)) == 0) {
		printf("fd: %d, ttyname: %s\n", filedes, buf);
	}
}

int main(void)
{
	ttyname_r_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Is-It-a-Terminal.html#Is-It-a-Terminal
