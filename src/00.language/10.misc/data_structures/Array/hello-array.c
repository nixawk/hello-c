// Introduction to Arrays

// An array is collection of items stored at continuous memory locations.
// The idea is store multiple items of same type together. This makes it
// easier to calculate the position of each element by simply adding an
// offset to a base value, i.e., the memory location of the first element
// of the array (generally denoted by the name of the array).

// Types of indexing in array:

// 0 (zero-based indexing): The first element of the array is indexed by
// subscript of 0

// 1 (one-based indexing): The first element of the array is indexed by
// subscript of 1

// n (n-based indexing): The base index of an array can be freely chosen.
// Usually programming languages allowing n-based indexing also allow
// negative index values and other scalar data types like enumerations,
// or characters may be used as an array index.

// Advantages of using arrays:

// 1. Arrays allow random access of elements. This makes accessing elements
//    by position faster.

// 2. Arrays have better cache locality that can make a pretty big different
//    in performance.

#include <stdio.h>

void printarray(int arylst[], int arylen)
{
	int i;

	for (i = 0; i < arylen; i++) {
		printf("%p - %d\n", &arylst[i], arylst[i]);
	}
}

int main(void)
{
	int arylst[] = { 0, 1, 2, 3, 4, 5 };

	printarray(arylst, sizeof(arylst) / sizeof(*arylst));
	return 0;
}

/*

$ ./a.out
0x7fff5edc3990 - 0
0x7fff5edc3994 - 1
0x7fff5edc3998 - 2
0x7fff5edc399c - 3
0x7fff5edc39a0 - 4
0x7fff5edc39a4 - 5

*/

//https://www.geeksforgeeks.org/introduction-to-arrays/
