#include <stdio.h>

size_t s_len(char *s)
{
	char *d = s;
	for (; *d; d++) {
		;
	}
	return (size_t) (d - s);
}

int main(void)
{
	char s[] = "helloworld";
	printf("s_len(s) = %ld\n", s_len(s));
	return 0;
}

/* https://en.cppreference.com/w/c/keyword/for */
