#include <stdlib.h>
#include <stdio.h>


// void * calloc (size_t count, size_t eltsize)

// The function [calloc] allocates memory and clears it to zero. Iti is declared in [stdlib.h]

void
calloc_usage(void)
{
    int *ptr = calloc(1, sizeof(int));
    if (ptr == NULL)
    {
        fprintf(stderr, "calloc() failed\n");
        exit(0);
    }

    printf("%d\n", *ptr);  // print 0
    free(ptr);             // cleanup
}


int
main(void)
{
    calloc_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Allocating-Cleared-Space.html#Allocating-Cleared-Space