#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// int access (const char *filename, int how)

// The [access] function checks to see whether the file named by [filename]
// can be accessed in the way specified by the [how] argument. The [how]
// argument either can be the bitwise OR of the flags:

    // R_OK - Flag meaning test for read permission
    // W_OK - Flag meaning test for write permission
    // X_OK - Flag meaning test for execute/search permission
    // F_OK - Flag meaning test for existence of the file

// This function uses the real user and group IDs of the calling process,
// rather than the effective IDs, to check for the access permission.
// As a result, if you use the functiob from a [setuid] or [setgid] program,
// it gives information relative to the user who actually ran the program.

// The return value is 0 if the access is permitted, and -1 otherwise.

void access_usage(void)
{
	if (access("/etc/passwd", R_OK | W_OK | X_OK) != 0) {
		fprintf(stderr, "access() failed: %s\n", strerror(errno));
		exit(0);
	}
}

int main(void)
{
	access_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Testing-File-Access.html
