#include <stdio.h>

// size_t defined in stddef.h

/*

#ifndef _SIZE_T
#define _SIZE_T
typedef __kernel_size_t     size_t;
#endif

typedef unsigned long __kernel_size_t;

*/

void show_size_t(void)
{
	size_t n = 100;
	printf("%lu - %lu bytes\n", n, sizeof(n));	// unsigned long
}

int main(void)
{
	show_size_t();
	return 0;
}

// https://stackoverflow.com/questions/2550774/what-is-size-t-in-c
// http://en.cppreference.com/w/c/types/size_t
// https://elixir.free-electrons.com/linux/latest/source/include/linux/types.h#L55
// https://elixir.free-electrons.com/linux/latest/source/arch/blackfin/include/uapi/asm/posix_types.h#L20
