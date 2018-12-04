/* register is ued to define local variables that should be stored in a
 * register instead of RAM. This means that the variable has a maximum
 * size qeual to the register size (usually one word) and cant have
 * the unary '&' operator applied to it (as it does not have a memory
 * location) */

#include <stdio.h>

int main(void)
{
	register int n;

	for (int i = 10000; i < 100000000; i++) {
		n += i;
	}
	printf("n = %d\n", n);
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/register */
