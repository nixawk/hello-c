#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*

void *malloc(size_t size);

allocates the requested memory and returns a pointer to it.

- size -- This is the size of the memory block, in bytes.

This function returns a pointer to the allocated memory, or NULL if the request fails.


*/

int main(int argc, char const *argv[]) {
     char *str;

     /* Initial memory allocation */
     str = (char *) malloc(15);
     strcpy(str, "www.google");
     printf("String = %s,  Address = %p\n", str, str);

     /* Reallocating memory */
     str = (char *) realloc(str, 25);
     strcat(str, ".com");
     printf("String = %s,  Address = %p\n", str, str);

     free(str);

     return(0);
  }
