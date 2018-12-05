#include <stdio.h>
#include <stdlib.h>

void getline_usage(const char *filename)
{
	FILE *stream = NULL;
	char *lineptr = NULL;
	size_t n;
	ssize_t nread;

	stream = fopen(filename, "r");
	if (stream == NULL) {
		printf("failed to fopen %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&lineptr, &n, stream)) != -1) {
		printf("nread: %04ld, str: %s", nread, lineptr);
	}

	if (fclose(stream) != 0) {
		printf("failed to fclose %s\n", filename);
		exit(EXIT_FAILURE);
	}

	if (lineptr)
		free(lineptr);
	exit(EXIT_SUCCESS);
}

int main(int argc, const char *argv[])
{
	int i;

	if (argc < 2) {
		printf("Usage: %s <file1> <file2> ...\n", argv[0]);
		return -1;
	}

	for (i = 1; i < argc; i++) {
		getline_usage(argv[i]);
	}

	return 0;
}

// https://dev.w3.org/libwww/Library/src/vms/getline.c
// https://opensource.apple.com/source/cvs/cvs-19/cvs/lib/getline.c
// https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
