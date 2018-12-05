#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int isalpha (int c)

void isalpha_usage(void)
{
	char string[] = "hello, world";
	int i;

	for (i = 0; i < strlen(string); i++) {
		if (isalpha(string[i])) {
			printf("[+] [%c] is a alpha letter.\n", string[i]);
		} else {
			printf("[-] [%c] is not a alpha letter.\n", string[i]);
		}
	}
}

int main(void)
{
	isalpha_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
