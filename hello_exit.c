#include <stdlib.h>
#include <stdio.h>

/*
void exit(int status);

status - This is the status value returned to the parent process.

This function does not return any value.

*/

int main(int argc, char const *argv[]) {
  printf("Start the program...\n");
  printf("Exiting  the program...\n");

  exit(0);

  printf("End of the program...\n");
  return 0;
}
