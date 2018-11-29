#include <obstack.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// void * obstack_copy (struct obstack *obstack-ptr, void *address, int size)

// This allocates a block and initializes it by copying size  bytes of data
// starting at address. It calls obstack_alloc_failed_handler if allocation
// of memory by obstack_chunk_alloc failed.

// void * obstack_copy0 (struct obstack *obstack-ptr, void *address, int size)

// Like obstack_copy, but appends on extra byte containing a null character.
// This extra byte is not counted in the argument size.

#define obstack_chunk_alloc malloc
#define obstack_chunk_free free

void obstack_copy_usage(void)
{
	struct obstack obstack_string;
	obstack_init(&obstack_string);

	char *src = "hello, world";
	char *dst = (char *)obstack_copy(&obstack_string, src, strlen(src) + 1);

	printf("dst string: %s\n", dst);

	obstack_free(&obstack_string, dst);
}

int main(void)
{
	obstack_copy_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Allocation-in-an-Obstack
