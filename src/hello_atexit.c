#include <stdlib.h>
#include <stdio.h>

/*

int atexit(void (*func)(void));

- func -- This is the function to be called at the termination of the program.

This function returns a zero value if the function is registered successfully,
otherwise a non-zero value is returned if it is failed.

*/

void callback(void)
{
    printf("callback function\n");
}

int main(int argc, char const *argv[]) {
  /* register the termination function */
  atexit(callback);

  printf("Starting main program...\n");
  printf("Exiting  main program...\n");

  return 0;
}
