#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	size_t n;
	char buf[256];

	n = confstr(_CS_GNU_LIBC_VERSION, buf, 256);
	if (n == 0) {
		perror("confstr");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", buf);	/* glibc 2.27 */
	return 0;
}
