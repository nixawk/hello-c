#include <stdio.h>

int main(void)
{
	float f = 12345.6789;

	/*

	   %f    print as floating point
	   %6f   print as floating point, at least 6 characters wide
	   %.2f  print as floating point, 2 characters after decimal point
	   %6.2f print as floating point, at least 6 wide and 2 after decimal point

	 */

	printf("%5.1f\n", f);	/* 12345.6 */
	printf("%5.2f\n", f);	/* 12345.67 */
	printf("%9.2f\n", f);	/* _12345.67, _ is a space. */

	return 0;
}
