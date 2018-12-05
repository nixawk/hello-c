// The archetypal use of wildcard is for matching against the files in a
// directory, and making a list of all the matches. This is called globbing.

// You could do this using fnmatch, by reading the directory entries one by
// one and testing each one with fnmathc. But that would be slow (
// complex, since you would have to handle subdirectories by hand).

// The library provides a function glob to make this particular use of
// wildcards convenient. glob and the other symbols in this section are
// declared in glob.h.

#include <glob.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int errfunc(const char *filename, int errorcode)
{
	fprintf(stderr, "filename: %s, errorcode: %d\n", filename, errorcode);
	return 0;		/* let glob keep going */
}

void glob_usage(const char *pattern)
{
	glob_t globbuf;
	int i;

	if (glob(pattern, GLOB_MARK, errfunc, &globbuf) != 0) {
		perror("glob");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < (globbuf.gl_pathc); i++) {
		printf("%s\n", globbuf.gl_pathv[i]);
	}

	globfree(&globbuf);
}

int main(void)
{
	glob_usage("*");
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Calling-Glob.html#Calling-Glob
// https://www.gnu.org/software/libc/manual/html_node/Flags-for-Globbing.html#Flags-for-Globbing
// http://man7.org/linux/man-pages/man3/glob.3.html
// http://man7.org/linux/man-pages/man7/glob.7.html
// https://github.com/perusio/linux-programming-by-example/blob/master/book/ch12/ch12-glob.c
// https://www.gnu.org/software/libc/manual/html_node/More-Flags-for-Globbing.html#More-Flags-for-Globbing
