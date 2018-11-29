#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void dlopen_usage(void)
{
	void *handle;
	void (*hello) (const char *);

	/* dynamically load the shared library containing hello() */
	handle = dlopen("library.so", RTLD_GLOBAL);
	if (handle == NULL) {
		fprintf(stderr, "%s:%d:%s", __FILE__, __LINE__,
			strerror(errno));
		exit(1);
	}

	/* get a pointer to the hello() function we just loaded */
	hello = dlsym(handle, "hello");
	if (hello == NULL) {
		fprintf(stderr, "%s:%d:%s", __FILE__, __LINE__,
			strerror(errno));
		exit(1);
	}

	/* call function hello() */
	hello("world");

	/* unload the shared library */
	if (dlclose(handle) != 0) {
		fprintf(stderr, "%s:%d:%s", __FILE__, __LINE__,
			strerror(errno));
		exit(1);
	}
}

int main(void)
{
	dlopen_usage();
	return 0;
}

// http://man7.org/linux/man-pages/man3/dlopen.3.html
