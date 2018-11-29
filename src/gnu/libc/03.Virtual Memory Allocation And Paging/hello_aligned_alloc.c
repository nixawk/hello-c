#include <stdio.h>
#include <stdlib.h>

// The address of a block returned by malloc or realloc in GNU systems is
// always a multiple of eight (or sixteen on 64-bit systems). If you need
// a block whose address is a multiple of a higher power of two than that,
// use [aligned_alloc] or [posix_memalign.aligned_alloc] and posix_memalign
// are declared in [stdlib.h]

// void * aligned_alloc (size_t alignment, size_t size)

// The aligned_alloc function allocates a block of size bytes whose address
// is a multiple of alignment. The alignment must be a power of two and size
// must be a multiple of alignment.

// The aligned_alloc function returns a null pointer on error and sets errno
// to one of the following values:

    // ENOMEM - There was insufficient memory available to satisfy the request.
    // EINVAL - alignment is not a power of two. 

void aligned_alloc_usage()
{
	int *p1 = malloc(10 * sizeof(*p1));
	printf("default-aligned addr: %p\n", (void *)p1);
	free(p1);

	int *p2 = aligned_alloc(1024, 1024 * sizeof(*p2));
	printf("1024-byte aligned addr: %p\n", (void *)p2);
	free(p2);
}

int main(void)
{
	aligned_alloc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Aligned-Memory-Blocks
// http://en.cppreference.com/w/c/memory/aligned_alloc
