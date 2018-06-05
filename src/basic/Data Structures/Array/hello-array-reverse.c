#include <stdio.h>

void swap(int*, int*);
void reverse(int[], int);


void
swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void
reverse(int arylst[], int arylen)
{
    int i;

    for (i = 0; i < arylen / 2; i++)
    {
        swap(&arylst[i], &arylst[arylen - 1 - i]);
    }
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
main(void)
{
    int arylst[] = {1, 2, 3, 4, 5};
    int arylen = sizeof(arylst) / sizeof(*arylst);

    printarray(arylst, arylen);  
    reverse(arylst, arylen);
    printarray(arylst, arylen);

    return 0;
}

/*

$ ./a.out
 1  2  3  4  5
 5  4  3  2  1

*/
