#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void new_pointer1(void)
{
    int *pointer = malloc(sizeof(*pointer));
    memset(pointer, '\x00', sizeof(int));

    printf("new_pointer1 - Please enter a number:\n ");
    scanf("%d", pointer);
    printf("number is : %d\n", *pointer);
    free(pointer);
}

void new_pointer2(void)
{
    int x;               /* A normal integer */
    int *p;              /* A pointer to an integer ("*p") is an integer, so p must be a pointer to an integer */

    p = &x;              /* Read it, "assign the address of x to p" */

    printf("new_pointer2 - Please enter a number: ");
    scanf("%d", &x);     /* Put a value in x, we could also use p here */
    printf("number is : %d\n", *p);  /* Note the use of the * to get the value */
    getch();
}

int main(void)
{
    new_pointer1();
    new_pointer2();

    return 0;
}
