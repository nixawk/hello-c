#include <unistd.h>
#include <sys/param.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// int MAXSYMLINKS

// The macro [MAXSYMLINKS] specifies how many symlinks some function will follow
// before returning [ELOOP]. Not all functions behave the same and this value is
// not the same as that returned for [_SC_SYMLOOP] by sysconf, the sysconf result
// can indicate that there is no fixed limit althrough [MAXSYMLINKS] exists and
// has a finite value.

// int symlink (const char *oldname, const char *newname)

// The normal return from [symlink] is 0. A return value of -1 indicates an error.
// In addition to the usual file name syntax errors, the following [errno] error
// conditions are defined for this function.

#define FILENAME "/tmp/filename"
#define SYMFNAME "/tmp/symlink"

void print_MAXSYMLINKS(void)
{
	printf("MAXSYMLINKS: %d\n", MAXSYMLINKS);
}

void symlink_usage(void)
{
	if (symlink(FILENAME, SYMFNAME) != 0) {
		fprintf(stderr, "symlink() failed: %s\n", strerror(errno));
	}
	printf("symlink() successful : %s\n", SYMFNAME);
}

int main(void)
{
	print_MAXSYMLINKS();
	symlink_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Symbolic-Links.html#Symbolic-Links
// https://unix.stackexchange.com/questions/53087/how-do-you-increase-maxsymlinks
