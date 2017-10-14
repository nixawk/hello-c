#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

// struct mallinfo mallinfo (void)

// This function returns information about the current dunamic memory
// usage in a structure of type [struct mallinfo].

void
mallinfo_usage(void)
{
    struct mallinfo m;

    m = mallinfo();
    printf("mallinfo.arena: %d\n", m.arena);
    printf("mallinfo.ordblks: %d\n", m.ordblks);
    printf("mallinfo.smblks: %d\n", m.smblks);
    printf("mallinfo.hblks: %d\n", m.hblks);
    printf("mallinfo.hblkhd: %d\n", m.hblkhd);
    printf("mallinfo.usmblks: %d\n", m.usmblks);
    printf("mallinfo.fsmblks: %d\n", m.fsmblks);
    printf("mallinfo.uordblks: %d\n", m.uordblks);
    printf("mallinfo.fordblks: %d\n", m.fordblks);
    printf("mallinfo.keepcost: %d\n", m.keepcost);
}


int
main(void)
{
    void *ptr;

    mallinfo_usage();
    ptr = malloc(512);
    if (ptr != NULL)
    {
        free(ptr);
    }

    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Statistics-of-Malloc.html#Statistics-of-Malloc
// https://www.gnu.org/software/libc/manual/html_node/Summary-of-Malloc.html#Summary-of-Malloc