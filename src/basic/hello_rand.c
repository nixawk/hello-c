#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*

int rand(void);

This function returns an integer value between 0 and RAND_MAX
*/

int main(int argc, char const *argv[]) {
  int i, n;
  time_t t;

  n = 5;

  /* Initializes random number generator */
  srand((unsigned) time(&t));

  /* Print 5 random numbers from 0 to 49 */
  for (i = 0; i < n; ++i)
  {
    printf("%d\n", rand() % 50);
  }

  return 0;
}
