#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This section describes what you find in a single directory entry,
// as you might obtain it from a directory stream.
// All the symbols are declared in the header file [dirent.h]

    // struct dirent {
    //     ino_t          d_ino;       /* inode number */
    //     off_t          d_off;       /* offset to the next dirent */
    //     unsigned short d_reclen;    /* length of this record */
    //     unsigned char  d_type;      /* type of file; not supported
    //                                    by all file system types */
    //     char           d_name[256]; /* filename */
    // };

// struct dirent * readdir (DIR *dirstream)

// The function reads the next entry from the directory. It normally returns a pointer
// to a structure containing information about the file. This structure  is associated
// with the [dirstream] handle and can be rewritten by a subsequent call.

// On success, readdir() returns a pointer to a dirent structure. (This structure may be
// statically allocated; do not attempt to free it.) If the end of the directory stream
// is reached, NULL is returned and [errno] is not changed. If an error occurs, NULL is
// returned and errno is set appropriately.

// struct dirent64 * readdir64 (DIR *dirstream)

void readdir_usage(void)
{
	char *dirpath = "/tmp/";
	DIR *dirstream;
	struct dirent *entry;

	dirstream = opendir(dirpath);
	if (dirstream == NULL) {
		fprintf(stderr, "opendir() failed: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	while ((entry = readdir(dirstream)) != NULL) {
		printf("%s\n", entry->d_name);
	}

	closedir(dirstream);
}

int main(void)
{
	readdir_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Reading_002fClosing-Directory.html#Reading_002fClosing-Directory
// https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html#Directory-Entries
// https://linux.die.net/man/3/readdir
// https://www.gnu.org/software/libc/manual/html_node/Simple-Directory-Lister.html#Simple-Directory-Lister
