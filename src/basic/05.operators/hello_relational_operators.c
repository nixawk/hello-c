// Comparison operators / Relational operators

#include <stdio.h>

void relational_operators(void)
{
	int i = 1;		/* basic assignment */
	int j = 2;		/* basic assignment */

	printf("i = %d, j = %d\n", i, j);

	(i == j) ? printf("i == j\n") : printf("i != j\n");
	(i != j) ? printf("i != j\n") : printf("i == j\n");
	(i > j) ? printf("i > j\n") : printf("i <= j\n");
	(i < j) ? printf("i < j\n") : printf("i >= j\n");
	(i >= j) ? printf("i >= j\n") : printf("i < j\n");
	(i <= j) ? printf("i <= j\n") : printf("i > j\n");
}

int main(void)
{
	relational_operators();
	return 0;
}

// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
