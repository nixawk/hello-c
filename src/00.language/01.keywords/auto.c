#include <stdio.h>

void keyword_auto(void)
{
	auto int i;		/* auto is the default storage class for local variables */

	for (i = 0; i < 5; i++) {
		printf("auto int i = %d\n", i);
	}
}

int main(void)
{
	keyword_auto();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword */
/* https://en.cppreference.com/w/c/keyword/auto */
/* https://stackoverflow.com/questions/2192547/where-is-the-c-auto-keyword-used */
