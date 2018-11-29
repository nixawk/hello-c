#include <stdio.h>

void inplace_swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

int main(void)
{
	int x = 1, y = 2;

	printf("x = %d, y = %d\n", x, y);
	inplace_swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}

// Computer Systems: A Programmer's Perspective, 3/E (CS:APP3e). Part 2.1.7
