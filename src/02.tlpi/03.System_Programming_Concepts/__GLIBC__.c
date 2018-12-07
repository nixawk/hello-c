#include <stdio.h>

int main(void)
{
#ifdef __GLIBC__
	printf("__GLIBC__: %d\n", __GLIBC__);
	printf("__GLIBC_MINOR__: %d\n", __GLIBC_MINOR__);
#endif
	return 0;
}
