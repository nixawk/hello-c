#include <stdio.h>

/*
void pointer:
    A void pointer is a pointer that has no associated data type with it.
    A void pointer can hold address of any type and can be typcasted to any type.
*/

int main(void)
{
	int x = 1234;
	void *p = &x;
	int *intptr = (int *)p;	/* typecast */

	printf("%p\n", intptr);
	return 0;
}

// http://www.geeksforgeeks.org/void-pointer-c/
// http://stackoverflow.com/questions/20967868/should-the-compiler-warn-on-pointer-arithmetic-with-a-void-pointer
// http://stackoverflow.com/questions/692564/concept-of-void-pointer-in-c-programming
