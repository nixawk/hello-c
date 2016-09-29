#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*

void free(void *ptr);

deallocates the memory previously allocated by a call to calloc, malloc, or realloc.

- ptr -- This is the pointer to a memory block previously allocated with malloc,
         calloc or realloc to be deallocated. If a null pointer is passed as argument, no action occurs.

This function does not return any value.

*/

int main(int argc, char const *argv[]) {
  char *str;
  int bufsize = 30;

  /* Initial memory allocation */
  str = (char *)malloc(bufsize);
  strcpy(str, "www.google");
  printf("String = %s, Address = %p\n", str, str);

  /* Reallocating memory */
  str = (char *)realloc(str, bufsize);
  strcat(str, ".com");
  printf("String = %s, Address = %p\n", str, str);

  /* Deallocate allocated memory */
  free(str);
  return 0;
}
