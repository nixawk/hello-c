#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

// int __freadable (FILE *stream)

// The __freadable function determines whether the stream stream was opened to allow reading.
// In this case the return value is nonzero. For write-only streams the function returns zero.

// int __fwritable (FILE *stream)

// The __fwritable function determines whether the stream stream was opened to allow writing.
// In this case the return value is nonzero. For read-only streams the function returns zero.

// int __freading (FILE *stream)

// The __freading function determines whether the stream stream was last read from or whether
// it is opened read-only. In this case the return value is nonzero, otherwise it is zero. 
// Determining whether a stream opened for reading and writing was last used for writing 
// allows to draw conclusions about the content about the buffer, among other things.

// int __fwriting (FILE *stream)

// The __fwriting function determines whether the stream stream was last written to or whether 
// it is opened write-only. In this case the return value is nonzero, otherwise it is zero.

void __fwritable_usage(void)
{
	FILE *fp;
	char *fn = "/tmp/testfile";

	fp = fopen(fn, "w");
	if (fp == NULL) {
		printf("fopen() failed\n");
		exit(0);
	}

	if (__fwritable(fp)) {
		printf("[%s] is writable\n", fn);
	} else {
		printf("[%s] is not writable\n", fn);
	}

	fclose(fp);
}

int main(void)
{
	__fwritable_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Opening-Streams.html#Opening-Streams
