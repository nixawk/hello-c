/*
 * C programs create, destroy, access, and manipulate objects.
 *
 * An object, in C, is region of data storage in the execution environment, the
 * contents of which can represent values (a value is the meaning of the 
 * content of an object, when interpreted as having a specific type).
 *
 * Every object has
 *
 *  - size (can be determined with sizeof)
 *  - alignment requirement (can be determined by alignof)
 *  - storage duration (automatic, static, allocated, thread-local)
 *  - lifetime (equal to storage duration or temporary)
 *  - effective type
 *  - value (which may be indeterminate)
 *  - optionally, an identifier that denotes this object
 */

/* gcc -Wall -std=c11 07.object.c */

#include <stdio.h>

int main(void)
{
	struct {		/* my_struct - lifetime start */
		int x;
		char c;
		int y;
	} my_struct;

	printf("sizeof(my_struct) = %ld\n", sizeof(my_struct));
	return 0;
}				/* my_struct - lifetime end */

/* https://en.cppreference.com/w/c/language/object */
