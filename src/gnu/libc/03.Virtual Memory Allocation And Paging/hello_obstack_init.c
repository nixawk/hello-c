#include <obstack.h>
#include <stdlib.h>

    // int obstack_init (struct obstack *obstack-ptr)

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


    // obstack_alloc_failed_handler

// The value of this variable is a pointer to a function that obstack uses
// when obstack_chunk_alloc failes to allocate memory. The default action
// is to print a message and abort. You should supply a function that either
// calls exit and doesn't return.

    // void obstack_free (struct obstack *obstack-ptr, void *object)

// If object is a null pointer, everything allocated in the obstack is freed.
// Otherwise, object must be the address of an object allocated in the obstack.
// Then object is freed, along with everything allocated in obstack-ptr since
// object.

// Note that if object is a null pointer, the result is an uninitialized
// obstack. To free all memory in an obstack but leave it valid for further
// allocation, call obstack_free with the address of the first allocated on
// the obstack.

// Recall that the objects in an obstack are grouped into chunks. When all
// the objects in a chunk become free, the obstack library automatically frees
// the chunk. Then other obstacks, or non-obstack allocation, can reuse the
// space of the chunk.


#define obstack_chunk_alloc malloc
#define obstack_chunk_free free


void
obstack_usage(void)
{
    // Here are two examples of how to allocate the space for an obstack and initialize it.

    // First, an obstack that is a static variable:
    static struct obstack myobstack;
    obstack_init(&myobstack);

    // Second, an obstack that is itself dynamically allocated:
    struct obstack *myobstack_ptr = (struct obstack *) malloc(
        sizeof(struct obstack)
    );
    obstack_init(myobstack_ptr);
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