#include <stdio.h>

int main(int argc, const char *argv[])
{
	switch (argc) {
	case 1:
		printf("[*] %s arg1 arg2 [...]\n", argv[0]);
		break;
	default:
		printf("do_something here\n");
		break;
	}
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/default */
