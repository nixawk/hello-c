// Program to cyclically rotate an array by one

#include <stdio.h>

void
rotate(int arylst[], int n)
{
	int x, i;

	x = arylst[n-1];
	for (i = n-1;i > 0;i--)
	{
		arylst[i] = arylst[i-1];
	}
	arylst[0] = x;
}

int
main(void)
{
	int arylst[] = {1, 2, 3, 4, 5};
	int n = sizeof(arylst) / sizeof(*arylst);
	int i;

	printf("Given array is\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arylst[i]);
	}

	rotate(arylst, n);

	printf("\nRotated array is\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arylst[i]);
	}
	printf("\n");

	return 0;
}

// https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/
