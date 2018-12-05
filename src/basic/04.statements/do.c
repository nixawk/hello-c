#include <stdio.h>

int main(void)
{
	int i = 0;

	do {
		printf("%d ", i);
		i++;
	} while (i < 5);
	printf("\n");
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/do */
/* https://en.cppreference.com/w/c/language/do */
