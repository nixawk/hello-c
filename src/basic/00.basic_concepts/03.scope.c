/*
 * Each identifier that appears in a C program is visible (that is, * may be 
 * used) only in some possibly discontigous portion of the source code called
 * it scope.
 *
 * C has four kinds of scopes:
 *     * block scope
 *     * file scope
 *     * function scope
 *     * function prototype scope
 *
 * */

#include <stdio.h>		/* file scope start */

int main(void)
{				/* function scope start */
	int i;

	for (i = 1; i < 10; i++) {	/* block scope start */
		printf("%d ", i);
	}
	printf("\n");		/* block scope end */
	return 0;
}				/* function scope end */

/* file scope end */

/* https://en.cppreference.com/w/c/language/scope */
