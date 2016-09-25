#include <string.h>
#include <stdio.h>

/*
char *strtok(char *str, const char *delim);

str   - The contents of this string are modified and broken into smaller strings(tokens).
delim - This is the C string containing the deliniters. These may vary from one call to another.

*/

int main(int argc, char const *argv[]) {
  char str1[] = "This is a demo string";
  char str2[] = "i";
  char *pointer;

  pointer = strtok(str1, str2);
  printf("pointer: %p\n", pointer);
  return 0;
}
