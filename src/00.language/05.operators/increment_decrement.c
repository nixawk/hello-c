#include <stdio.h>

void increment_decrement(void)
{
	int a;

	a = 1;
	++a;
	--a;
	a++;
	a--;

	a = 1;
	printf("a++ : %d\n", a++);	/* output: 1 */

	a = 1;
	printf("++a : %d\n", ++a);	/* output: 2 */
}

int main(void)
{
	increment_decrement();
	return 0;
}

/* https://en.cppreference.com/w/c/language/expressions#Constants_and_literals */
