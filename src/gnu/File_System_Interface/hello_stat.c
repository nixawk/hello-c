#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// int stat (const char *filename, struct stat *buf)

// The [stat] function returns information about the attributes of the file named by [filename]
// in the structure pointed to by buf.

// If [filename] is the name of a symbolic link, the attributes you get describe the file that
// the link points to. If the link points to a nonexistent file name, then [stat] fails reporting
// a nonexistent file.

// The return value is 0 if the operation is successful, or -1 on failure. 

void
stat_usage(void)
{
    struct stat buf;

    if (0 != stat("/etc/passwd", &buf))
    {
        fprintf(stderr, "stat() failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("stat.st_mode: %d\n", buf.st_mode);
    printf("stat.st_ino : %llu\n", buf.st_ino);
    printf("stat.st_uid : %d\n", buf.st_uid);
    printf("stat.st_gid : %d\n", buf.st_gid);

    if (S_ISDIR(buf.st_mode))
    {
        printf("It is a directiry.\n");
    }

    if (S_ISREG(buf.st_mode))
    {
        printf("It is a regular file.\n");
    }
}


int
main(void)
{
    stat_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Reading-Attributes.html#Reading-Attributes
// https://www.gnu.org/software/libc/manual/html_node/Attribute-Meanings.html#Attribute-Meanings
// https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html#Permission-Bits
// https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html#Testing-File-Type