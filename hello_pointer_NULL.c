#include <stdio.h>


/*

NULL pointer:

    1. To initialize a pointer variable when that pointer variable isn't assigned any valid memory address yet.
    2. To check for null pointer before accessing any pointer variable.
    3. To pass a null pointer to a function argument when we don't want to pass any valid memory address.

NULL pointer is different from uninitialized and dangling pointer.
    1. Uninitialized and Dangling pointers are invalid but they can point to some memory address that may
       be accessible though the memory access is unintended.

*/


int
main(void)
{
    int *intptr;
    int *nulptr = NULL;

    printf("%p\n", intptr);           /* print a valid memory address */
    printf("%p\n", nulptr);           /* print 0 */

    printf("%lu\n", sizeof(intptr));  /* print pointer length */
    printf("%lu\n", sizeof(nulptr));  /* print pointer length */

    printf("%#x\n", *intptr);         /* print memory value */
    printf("%#x\n", *nulptr);         /* exception here */

    return 0;
}