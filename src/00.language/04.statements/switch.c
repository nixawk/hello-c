#include <stdio.h>

enum { A, B, C };

int main(int argc, const char *argv[])
{
	switch (argc - 1) {
	case A:
		printf("This is A\n");
		break;
	case B:
		printf("This is B\n");
		break;
	case C:
		printf("This is C\n");
		break;
	default:
		printf("This is unknown\n");
		break;
	}
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/default */
/* https://en.cppreference.com/w/c/language/switch */
