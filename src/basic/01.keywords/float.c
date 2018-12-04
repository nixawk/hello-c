/* Real floating-point type, usually referred to as a single-precision
 * floating-point type. Actual properties unspecified (except minimum
 * limits), however on most systems this is the IEEE 754 single-precision
 * binary floating-point format (32 bits). This format is required by
 * the optional Annex F "IEC 60559 floating-point arithmetic".
 */

#include <stdio.h>

void float_sizeof(void)
{
	printf("sizeof(float) = %lu byte(s)\n", sizeof(float));
}

void float_mismatch(void)
{
	float f1 = 0.1;
	float f2 = 0.5;

	if (f1 == 0.1)
		printf("f1 == 0.1\n");
	else if (f1 == 0.1f)
		printf("f1 == 0.1f\n");	/* output */
	else
		printf("f1 != 0.1 or 0.1f\n");

	/* Note that the promotion of float or double can only cause
	 * mismatch when a value (like 0.1) uses more precision bits
	 * of single precision. */

	if (f2 == 0.5)
		printf("f2 == 0.5\n");	/* output */
	else if (f2 == 0.5f)
		printf("f2 == 0.5f\n");
	else
		printf("f2 != 0.5 or 0.5f\n");

	printf("f1   = %.30f\n", f1);
	printf("0.1  = %.30f\n", 0.1);
	printf("0.1f = %.30f\n", 0.1f);

	printf("f2   = %.30f\n", f2);
	printf("0.5  = %.30f\n", 0.5);
	printf("0.5f = %.30f\n", 0.5f);
}

void float_compare(void)
{
	float f1 = 0.1;
	float f2 = 0.1;

	/* You should never compare floating point values for equality
	   due to known precision and rounding issues. */

	if (f1 == f2)
		printf("f1 == f2\n");
	else
		printf("f1 != f2\n");
}

int main(void)
{
	float_sizeof();
	float_mismatch();
	float_compare();

	return 0;
}

/*

$ ./a.out
sizeof(float) = 4 byte(s)
f1 == 0.1f
f2 == 0.5
f1   = 0.100000001490116119384765625000
0.1  = 0.100000000000000005551115123126
0.1f = 0.100000001490116119384765625000
f2   = 0.500000000000000000000000000000
0.5  = 0.500000000000000000000000000000
0.5f = 0.500000000000000000000000000000
f1 == f2

*/

// https://en.wikipedia.org/wiki/C_data_types
// https://en.wikipedia.org/wiki/IEEE_754
// https://www.geeksforgeeks.org/data-types-in-c/
// https://stackoverflow.com/questions/5989191/compare-two-floats
// https://www.geeksforgeeks.org/comparison-float-value-c/
// https://bitbashing.io/comparing-floats.html
// https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/fabs.htm
