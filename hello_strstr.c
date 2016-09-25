#include <string.h>
#include <stdio.h>

/*

char *strstr(const char *haystack, const char *needle);

haystack - This is the main C string to be scanned.
needle   - This is the small string to be searched with-in haystack string.

This function returns a pointer to the first occurrence in haystack of any of the entire sequence of characters specified in needle, or a null pointer if the sequence is not present in haystack.

*/

int main(int argc, char const *argv[]) {
  const char haystack[] = "this is a demo string";
  const char needle[] = "string";
  char *pointer;

  pointer = strstr(haystack, needle);
  printf("pointer: %p\n", pointer);
  return 0;
}
