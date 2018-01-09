#include <stdlib.h>

    // void free (void *ptr)

// When you no longer need a block that you got with [malloc], use the function [free]
// to make the block available to be allocated again.

// The [free] function deallocates the block of memory pointed at by ptr.

// Freeing a block alters the contents of the block. Do not expect to find any data
// (such as a pointer to the next block in a chain of blocks) in the block after
// freeing it. Copy whatever you need out of the block before freeing it!

// Occasionally, free can actually return memory to the operating system and make
// the process smaller. Usually, all it can do is allow a later call to malloc to
// reuse the space. In the meantime, the space remains in your program as part of
// a free-list used internally by malloc.

// There is no point in freeing blocks at the end of a program, because all of the
// program’s space is given back to the system when the process terminates.

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


// https://www.gnu.org/software/libc/manual/html_node/Freeing-after-Malloc.html#Freeing-after-Malloc
// http://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/