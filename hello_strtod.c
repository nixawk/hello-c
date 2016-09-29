#include <stdlib.h>
#include <stdio.h>

/*

double strtod(const char *str, char **endptr);

converts the string pointed to by the argument str to a floating-point number
(type double). If endptr is not NULL, a pointer to the character after the last
character used in the conversion is stored in the location referenced by endptr.

- str - This is the value to be converted to a string.
- endptr - This is the reference to an already allocated object of type char*,
  whose value is set by the function to the next character in str after the numerical value.

This function returns the converted floating point number as a double value, else
zero value (0.0) is returned.

*/

int main(int argc, char const *argv[]) {
  char sn[] = "3.1415926 This is a demo string.";
  char *ptr;
  double ret;

  ret = strtod(sn, &ptr);
  printf("String: %s -> Double: %lf\n", sn, ret);
  printf("Double: %s", ptr);  // output: This is a demo string.
  return 0;
}
