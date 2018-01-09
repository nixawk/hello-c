#include <stdio.h>


void
byteorder(void)
{
    union {
        short s;
        char  c[sizeof(short)];
    } un;

    un.s = 0x0102;
    // printf("%s: ", CPU_VENDOR_OS);
    if (sizeof(short) == 2)
    {
        if (un.c[0] == 1 && un.c[1] == 2)
            printf("big-endian\n");
        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");
        else
            printf("unknown\n");
    } else {
        printf("sizeof(short) = %d\n", sizeof(short));
    }
}

int
main(int argc, char *argv[])
{
    byteorder();
    return 0;
}


// http://www.informit.com/articles/article.aspx?p=169505&seqNum=4
// https://stackoverflow.com/questions/2531827/what-are-makefile-am-and-makefile-in
// https://www.gnu.org/software/automake/manual/html_node/Creating-amhello.html