#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define PROGRAM_NAME "getopt"

void usage(int status)
{
	if (status != EXIT_SUCCESS) {
		fprintf(stderr, "Try `%s -h' for more information.\n",
			PROGRAM_NAME);
	} else {
		printf("Usage: %s [OPTION]... [FILE]...\n", PROGRAM_NAME);
		printf("\t-a, append to the given FILEs, do not overwrite\n\n");
	}
	exit(status);
}

int main(int argc, char *argv[])
{
	int opt;

	while ((opt = getopt(argc, argv, "a:h")) != -1) {
		switch (opt) {
		case 'a':
			printf("print: %s -a %s\n", PROGRAM_NAME, optarg);
			break;

		case 'h':
			usage(EXIT_SUCCESS);

		default:
			usage(EXIT_FAILURE);
		}
	}

	usage(EXIT_SUCCESS);
}

// http://man7.org/linux/man-pages/man3/getopt.3.html
// https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
