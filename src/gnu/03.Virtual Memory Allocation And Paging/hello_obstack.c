#include <stdio.h>
#include <obstack.h>


// struct obstack          /* control current object in current chunk */
// {
//   long chunk_size;              /* preferred size to allocate chunks in */
//   struct _obstack_chunk *chunk; /* address of current struct obstack_chunk */
//   char *object_base;            /* address of object we are building */
//   char *next_free;              /* where to add next char to current object */
//   char *chunk_limit;            /* address of char after current chunk */
//   union
//   {
//     PTR_INT_TYPE tempint;
//     void *tempptr;
//   } temp;                       /* Temporary for some macros.  */
//   int alignment_mask;           /* Mask of alignment for each object. */
//   /* These prototypes vary based on 'use_extra_arg', and we use
//      casts to the prototypeless function type in all assignments,
//      but having prototypes here quiets -Wstrict-prototypes.  */
//   struct _obstack_chunk *(*chunkfun) (void *, long);
//   void (*freefun) (void *, struct _obstack_chunk *);
//   void *extra_arg;              /* first arg for chunk alloc/dealloc funcs */
//   unsigned use_extra_arg : 1;     /* chunk alloc/dealloc funcs take extra arg */
//   unsigned maybe_empty_object : 1; /* There is a possibility that the current
//                                       chunk contains a zero-length object.  This
//                                       prevents freeing the chunk if we allocate
//                                       a bigger chunk to replace it. */
//   unsigned alloc_failed : 1;      /* No longer used, as we now call the failed
//                                      handler on error, but retained for binary
//                                      compatibility.  */
// };


// An obstack is represented by a data structure of type struct obstack.
// This structure has a small fixed size; it records the status of the
// obstack and how to find the space in which objects are allocated.
// It does not contain any of the objects themselves. You should not
// try to access the contents of the structure directory;

// You can declare variables of type struct obstack and use them as obstacks,
// or you can allocate obstack dynamically like any other kind of object.
// Dynamic allocation of obstacks allows your program to have a variable
// number of different stacks. (You can even allocate an obstack structure
// in another obstack, but this is rarely useful.)

void
obstack_usage(void)
{
    struct obstack obs;
    printf("%lu\n", sizeof(obs));
    printf("%lu\n", obs.chunk_size);
}


int
main(void)
{
    obstack_usage();
    return 0;
}