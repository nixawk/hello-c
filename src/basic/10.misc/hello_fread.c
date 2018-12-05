#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char astring[] = "this is a demo string";
	char buffer[256];

	/* Open file for both reading and writing */
	fp = fopen("test.txt", "w+");

	/* Write data to the file */
	fwrite(astring, strlen(astring) + 1, 1, fp);

	/* Seek to the beginning of the file */
	fseek(fp, SEEK_SET, 0);

	/* Read and display data */
	fread(buffer, strlen(astring) + 1, 1, fp);
	printf("%s\n", buffer);

	fclose(fp);
	return 0;
}

// https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
