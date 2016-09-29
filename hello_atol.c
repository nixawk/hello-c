#include <stdlib.h>
#include <stdio.h>

/*

long int atol(const char *str)

converts the string argument str to a long integer (type long int)

- str -- This is the string containing the representation of an integral number.

This function returns the converted integral number as a long int.
If no valid conversion could be performed, it returns zero.

*/

int main(int argc, char const *argv[]) {
  long lnum;
  char snum[] = "123123123";

  lnum = atol(snum);
  if (lnum != 0)
      printf("String: %s -> Long int: %ld", snum, lnum);
  return 0;
}
