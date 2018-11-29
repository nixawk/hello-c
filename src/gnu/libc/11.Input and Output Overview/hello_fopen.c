#include <stdio.h>
#include <stdlib.h>

// FILE * fopen (const char *filename, const char *opentype)
// FILE * fopen64 (const char *filename, const char *opentype)

// If the open fails, [fopen] returns a null pointer.

#define SIZE 512		/* heap memory size */

void file_write(char *, char *);
void file_read(char *);

void file_write(char *filename, char *data)
{
	FILE *fp = fopen(filename, "w");

	if (fp == NULL || data == NULL) {
		printf("file_write - failed to write data\n");
		exit(0);	/* exit() VS abort() */
	} else {
		fputs(data, fp);	/* no newline \n here */
		fclose(fp);
	}
}

void file_read(char *filename)
{
	FILE *fp = fopen(filename, "r");
	char *ptr = NULL;

	if (fp == NULL) {
		printf("file_read - failed to read data\n");
		exit(0);
	} else {
		ptr = (char *)calloc(SIZE, sizeof(char));	/* allocate heap buffer */

		if (ptr == NULL) {
			printf("file_read - failed to allocate buffer\n");
			exit(0);
		} else {
			while (!feof(fp)) {	/* end of file */
				fgets(ptr, SIZE, fp);	/* read byte by byte */
				fputs(ptr, stdout);	/* output to console */
			}
		}

		free(ptr);
		fclose(fp);
	}
}

int main(void)
{
	file_write("/tmp/test.log", "helloworld \n");
	file_read("/etc/passwd");

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Opening-Streams.html#Opening-Streams
// http://www.geeksforgeeks.org/fopen-for-an-existing-file-in-write-mode/
// http://www.geeksforgeeks.org/eof-and-feof-in-c/
// http://www.geeksforgeeks.org/g-fact-82/
