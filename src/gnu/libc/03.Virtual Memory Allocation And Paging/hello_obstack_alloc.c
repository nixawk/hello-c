#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <obstack.h>

// void * obstack_alloc (struct obstack *obstack-ptr, int size)

// This allocates are uninitialized block of size bytes in an obstack and
// returns its address. Here [obstack-ptr] specifies which obstack to allocate
// the block in; it is the address of the struct obstack object which
// represents the obstack. Each obstack function or macro requires you to
// speecify an obstack-ptr as the first argument.

#define obstack_chunk_alloc malloc
#define obstack_chunk_free free

struct obstack string_obstack;


char *
copystring(char *string)
{
    size_t len = strlen(string) + 1;
    printf("str len : %lu\n", len);

    // If not init, prog crashes.
    obstack_init(&string_obstack);

    char *s = (char *)obstack_alloc(&string_obstack, len);
    printf("str addr: %p\n", s);
    memcpy(s, string, len);
    return s;
}


void
obstack_alloc_usage(void)
{
    char *src = "hello, world";
    char *dst = copystring(src);

    printf("dst string: %s\n", dst);
}


int
main(void)
{
    obstack_alloc_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Allocation-in-an-Obstack