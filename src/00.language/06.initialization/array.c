#include <stdio.h>

int main(void)
{
	int l[] = { 0, 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < sizeof(l) / sizeof(*l); i++) {
		printf("%d ", l[i]);
	}
	printf("\n");
	return 0;
}

/* https://en.cppreference.com/w/c/language/array_initialization */
