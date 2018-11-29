#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

void *realloc(void *ptr, size_t size);

attempts to resize the memory block pointed to by ptr that was previously allocated
with a call to malloc or calloc.

- ptr - This is the pointer to a memory block previously allocated with malloc, calloc
or realloc to be reallocated. If this is NULL, a new block is allocated and a pointer
to it is returned by the function.

- size - This is the new size for the memory block, in bytes. If it is 0 and ptr points
to an existing block of memory, the memory block pointed by ptr is deallocated and
a NULL pointer is returned.

This function returns a pointer to the newly allocated memory, or NULL if the request fails.

*/

/*

If "size" is zero, then call to realloc is equivalent to "free(ptr)".
If "ptr" is NULL and size if non-zero then call to realloc is equivalent to "malloc(size)".

*/

void realloc_malloc(void)
{
	int *ptr = realloc(NULL, 512);	/* eq to malloc */

	printf("realloc_malloc: %p\n", ptr);
	free(ptr);
}

void realloc_free(void)
{
	int *ptr = malloc(512);
	int *realloc_ptr = realloc(ptr, 0);	/* eq to free(ptr) */

	printf("realloc_free: %p\n", realloc_ptr);
}

void realloc_resize(void)
{
	char *str;

	/* Initial memory allocation */
	str = (char *)malloc(15);
	strcpy(str, "www.google");
	printf("String: %s, Address: %p\n", str, str);

	/* Reallocating memory */
	str = (char *)realloc(str, 25);
	strcat(str, ".com");
	printf("String: %s, Address: %p\n", str, str);

	/* Release memory */
	free(str);
}

int main(void)
{

	realloc_malloc();
	realloc_free();
	realloc_resize();

	return 0;
}

// http://www.geeksforgeeks.org/how-to-deallocate-memory-without-using-free-in-c/
// https://www.gnu.org/software/libc/manual/html_node/Changing-Block-Size.html#Changing-Block-Size
