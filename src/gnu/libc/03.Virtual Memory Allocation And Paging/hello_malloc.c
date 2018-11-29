#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

    // void * malloc (size_t size)

// This function returns a pointer to a newly allocated block size bytes long,
// or a null pointer if the block could not be allocated.

// The contents of the block are undefined; you must initialize it yourself.
// Normally you would cast the value as a pointer to the kind of object that
// you want to store in the block.

// Initializing the space with zeros using library function memset.

// If no more space is available, [malloc] returns a null pointer. You should
// check the value of every call to [malloc]. It is useful to write a subroutine
// that calls [malloc] and reports an error if the value is a null pointer,
// returning only if the value is nonzero.

    // void free (void *ptr)

// When you no longer need a block that you got with malloc, use the function 
// free to make the block available to be allocated again. 

    // void * memset(void *b, int c, size_t len);

// The memset() function returns its first argument.

typedef struct foo {
	int x;
} foo_t;

void malloc_usage(void)
{
	foo_t *ptr;

	ptr = (foo_t *) malloc(sizeof(foo_t));
	if (ptr != NULL) {
		error(EXIT_FAILURE, errno, "malloc() failed");
	}

	memset(ptr, 0, sizeof(foo_t));
	printf("foo.x = %d\n", ptr->x);

	free(ptr);
}

int main(void)
{
	malloc_usage();
	return (0);
}

// https://www.gnu.org/software/libc/manual/html_node/Basic-Allocation.html#Basic-Allocation
// https://www.gnu.org/software/libc/manual/html_node/Malloc-Examples.html#Malloc-Examples
