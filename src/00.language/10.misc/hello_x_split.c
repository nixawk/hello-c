#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void split(void)
{
	char s[] = "aaa.bbb,ccc;ddd:eee!fff-";
	char sep[] = " .,;:!-";

	char *token;

	for (token = strtok(s, sep); token; token = strtok(NULL, sep)) {
		printf("%s\n", token);
	}

	if (token)
		free(token);
}

int main(void)
{
	split();
	return 0;
}
