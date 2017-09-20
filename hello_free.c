#include <stdlib.h>

/*

void free(void *ptr);

deallocates the memory previously allocated by a call to calloc, malloc, or realloc.

- ptr -- This is the pointer to a memory block previously allocated with malloc,
         calloc or realloc to be deallocated. If a null pointer is passed as argument, no action occurs.

This function does not return any value.

*/

/*

What is Memory Leak ?

Memory leak occurs when programmers create a memory in heap and forget to delete it.
Memory leaks are particularly serious issues for programs like daemons and servers
which by definition never terminate.

To avoid memory leaks, memory allocated on heap should always be freed when no longer needed.

Valgrind : http://valgrind.org/

*/

void
memory_leak(void)
{
    int *ptr = malloc(512);
}


void
avoid_memory_leak(void)
{
    int *ptr = malloc(512);
    free(ptr);
}


int
main(void) {

    memory_leak();
    avoid_memory_leak();

    return 0;
}


// http://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/