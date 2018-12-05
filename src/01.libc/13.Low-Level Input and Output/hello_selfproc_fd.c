#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define selfproc "/proc/self/fd"

void list_fd()
{
	DIR *dirp = NULL;
	struct dirent *dp = NULL;

	dirp = opendir(selfproc);
	if (dirp == NULL) {
		printf("failed to opendir %s\n", selfproc);
		exit(EXIT_FAILURE);
	}

	while ((dp = readdir(dirp)) != NULL) {
		if (strstr(dp->d_name, ".") == NULL)	// excude ".", ".."
		{
			printf("file descriptor: %s\n", dp->d_name);
		}
	}

	if (closedir(dirp) == -1) {
		printf("failed to closedir %s\n", selfproc);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, const char *argv[])
{
	list_fd();
	return 0;
}

// https://en.wikipedia.org/wiki/File_descriptor
// https://stackoverflow.com/questions/6583158/finding-open-file-descriptors-for-a-process-linux-c-code
// http://www.microhowto.info/howto/list_all_open_file_descriptors_for_a_given_process.html
