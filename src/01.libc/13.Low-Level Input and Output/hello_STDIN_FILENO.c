#include <unistd.h>
#include <stdio.h>

void print_fileno(void)
{
	printf("STDIN_FILENO = %d\n", STDIN_FILENO);
	printf("STDOUT_FILENO = %d\n", STDOUT_FILENO);
	printf("STDERR_FILENO = %d\n", STDERR_FILENO);
}

int main(void)
{
	print_fileno();
	return 0;
}

// https://stackoverflow.com/questions/15102992/what-is-the-difference-between-stdin-and-stdin-fileno
