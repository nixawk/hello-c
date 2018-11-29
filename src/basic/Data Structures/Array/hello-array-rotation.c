// Program for array rotation

#include <stdio.h>

void leftrotation_one(int[], int);
void leftrotation(int[], int, int);
void rightrotation_one(int[], int);
void rightrotation(int[], int, int);
void printarray(int[], int);

void leftrotation_one(int arylst[], int arylen)
{
	int i, temp;

	temp = arylst[0];
	for (i = 0; i < arylen - 1; i++) {
		arylst[i] = arylst[i + 1];
	}
	arylst[i] = temp;
}

void leftrotation(int arylst[], int arylen, int index)
{
	int i;

	for (i = 0; i < index; i++) {
		leftrotation_one(arylst, arylen);
	}
}

void rightrotation_one(int arylst[], int arylen)
{
	int i, temp;

	temp = arylst[arylen - 1];
	for (i = arylen; i > 0; i--) {
		arylst[i] = arylst[i - 1];
	}
	arylst[0] = temp;
}

void rightrotation(int arylst[], int arylen, int index)
{
	int i;

	for (i = 0; i < index; i++) {
		rightrotation_one(arylst, arylen);
	}
}

void printarray(int arylst[], int arylen)
{
	int i;

	for (i = 0; i < arylen; i++) {
		printf(" %d ", arylst[i]);
	}
	printf("\n");
}

int main(int argc, const char *argv[])
{
	int arylst[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arylen = sizeof(arylst) / sizeof(*arylst);

	printf("original array    : ");
	printarray(arylst, arylen);

	printf("left  rotation(2) : ");
	leftrotation(arylst, arylen, 2);
	printarray(arylst, arylen);

	printf("right rotation(2) : ");
	rightrotation(arylst, arylen, 2);
	printarray(arylst, arylen);

	return 0;
}

// https://www.geeksforgeeks.org/array-rotation/
