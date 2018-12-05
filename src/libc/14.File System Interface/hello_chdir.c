#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

// int chdir (const char *filename)

// This function is used to set the process's working directory to [filename].
// The normal, successful return value from [chdir] is 0. A value of -1 is
// returned to indicate an error. The [errno] error conditions defined for
// this function are the usual file name syntax errors, plus [ENOTDIR] if
// the file [filename] is not a directory. 

void getcwd_usage(void);
void chdir_usage(void);

#define PATH_MAX 4096

void getcwd_usage(void)
{
	char path[PATH_MAX] = "";
	if (path == getcwd(path, PATH_MAX)) {
		printf("current directory: %s\n", path);
	} else {
		fprintf(stderr, "getcwd() failed: %s.\n", strerror(errno));
	}
}

void chdir_usage(void)
{
	int ret;

	getcwd_usage();
	ret = chdir("/tmp/");
	if (ret != 0) {
		fprintf(stderr, "chdir() failed: %s", strerror(errno));
	}
	getcwd_usage();
}

int main(void)
{
	chdir_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Working-Directory.html#Working-Directory
