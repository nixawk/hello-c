// External Storage Class

// The extern specifier gives the declared variable external storage class.
// The principal use of extern is to specify that a variable is declared
// with external linkage elsewhere in the program.

// When extern specifier is used with a variable declaration then no
// storage is allocated to that variable and it is assumed that the
// variable has already been defined elsewhere in the program.

#include <stdio.h>

extern int i;

void storage_class_extern(void)
{
	// When we use extern specifier the variable cannot be
	// initialize because with extern specifier variable is
	// declared, not defined.

	printf("i = %d\n", i);

}

int main(void)
{
	storage_class_extern();

	return 0;
}

int i = 10;

/*

$ ./a.out
i = 10

*/

// http://cs-fundamentals.com/c-programming/storage-classes-in-c-and-storage-class-specifiers.php
