#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int scandir (
//     const char *dir,
//     struct dirent ***namelist,
//     int (*selector) (const struct dirent *), 
//     int (*cmp) (const struct dirent **, const struct dirent **)
// )

// The [scandir] function scans the contents of the directory selected by [dir].
// The result in *namelist is an array of pointers to structures of type [struct dirent]
// which describe all selected directory entries and which is allocated using malloc.

// Instead of always getting all directory entries returned, the user supplied function
// [selector] can be used to decide which entries are in the result. Only the entries for
// which [selector] returns a non-zero value are selected.

// Finally the entries in *namelist are sorted using the user-supplied function [cmp].
// The arguments passed to the [cmp] function are of type [struct dirent **], therefore
// one cannot directly use the [strcmp] or [strcoll] functions; instead see the functions
// [alphasort] and [versionsort].

// The return value of the function is the number of entries placed in [*namelist]. If
// it is -1 an error occurred (either the directory could not be opened for reading or the
// malloc call failed) and the global variable [errno] contains more information on the error.

int selector(const struct dirent *entry)
{
	return (strstr(entry->d_name, "log") == NULL) ? 0 : 1;
}

void scandir_usage(void)
{
	char *dirpath = "/var/log/";
	struct dirent **namelist;
	int n, i;

	n = scandir(dirpath, &namelist, selector, alphasort);
	if (n == -1) {
		fprintf(stderr, "scandir() failed: %s\n", strerror(errno));
	}

	for (i = 0; i < n; i++) {
		printf("%s\n", namelist[i]->d_name);
		free(namelist[i]);
	}
	free(namelist);

	printf("namelist count: %d\n", n);
}

int main(void)
{
	scandir_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Scanning-Directory-Content.html#Scanning-Directory-Content
// https://stackoverflow.com/questions/17616362/filtering-scandir-for-filenames-in-folder-c-language
