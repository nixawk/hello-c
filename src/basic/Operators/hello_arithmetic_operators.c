// Arithmetic operators

#include <stdio.h>

void arithmetic_operators(void)
{
	int i = 2;		/* basic assignment */
	int j = 2;		/* basic assignment */

	printf("i + j = %d\n", i + j);	/* addition */
	printf("i - j = %d\n", i - j);	/* subtraction */
	printf("i * j = %d\n", i * j);	/* multiplication */
	printf("i / j = %d\n", i / j);	/* division */
	printf("i %% j = %d\n", i % j);	/* modulo */

	printf("i++ : %d\n", i++);	/* increment */
	printf("++j : %d\n", ++j);

	printf("i-- : %d\n", i--);	/* decrement */
	printf("--j : %d\n", --j);
}

int main(void)
{
	arithmetic_operators();
	return 0;
}

/*

$ ./a.out
i + j = 4
i - j = 0
i * j = 4
i / j = 1
i % j = 0
i++ : 2
++j : 3
i-- : 3
--j : 2

*/

// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
