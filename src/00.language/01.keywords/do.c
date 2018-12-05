#include <stdio.h>

void keyword_do(void)
{
	int i = 0;

	do {
		printf("%d ", i);
		i++;
	} while (i < 5);
	printf("\n");
}

int main(void)
{
	keyword_do();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/do */
