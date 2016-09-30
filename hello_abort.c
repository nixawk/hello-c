#include <stdlib.h>
#include <stdio.h>

/*

void abort(void);

abort the program execution and comes out directly from the place of the call.

This function does not return any value.

*/

int main(int argc, char const *argv[]) {
  FILE *fp;

  printf("Going to open nofile.txt\n");
  fp = fopen("nofile.txt", "r");
  if (fp == NULL)
  {
    printf("Going to abort the program\n");
    abort();
  }
  printf("Going to close nofile.txt\n");
  fclose(fp);

  return 0;
}
