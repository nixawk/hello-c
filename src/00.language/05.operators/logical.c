#include <stdio.h>

typedef enum { false, true } bool;

void logical(void)
{
	bool cond1 = false;
	bool cond2 = true;

	if (!cond1) {
		printf("cond1 is true\n");
	}

	if (cond1 && cond2) {
		printf("both cond1 and cond2 are true\n");
	}

	if (cond1 || cond2) {
		printf("cond1 is true, or cond2 is true\n");
	}
}

int main(void)
{
	logical();
	return 0;
}
