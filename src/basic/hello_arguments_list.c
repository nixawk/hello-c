#include <stdarg.h>
#include <stdio.h>

/*

  va_list  - a variable capable pf storing a variable-length argument list.
  va_start - initialize a_list with v_start,
  va_arg   - takes a va_list and a variable type, and returns the next argument in the list in the form of whatever variable type it is told.
             It then moves down the list to the next argument.
  va_end   - clean up the list.
 */

int sum(int argc, ...)
{
	int total = 0;
	int i;

	va_list arguments;
	va_start(arguments, argc);

	for (i = 0; i < argc; ++i) {
		total += va_arg(arguments, int);
	}

	va_end(arguments);

	return total;
}

int main(void)
{
	printf("1 + 2 + 3 + 4 + 5 = %d\n", sum(5, 1, 2, 3, 4, 5));
	return 0;
}
