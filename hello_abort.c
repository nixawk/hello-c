#include <stdlib.h>
#include <stdio.h>

/*

void abort(void);

abort the program execution and comes out directly from the place of the call.

This function does not return any value.

Unlike exit() function, abort() may not close files that are open.
It may also not delete temporary files and may not flush stream buffer.
Also, it does not call functions registered with atexit().

This function actually terminates the process by raising a SIGABRT signal,

*/

int main(int argc, char const *argv[]) {
    FILE *fp;

    fp = fopen("nofile.txt", "r");
    if (fp == NULL)
    {
        printf("Going to abort the program\n");
        abort();
    }

    printf("Going to close nofile.txt\n");
    fclose(fp);

    return 0;
}
