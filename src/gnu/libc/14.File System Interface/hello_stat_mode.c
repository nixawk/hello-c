#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// The file mode, stored in the st_mode field of the file attributes, contains
// two kinds of information: the file type code, and the access permission bits.
// This section discusses only the type code, which you can use to tell whether
// the file is a directory, socket, symbolic link, and so on.

void stat_usage(void)
{
	struct stat buf;

	if (0 != stat("/etc/passwd", &buf)) {
		fprintf(stderr, "stat() failed: %s.\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (S_ISDIR(buf.st_mode)) {
		printf("It is a directiry.\n");
	}

	if (S_ISCHR(buf.st_mode)) {
		printf("It is a character special file.\n");
	}

	if (S_ISBLK(buf.st_mode)) {
		printf("It is a block special file.\n");
	}

	if (S_ISREG(buf.st_mode)) {
		printf("It is a regular file.\n");
	}

	if (S_ISFIFO(buf.st_mode)) {
		printf("It is a FIFO special file.\n");
	}

	if (S_ISLNK(buf.st_mode)) {
		printf("It is a symbolic link.\n");
	}

	if (S_ISSOCK(buf.st_mode)) {
		printf("It is a socket.\n");
	}

	printf("file type code: %d\n", S_IFMT);
}

int main(void)
{
	stat_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Reading-Attributes.html#Reading-Attributes
// https://www.gnu.org/software/libc/manual/html_node/Attribute-Meanings.html#Attribute-Meanings
// https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html#Permission-Bits
// https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html#Testing-File-Type
