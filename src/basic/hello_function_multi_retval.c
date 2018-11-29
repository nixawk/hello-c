#include <stdio.h>

/* A function in C can return only one value.
   How to return multiple values from a function ? */
struct newtype {
	int x;
	int y;
};

/* return multiple values from a function */
struct newtype demo(int x, int y)
{
	struct newtype st = { x, y };
	return st;
}

int main(void)
{
	struct newtype st = demo(1, 2);
	printf("x = %d, y = %d\n", st.x, st.y);
	return 0;
}

/* If we want the function to return multiple values of same data types,
  the pointer can be a good choice. */

// http://www.geeksforgeeks.org/how-can-i-return-multiple-values-from-a-function/
