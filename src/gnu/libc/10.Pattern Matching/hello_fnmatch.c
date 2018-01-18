#define _GNU_SOURCE
#include <dirent.h>
#include <fnmatch.h>
#include <stdlib.h>
#include <stdio.h>

// The GNU C Library provides pattern matching facilities for two kinds of
// patterns: regular expressions and file-name wildcards.

// Wildcard Matching

    // int fnmatch(const char *pattern, const char *string, int flags);

// The fnmatch() function checks whether the string argument matches the
// pattern argument, which is a shell wildcard pattern.


void
fnmatch_const_print(void)
{
    printf("FNM_NOESCAPE = %d\n", FNM_NOESCAPE);
    printf("FNM_PATHNAME = %d\n", FNM_PATHNAME);
    printf("FNM_PERIOD = %d\n", FNM_PERIOD);
    printf("FNM_FILE_NAME = %d\n", FNM_FILE_NAME);
    printf("FNM_LEADING_DIR = %d\n", FNM_LEADING_DIR);
    printf("FNM_CASEFOLD = %d\n", FNM_CASEFOLD);
    printf("FNM_EXTMATCH = %d\n", FNM_EXTMATCH);
}

void
fnmatch_ls(const char *filename, const char *pattern)
{
    DIR *dir;
    struct dirent *dirent;

    dir = opendir(filename);
    if (dir == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dirent = readdir(dir)) != NULL)
    {
        if (! fnmatch(pattern, dirent->d_name, FNM_PATHNAME | FNM_PERIOD))
        {
            printf("%s\n", dirent->d_name);
        }
    }

    if (closedir(dir) == -1)
    {
        perror("closedir");
        exit(EXIT_FAILURE);
    }

}

int
main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf("[*] %s FILENAME PATTERN\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fnmatch_const_print();
    fnmatch_ls(argv[1], argv[2]);

    return 0;
}

/*

$ ./a.out 
[*] ./a.out FILENAME PATTERN

$ ./a.out /tmp/ "a*"
FNM_NOESCAPE = 2
FNM_PATHNAME = 1
FNM_PERIOD = 4
FNM_FILE_NAME = 1
FNM_LEADING_DIR = 8
FNM_CASEFOLD = 16
FNM_EXTMATCH = 32
a.out

*/

// http://man7.org/linux/man-pages/man3/fnmatch.3.html
// https://www.gnu.org/software/libc/manual/html_node/Wildcard-Matching.html#Wildcard-Matching
// https://tools.cisco.com/security/center/viewAlert.x?alertId=22539
// https://www.exploit-db.com/exploits/17120/
// http://man7.org/linux/man-pages/man3/opendir.3.html
// http://man7.org/linux/man-pages/man3/closedir.3.html
// http://man7.org/linux/man-pages/man3/readdir.3.html
