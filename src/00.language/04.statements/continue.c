#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 15; i++) {
		if (i % 2 == 0)
			continue;
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/continue */
/* https://en.cppreference.com/w/c/language/continue */
