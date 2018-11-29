#include <stdio.h>

int main(void)
{
	FILE *fp;

	fp = fopen("test.txt", "a+");
	printf("src string: helloworld");
	fprintf(fp, "helloworld\n");
	fclose(fp);
	return 0;
}
