#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int isspace (int c)

// Returns true if c is a whitespace character. In the standard "C" locale, isspace returns true for only the standard whitespace characters:

// ' '  - space
// '\f' - formfeed
// '\n' - newline
// '\r' - carriage return
// '\t' - horizontal tab
// '\v' - vertical tab

void isspace_usage(void)
{
	char string[] = " \tA";
	int i;

	for (i = 0; i < strlen(string); i++) {
		if (isspace(string[i])) {
			printf("[%c] is a whitespace character\n", string[i]);
		} else {
			printf("[%c] is not a whitespace character\n",
			       string[i]);
		}
	}
}

int main(void)
{
	isspace_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
