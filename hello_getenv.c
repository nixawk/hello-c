#include <stdlib.h>
#include <stdio.h>

/*

char *getenv(const char *name);

- name - This is the C string containing the name of the requested variable.

This function returns a null-terminated string with the value of the requested
environment variable, or NULL if that environment variable does not exist.

*/

int main(int argc, char const *argv[]) {
  printf("PATH: %s\n", getenv("PATH"));
  printf("HOME: %s\n", getenv("HOME"));
  printf("SHELL: %s\n", getenv("SHELL"));

  return 0;
}
