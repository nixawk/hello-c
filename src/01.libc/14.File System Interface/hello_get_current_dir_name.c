#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

// char * get_current_dir_name (void)

// This [get_current_dir_name(void)] function is basically equivalent to
    // getcwd(NULL, 0)
// The only difference is that the value of the [PWD] variable is returned
// if this value is correct. This is a subtle difference which is visible 
// if the path described by the PWD value is using one or more symbol links 
// in which case the value returned by getcwd can resolve the symbol links 
// and therefore yield a different result.

void get_current_dir_name_usage(void)
{
	char *path = get_current_dir_name();
	if (path != NULL) {
		printf("current directory: %s\n", path);
	} else {
		fprintf(stderr, "get_current_dir_name() failed: %s.\n",
			strerror(errno));
	}
}

int main(void)
{
	get_current_dir_name_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Working-Directory.html#Working-Directory
