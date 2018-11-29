#include <stdio.h>
#include <string.h>

/*
$ echo id | hello-open
*/

int main(int argc, const char *argv[])
{
	FILE *in;
	const int buffsize = 10240;
	char buff[buffsize];
	char command[buffsize];

	scanf("%s", command);

	if (!(in = popen(command, "r"))) {
		return 1;
	}

	while (fgets(buff, sizeof(buff), in) != NULL) {
		printf("%s", buff);
	}

	pclose(in);

	return 0;
}
