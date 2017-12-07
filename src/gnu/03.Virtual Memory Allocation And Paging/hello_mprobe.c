#include <stdlib.h>
#include <mcheck.h>
#include <stdio.h>


void
mprobe_usage(void)
{
    char *p = NULL;
    enum mcheck_status ms;

    if (mcheck(NULL) != 0)   // If no mcheck, MCHECK_DISABLED
    {
        fprintf(stderr, "mcheck() failed\n");
        exit(EXIT_FAILURE);
    }

    p = malloc(32);
    ms = mprobe(p);

    switch (ms)
    {
        case(MCHECK_DISABLED):
            fprintf(stderr, "MCHECK_DISABLE\n");
            break;

        case(MCHECK_OK):
            fprintf(stderr, "MCHECK_OK\n");
            break;

        case(MCHECK_HEAD):
            fprintf(stderr, "MCHECK_HEAD\n");
            break;

        case(MCHECK_TAIL):
            fprintf(stderr, "MCHECK_TAIL\n");
            break;

        case(MCHECK_FREE):
            fprintf(stderr, "MCHECK_FREE\n");
            break;

        default:
            fprintf(stderr, "UNKNOWN\n");
    }

    free(p);
}


int
main(void)
{
    mprobe_usage();
    return 0;
}