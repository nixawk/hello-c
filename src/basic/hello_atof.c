#include <stdlib.h>
#include <stdio.h>

/*
double atof(const char *str)

converts the string argument str to a floating-point number  (type double).

This function returns the converted floating point number as a double value.
If no valid conversion could be performed, it returns zero (0.0)
*/

int main(int argc, char const *argv[]) {
  char sn[] = "12345";
  printf("String: %s -> Float: %f\n", sn, atof(sn));
  printf("String: %s -> Integer: %d", sn, atoi(sn));
  return 0;
}
