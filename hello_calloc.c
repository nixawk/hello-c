#include <stdlib.h>
#include <stdio.h>


/*

void *calloc(size_t, size_t size);

allocates the requested memory and returns a pointer to it. The difference in
malloc and calloc is that malloc does not set the memory to zero where as calloc
sets allocated memory to zero.

- nitems - This is number of elements to be allocated.
- size - This is the size of elements.

This function returns a pointer to the allocated memory, or NULL if the request
fails.

*/

int main(int argc, char const *argv[]) {
  int i, n;
  int *pointer;

  printf("Number of elements to be entered: ");
  scanf("%d", &n);

  pointer = (int *)calloc(n, sizeof(int));
  printf("Enter %d number: \n", n);
  for (i = 0; i < n; ++i)
  {
      scanf("%d", &pointer[i]);
  }

  printf("The numbers entered are: ");
  for (i = 0; i < n; i++)
  {
      printf("%d ", pointer[i]);
  }
  return 0;
}
