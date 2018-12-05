#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

// Function: size_t strftime (char *s, size_t size, const char *template, const struct tm *brokentime)

// If s is a null pointer, strfttime does not actually write anything,
// but instead returns the number of characters it would have written.

// The size parameter can be used to specify the maximum number of characters
// to be stored in the array s, including the terminating null character.
// If the formatted time requires more than size characters, strftime returns
// zero and the contents of the array s are undefined. Otherwise the return
// value indicates the number of characters placed in the array s, not
// including the terminating null character.

void strftime_usage(void)
{
	char buf[SIZE];
	struct tm *tm;
	time_t time = 1514366148;

	tm = localtime(&time);
	if (tm == NULL) {
		fprintf(stderr, "localtime() failed\n");
		exit(EXIT_FAILURE);
	}

	if (strftime(buf, SIZE, "%Y-%m-%d %H:%M:%S%z", tm) != (size_t) 0) {
		printf("Date: %s\n", buf);
	}
}

int main(void)
{
	strftime_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Formatting-Calendar-Time.html#Formatting-Calendar-Time
