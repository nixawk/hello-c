#include <stdlib.h>
#include <stdio.h>

/*

int mblen(const char *str, size_t n);

returns the length of a multi-byte character pointed to,
by the argument str.

- str - This is the pointer to the first byte of a multibyte character.
- n   - This is the maximum number of bytes to be checked for character length.

The mblen() function returns the number of bytes passed from the multi-byte sequence starting at str,
if a non-null wide character was recongized. It returns 0, if a null wide character was recognized.
It return -1, if an invalid multi-byte sequence was encountered or if it could not parse a complete
multi-byte character.

*/

int main(int argc, char const *argv[]) {
  int len;
  char *pmbnull = NULL;
  char *pmb = (char *)malloc(MB_CUR_MAX);

  wchar_t *pwc = L"Hi";
  wchar_t *pwcs = (wchar_t *)malloc(sizeof(wchar_t));

  printf("Converting to multibyte string\n");
  len = wcstombs(pmb, pwc, MB_CUR_MAX);
  printf("Characters converted %d\n", len);
  return 0;
}
