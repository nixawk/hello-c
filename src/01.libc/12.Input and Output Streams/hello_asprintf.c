#define _GNU_SOURCE
#include <stdio.h>

char *make_message(char *name, char *value)
{
	char *result;
	if (asprintf(&result, "value of %s is %s", name, value) < 0)
		return NULL;
	return result;
}

int main(void)
{
	char *buffer;

	buffer = make_message("name", "smith keen");
	printf("%s", buffer);

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Formatted-Output-Functions
// http://man7.org/linux/man-pages/man3/asprintf.3.html
