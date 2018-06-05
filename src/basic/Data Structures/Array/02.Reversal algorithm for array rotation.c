// Reversal algorithm for array rotation

#include <stdio.h>

void swap(int*, int*);
void reverse(int[], int, int);
void leftrotation(int[], int, int);
void rightrotation(int [], int, int);
void printarray(int[], int);


void
swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void
reverse(int arylst[], int start, int end)
{
    while (start < end)
    {
        swap(&arylst[start], &arylst[end]);

        start++;
        end--;
    }
}

void
leftrotation(int arylst[], int arylen, int index)
{
    reverse(arylst, 0, index-1);
    reverse(arylst, index, arylen-1);
    reverse(arylst, 0, arylen-1);
}

void
rightrotation(int arylst[], int arylen, int index)
{
    reverse(arylst, 0, arylen - index - 1);
    reverse(arylst, arylen - index, arylen - 1);
    reverse(arylst, 0, arylen - 1);
}

void
printarray(int arylst[], int arylen)
{
    int i;

    for (i = 0; i < arylen; i++)
    {
        printf(" %d ", arylst[i]);
    }
    printf("\n");
}

int
main(int argc, const char *argv[])
{
    int arylst[] = {1, 2, 3, 4, 5, 6, 7};
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

/*

$ ./a.out
original array    :  1  2  3  4  5  6  7
left  rotation(2) :  3  4  5  6  7  1  2
right rotation(2) :  1  2  3  4  5  6  7

*/

// https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
