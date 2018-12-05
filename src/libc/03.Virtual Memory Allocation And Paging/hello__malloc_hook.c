/* Prototypes for __malloc_hook, __free_hook */
#include <stdio.h>
#include <malloc.h>

/* Prototypes for our hooks.  */
static void my_init_hook(void);
static void *my_malloc_hook(size_t, const void *);
static void my_free_hook(void *, const void *);

/* Variable to save original hooks */
static void *(*old_malloc_hook) (size_t, const void *);
static void *(*old_free_hook) (size_t, const void *);

static void my_init(void)
{
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
}

static void my_release(void)
{
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;
}

static void *my_malloc_hook(size_t size, const void *caller)
{
	void *result;
	/* Restore all old hooks */
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;
	/* Call recursively */
	result = malloc(size);
	/* Save underlying hooks */
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	/* printf might call malloc, so protect it too. */
	printf("malloc (%u) returns %p\n", (unsigned int)size, result);
	/* Restore our own hooks */
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
	return result;
}

static void my_free_hook(void *ptr, const void *caller)
{
	/* Restore all old hooks */
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;
	/* Call recursively */
	free(ptr);
	/* Save underlying hooks */
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	/* printf might call free, so protect it too. */
	printf("freed pointer %p\n", ptr);
	/* Restore our own hooks */
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
}

int main()
{
	char *ptr = NULL;

	/* init hook */
	my_init();

	ptr = malloc(32);
	free(ptr);

	/* release hook */
	my_release();

}

/*
    $ gcc hello__malloc_hook.c
    $ ./a.out 
    malloc (32) returns 0x55fdd124e010
    freed pointer 0x55fdd124e010
*/

// https://www.gnu.org/software/libc/manual/html_node/Hooks-for-Malloc.html
// https://www.systutorials.com/docs/linux/man/3-malloc_hook/
