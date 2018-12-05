#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

// int rename (const char *oldname, const char *newname)

// If [oldname] is not a directory, then any existing file named [newname] is removed during
// the renaming operation. However, if newname if the name of a directory, rename fails in in this case.

// If [oldname] is a directory, then either [newname] must not exist or it must name a directory
// that is empty. In the latter case, the existing directory named [newname] is deleted first.
// The name [newname] must not specify a subdirectory of the directory [oldname] which is being renamed.

// If rename fails, it returns -1.

void rename_usage(void)
{
	if (-1 == rename("/tmp/oldfile", "/tmp/newfile")) {
		fprintf(stderr, "rename() failed: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("rename successfully\n");
}

int main(void)
{
	rename_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Renaming-Files.html#Renaming-Files
