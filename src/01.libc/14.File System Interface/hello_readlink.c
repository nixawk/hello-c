#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

// ssize_t readlink (const char *filename, char *buffer, size_t size)

// The [readlink] function gets the value of the symbolic link filename.
// The file name that the link points to is copied into buffer. This file
// name string is not null-terminated; [readlink] normally returns the
// number of characters copied. The [size] argument specifies the
// maximum number of characters to copy, usually the allocation size of
// buffer.

// A value of -1 is returned in case of error.

#define SYMLINK "/tmp/symlink"

char *readlink_malloc(const char *filename)
{
	int size = 100;
	char *buffer = NULL;

	while (1) {
		buffer = (char *)realloc(buffer, size);
		int nchars = readlink(filename, buffer, size);
		if (nchars < 0) {
			free(buffer);
			return NULL;
		}

		if (nchars < size) {
			return buffer;
		}

		size *= 2;
	}
}

void readlink_usage(void)
{
	char *buffer = readlink_malloc(SYMLINK);
	if (buffer == NULL) {
		fprintf(stderr, "readlink_malloc() failed: %s\n",
			strerror(errno));
	}
	printf("symlink filename: %s\n", buffer);
}

int main(void)
{
	readlink_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Symbolic-Links.html#Symbolic-Links
