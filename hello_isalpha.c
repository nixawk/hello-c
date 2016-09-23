#include <ctype.h>
#include <stdio.h>

int main()
{
  /*
      char    hex     digit
      ----    ----    ------
      0       0x30    48
      9       0x39    57

      a       0x61    97
      z       0x7a    122
  */

    printf("%d\n", isalpha('0'));   // true
    printf("%d\n", isalpha(97));
    return 0;
}

// https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
