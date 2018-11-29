#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int isalnum (int c);

// Returns true if c is an alphanumeric character (a letter or number);
// in other words, if either isalpha or isdigit is true of a character, then isalnum is also true.

void isalnum_usage(void)
{
	char string[] = "a1-B2";
	int i;

	for (i = 0; i < strlen(string); i++) {
		if (isalnum(string[i])) {
			printf("[+] [%c] is an alphanumeric character\n",
			       string[i]);
		} else {
			printf("[-] [%c] is not an alphanumeric character\n",
			       string[i]);
		}
	}
}

int main(void)
{
	isalnum_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
