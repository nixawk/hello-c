#include <stdio.h>

void keyword_continue(void)
{
	for (int i = 0; i < 15; i++) {
		if (i % 2 == 0)
			continue;
		printf("%d ", i);
	}
	printf("\n");
}

int main(void)
{
	keyword_continue();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/continue */
