#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

void *realloc(void *ptr, size_t size);

attempts to resize the memory block pointed to by ptr that was previously allocated
with a call to malloc or calloc.

- ptr - This is the pointer to a memory block previously allocated with malloc, calloc
or realloc to be reallocated. If this is NULL, a new block is allocated and a pointer
to it is returned by the function.

- size - This is the new size for the memory block, in bytes. If it is 0 and ptr points
to an existing block of memory, the memory block pointed by ptr is deallocated and
a NULL pointer is returned.

This function returns a pointer to the newly allocated memory, or NULL if the request fails.

*/

int main(int argc, char const *argv[]) {
  char *str;

  /* Initial memory allocation*/
  str = (char *)malloc(15);
  strcpy(str, "www.google");
  printf("String: %s, Address: %p\n", str, str);

  /* Reallocating memory */
  str = (char *)realloc(str, 25);
  strcat(str, ".com");
  printf("String: %s, Address: %p\n", str, str);

  /* Release memory */
  free(str);
  return 0;
}
