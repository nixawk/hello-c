#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// If no more space is available, malloc returns a null pointer. You should
// check the value of every call to malloc. It is useful to write a subroutine
// that calls malloc and reports an error if the value is a null pointer,
// returning only if the value is nonzero. This function is conventionally
// called xmalloc. Here it is:

static void fatal(char *fmt, ...)
{
	va_list list;

	va_start(list, fmt);
	vfprintf(stderr, fmt, list);
	va_end(list);

	exit(1);
}

void *xmalloc(size_t size)
{
	void *value = malloc(size);
	if (value == 0)
		fatal("virtual memory exhausted");
	return value;
}

int main(void)
{
	char *ptr = xmalloc(32);
	free(ptr);
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Malloc-Examples
// https://elixir.free-electrons.com/linux/latest/source/arch/um/os-Linux/start_up.c#L73
