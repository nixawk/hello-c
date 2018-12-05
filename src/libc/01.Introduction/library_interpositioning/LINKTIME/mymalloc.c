#ifdef LINKTIME
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

/* malloc wrapper function */
void *__wrap_malloc(size_t size)
{
	void *ptr = __real_malloc(size);	/* Call libc malloc */
	printf("malloc(%zu) = %p\n", size, ptr);
	return ptr;
}

/* free wrapper function */
void __wrap_free(void *ptr)
{
	__real_free(ptr);
	printf("free(%p)\n", ptr);
}

#endif
