#include <stdio.h>
#include <string.h>

int main(void)
{
	char src[] = "helloworld";
	char dest[256];

	memset(dest, '\x00', 256);
	strcpy(dest, src);

	printf("destination string : %s\n", dest);
	return 0;
}
