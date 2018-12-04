/* switch statement: as the declaration of the case labels */

#include <stdio.h>

void keyword_case(void)
{
	enum { AIRPLANE, CAR, TRAIN } tool = 0;
	switch (tool) {
	case AIRPLANE:
		printf("airplane\n");
		break;
	case CAR:
		printf("air\n");
		break;
	case TRAIN:
		printf("train\n");
		break;
	default:
		printf("unknown\n");
		break;

	}
}

int main(void)
{
	keyword_case();
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/case */
