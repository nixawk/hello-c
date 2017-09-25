#include <string.h>
#include <stdio.h>

/*
size_t strspn(const char *str1, const char *str2);

str1  - This is the main C string to be scanned.
str2  - This is the string containing the list of characters to match in str1.

This function returns the number of characters in the initial segment of str1 which consist only of characters from str2.

*/

int main(int argc, char const *argv[]) {
  const char str1[] = "helloworld";
  const char str2[] = "heyman";

  int num;

  num = strspn(str1, str2);
  printf("match number: %d\n", num); // matches: 2
  return 0;
}
