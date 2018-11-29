#include <stdio.h>
#include <errno.h>
#include <string.h>

// int unlink (const char *filename)
// int rmdir (const char *filename)
// int remove (const char *filename)

// This is the ISO C function to remove a file. It works like [unlink] for files
// and like [rmdir] for directories.

#define FILENAME "/tmp/deletefile"

void remove_usage(void)
{
	if (remove(FILENAME) != 0) {
		fprintf(stderr, "remove() failed: %s\n", strerror(errno));
	} else {
		printf("delete file: %s\n", FILENAME);
	}
}

int main(void)
{
	remove_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Deleting-Files.html#Deleting-Files
