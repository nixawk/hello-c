// Member and pointer operators

#include <stdio.h>

typedef struct node
{
    int d;
    int *p;
} node_t;

void
member_and_pointer_operators(void)
{
    // a[b]  - subscript
    // *a    - Indirection ("object pointed to by a")
    // &a    - Address-of ("address of a")
    // a->b  - Structure reference ("member b of object pointed to by a")
    // a.b   - Structure reference ("member b of object a")
    // a->*b - Member selected by pointer-to-member b of object pointed to by a
    // a.*b  - Member of object a selected by pointer-to-member b.

    node_t newnode;
    node_t *nodeptr;
    int d = 1;

    newnode.d = 1;
    newnode.p = &d;        /* address-of */
    nodeptr = &newnode;    /* address-of */

    printf("nodeptr->d = %d\n", nodeptr->d);         /* structure reference */
    printf("nodeptr->p = %p\n", nodeptr->p);         /* structure reference */
    printf("*(nodeptr->p) = %d\n", *(nodeptr->p));
}

int
main(void)
{
    member_and_pointer_operators();
    return 0;
}

// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Arithmetic_operators
