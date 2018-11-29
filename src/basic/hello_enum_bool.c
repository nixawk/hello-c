#include <stdio.h>

// When you want to define names with constant integer values,
// use enum rather than ‘#define’. 

typedef enum {
	false,
	true
} bool;

int main(void)
{
	bool ret = true;

	if (ret) {
		printf("condition is true;\n");
	}

	return 0;
}

// https://www.gnu.org/prep/standards/standards.html#Names
