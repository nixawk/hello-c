#include <stdio.h>
#include <errno.h>

int main(void)
{
	errno = 1;
	perror("error1");	/* error1: Operation not permitted */

	errno = 2;
	perror("error2");	/* error2: No such file or directory */
	return 0;
}
