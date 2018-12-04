/* gcc -DDEBUG conditional.c */

#include <stdio.h>

void preprocessor_conditional(void)
{
#ifdef DEBUG
	printf("[*] this is a debug message\n");
#elif INFO
	printf("[+] this is a info message\n");
#else
	printf("[*] this is another message\n");
#endif

#ifndef DEBUG
	printf("[*] this is not a debug message\n");
#else
	printf("[*] this is a debug message\n");
#endif
}

int main(void)
{
	preprocessor_conditional();
	return 0;
}

/* https://en.cppreference.com/w/c/preprocessor/conditional */
