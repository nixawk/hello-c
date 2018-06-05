#include <stdio.h>

void swap(int*, int*);
void sort_ltob(int[], int);
void sort_btol(int[], int);
void printarray(int [], int);


// Swap double integers with each other
void
swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// Sort all integers in array from little to big
void
sort_ltob(int arylst[], int arylen)
{

    int i, j;

    for (i = 0; i < arylen; i++)
    {
        for (j = i + 1; j < arylen; j++)
        {
            if (arylst[i] > arylst[j])
            {
                swap(&arylst[i], &arylst[j]);
            }
        }
    }
}

// Sort all integers in array from big to little
void
sort_btol(int arylst[], int arylen)
{

    int i, j;

    for (i = 0; i < arylen; i++)
    {
        for (j = i + 1; j < arylen; j++)
        {
            if (arylst[i] < arylst[j])
            {
                swap(&arylst[i], &arylst[j]);
            }
        }
    }
}

// Print all integers in array
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

// Main function - program entry
int
main(void)
{
    int arylst[] = {2, 3, 1, 5, 4, 8, 9, 6, 4, 7};
    int arylen = sizeof(arylst) / sizeof(*arylst);

    printarray(arylst, arylen);
    sort_ltob(arylst, arylen);    // sort int array from little to big
    printarray(arylst, arylen);    
    sort_btol(arylst, arylen);    // sort int array from big to little
    printarray(arylst, arylen);

    return 0;
}

/*

$ ./a.out
 2  3  1  5  4  8  9  6  4  7
 1  2  3  4  4  5  6  7  8  9

*/
