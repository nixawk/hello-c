#ifdef COMPILETIME

#include <stdio.h>
#include <malloc.h>

/* malloc wrapper function */
void *mymalloc(size_t size)
{
	void *ptr = malloc(size);
	printf("malloc(%zu)=%p\n", size, ptr);
	return ptr;
}

/* free wrapper function */
void myfree(void *ptr)
{
	free(ptr);
	printf("free(%p)\n", ptr);
}

#endif // library interpositioning
