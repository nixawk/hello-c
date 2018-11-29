// Bitwise operators

#include <stdio.h>

void bitwise_operators(void)
{
	int i = 1;
	int j = 2;

	printf("i = %d, j = %d\n", i, j);
	printf("~i = %d\n", ~i);	/* bitwise NOT */
	printf("i & j = %d\n", i & j);	/* bitwise AND */
	printf("i | j = %d\n", i | j);	/* bitwise OR */
	printf("i ^ j = %d\n", i ^ j);	/* bitwise XOR */
	printf("i << j = %d\n", i << j);	/* bitwise left shift */
	printf("i >> j = %d\n", i >> j);	/* bitwise right shift */
}

int main(void)
{
	bitwise_operators();
	return 0;
}

/*

$ ./a.out
i = 1, j = 2
~i = -2
i & j = 0
i | j = 3
i ^ j = 3
i << j = 4
i >> j = 0

*/

// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Arithmetic_operators
