#include <stdio.h>
#include <stdlib.h>

// Function: FILE * freopen (const char *filename, const char *opentype, FILE *stream)

#define BUF_SIZE 4096

void freopen_read_and_write(char *src, char *dst)
{
	FILE *instream;		/* combines file with stdin */
	FILE *outstream;	/* combines file with stdout */
	size_t nread;		/* count of read */
	char buf[BUF_SIZE];	/* read buffer */

	/* freopen() open a input stream */

	instream = freopen(src, "r", stdin);
	if (instream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	/* freopen() open a output stream */

	outstream = freopen(dst, "w", stdout);
	if (outstream == NULL) {
		perror("fwrite");
		exit(EXIT_FAILURE);
	}

	/* read data from instream */

	while (!feof(instream)) {
		nread = fread(buf, BUF_SIZE, 1, instream);

		/* write data into outstream */

		printf("%s", buf);
	}

	/* close FILE stream, and avoid memory leak */

	if (fclose(instream) != 0) {
		perror("fclose");
		exit(EXIT_FAILURE);
	}

	if (fclose(outstream) != 0) {
		perror("fclose");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("[*] Usage: %s <file-in> <file-out>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	freopen_read_and_write("in.txt", "out.txt");

	exit(EXIT_SUCCESS);
}

// https://stackoverflow.com/questions/1908687/how-to-redirect-the-output-back-to-the-screen-after-freopenout-txt-a-stdo
