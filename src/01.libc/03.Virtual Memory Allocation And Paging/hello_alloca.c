#include <alloca.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

    // void * alloca (size_t size)

// The function alloca supports a kind of half-dynamic allocation in which
// blocks as you wish, and compute the size at run time. But all the blocks
// are freed when you exit the function that alloca was called from, just
// as if they were automatic variables declared in that function. There is
// no way to free the space explicitly.

// Do not use alloca inside the arguments of a function call - you will get
// unpredictable results, because the stack space for the alloca would
// appear on the stack in the middle of the space for the function arguments.
// An example of what to avoid is 

    // foo (x, alloca (4), y)

// These are the disadvantages of alloca in comparison with malloc:

// If you try to allocate more memory than the machine can provide, you don't
// get a clean error message. Instead you get a fatal signal like the one
// you would get from an infinite recursion; probably a segmentation violation.

// Some non-GNU systems fail to support alloca, so it is less portable.
// However, a slower emulation of alloca written in C is available for use
// on systems with this deficiency.

#define BUFSIZE 512

void alloca_usage(void)
{
	char *src = "hello, world";
	char *dst = (char *)alloca(BUFSIZE);
	memcpy(dst, src, strlen(src) + 1);

	printf("dst string: %s\n", dst);
}

int main(void)
{
	alloca_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Allocation-in-an-Obstack
