#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int base;
	char *endptr, *str;
	long val;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s str [base]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	str = argv[1];
	base = (argc > 2) ? atoi(argv[2]) : 10;

	errno = 0;		/* To distinguish success/failure after call */
	val = strtol(str, &endptr, base);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
	    || (errno != 0 && val == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}

	if (endptr == str) {
		fprintf(stderr, "No digits were found\n");
		exit(EXIT_FAILURE);
	}

	/* If we got here, strtol() successfully parsed a number */

	printf("strtol() returned %ld\n", val);

	if (*endptr != '\0')	/* Not necessarily an error... */
		printf("Further characters after number: %s\n", endptr);

	exit(EXIT_SUCCESS);
}

// man strtol
// https://stackoverflow.com/questions/7021725/how-to-convert-a-string-to-integer-in-c
// atof(3), atoi(3), atol(3), strtod(3), strtoul(3)
