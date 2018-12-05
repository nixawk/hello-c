#include <ctype.h>
#include <stdio.h>

// int isupper (int c)

// Return true if c is an upper-case letter. The letter need not be from the Latin alphabet,
// any alphabet repersentable is valid.

void isupper_usage(void)
{
	char ch = 'A';

	if (isupper(ch)) {
		printf("[%c] is a upper-case letter\n", ch);
	}
}

int main(void)
{
	isupper_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Characters.html#Classification-of-Characters
// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
