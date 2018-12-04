/*
 * Every object in C exists, has a constant address, retains its last-stored
 * value (except when the value is indeterminate), and, for VLA, retains its
 * size over a portion of program execution known as this object's lifetime.
 *
 * For the objects that are declared with automatic, static, and thread storage
 * duration, lifetime equals their storage duration (note the different between
 * non-VLA and VLA automatic storage duration).
 *
 * For the objects with allocated storage duration, the lifetime begins when
 * the allocation function returns (including the return from realloc) and ends
 * when the realloc function is called.
 * */

#include <stdio.h>

int main(void)
{
	int a = 10;		/* a has automatic storage duration */

	printf("a = %d\n", a);
	return 0;
}				/* lifetime of a ends */

/* https://en.cppreference.com/w/c/language/lifetime */
