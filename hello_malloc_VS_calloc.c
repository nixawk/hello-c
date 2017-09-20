#include <stdlib.h>


/*

The name malloc() and calloc() are library functions that allocate memory dynamically.
It means that memory is allocated during runtime (execution of the program) from heap segment.

malloc()
    - allocates memory block of given size (in bytes) and returns a pointer to the beginning of the block.
      malloc() doesn't initialize the allocated memory. If we try to access the content of memory block
      then we'll get garbage values.

calloc()
    - allocates mempry and initializes the allocates memory block to zero.
      If we try to access the content of these blocks then we'll get 0.

- Number of arguments: Unlike malloc(), calloc() takes two arguments
    - Number of blocks to be allocated.
    - Size of each block.
- Return Value
    - success : a pointer to the block of memory is returned.
    - failed  : NULL value is returned which indicates.

*/

void
malloc_ex(void)
{
    int *ptr = malloc(512);  /* allocate 512 bytes, not init */
    free(ptr);
}

void
calloc_ex(void)
{
    int *ptr = calloc(512, sizeof(char));  /* allocate 512 bytes, and initialize them to 0 */
    free(ptr);
}

int
main(void)
{
    malloc_ex();
    calloc_ex();
}

// http://www.geeksforgeeks.org/calloc-versus-malloc/