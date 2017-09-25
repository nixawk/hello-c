#include <stdlib.h>
#include <stdio.h>


// void * malloc (size_t size)

// This function returns a pointer to a newly allocated block size bytes long,
// or a null pointer if the block could not be allocated.


// void free (void *ptr)
// When you no longer need a block that you got with malloc, use the function 
// free to make the block available to be allocated again. 


typedef struct person {
    int id;
} person_t;


void
malloc_usage(void) {
    person_t *p;

    p = (person_t *) malloc(sizeof(person_t));
    if (p == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(0);
    }

    p->id = 0xFF;

    printf("ID: %#x\n", p->id);
    free(p);
}


int
main(void) {
    malloc_usage();
    return(0);
}



// https://www.gnu.org/software/libc/manual/html_node/Basic-Allocation.html#Basic-Allocation