#include <obstack.h>
#include <stdlib.h>

// An [obstack] is a pool of memory containing a stack of objects. You can
// create any number of separate obstacks, and then allocate objects in
// sepcified obstacks. Within each obstack, the last object allocated must
// always be the first one freed, but distinct obstack are independent of
// each other.

    // struct obstack

// An obstack is represented by a data structure of type [struct obstack].
// This structure has a small fixed size; it records the status of the
// obstack abd how to find the space in which objects are allocated.
// It does not contain any of the objects themselves. You should not try
// to access the contents of the structure directly;

#define obstack_chunk_alloc malloc
#define obstack_chunk_free free


void
obstack_usage(void)
{
    // Here are two examples of how to allocate the space for an obstack and initialize it. 
    // First, an obstack that is a static variable:
    static struct obstack obs;
    obstack_init(&obs);

    // Second, an obstack that is itself dynamically allocated:
    struct obstack *obs_ptr = (struct obstack *) malloc(sizeof(struct obstack));
}


int
main(void)
{
    obstack_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Obstacks.html#Obstacks
// https://www.gnu.org/software/libc/manual/html_node/Creating-Obstacks.html#Creating-Obstacks
// https://www.gnu.org/software/libc/manual/html_node/Preparing-for-Obstacks.html#Preparing-for-Obstacks