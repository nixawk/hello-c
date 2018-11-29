#include <stdio.h>
#include <stdlib.h>

// Function: int sprintf (char *s, const char *template, …)
// Function: int snprintf (char *s, size_t size, const char *template, …)

/* Construct a message describing the value of a variable
   whose name is name and whose value is value. */
char *make_message(char *name, char *value)
{
	/* Guess we need no more than 100 chars of space. */
	int size = 100;
	char *buffer = (char *)malloc(size);
	int nchars;

	if (buffer == NULL)
		return NULL;

	/* Try to print in the allocated space. */
	nchars = snprintf(buffer, size, "value of %s is %s", name, value);
	if (nchars >= size) {
		/* Reallocate buffer now that we know
		   how much space is needed. */
		size = nchars + 1;
		buffer = (char *)realloc(buffer, size);

		if (buffer != NULL)
			/* Try again. */
			snprintf(buffer, size, "value of %s is %s",
				 name, value);
	}
	/* The last call worked, return the string. */
	return buffer;
}

int main(void)
{
	char *buffer;

	buffer = make_message("name", "smith keen");
	printf("%s\n", buffer);

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Formatted-Output-Functions
