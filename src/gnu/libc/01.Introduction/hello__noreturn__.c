#include <stdio.h>
#include <stdlib.h>

// noreturn

// A few standard library functions, such as abort and exit, cannot return.
// GCC knows this automatically. Some programs define their own functions
// that never return. You can declare them noreturn to tell the compiler
// this fact.


void fatal() __attribute__((noreturn));

// The noreturn keyword tells the compiler to assume that fatal cannot return.
// It can then optimize without regard to what would happen if fatal ever did
// return. This makes slightly better code. More importantly, it helps avoid
// spurious warnings of uninitialized variables.

// The nonreturn keyword does not affect the exceptional path when that applies:
// a nonreturn-marked function may still return to the caller by throwing an
// exception or calling longjmp.

void
fatal()
{
	printf("This is a noreturn function !\n");
	exit(1);
}

int
main(void)
{
	fatal();
	return 0;
}

// https://gcc.gnu.org/onlinedocs/gcc-4.7.2/gcc/Function-Attributes.html
