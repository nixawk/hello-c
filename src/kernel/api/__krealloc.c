#include <linux/module.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __krealloc");

static int __init __krealloc_init(void);
static void __exit __krealloc_exit(void);
struct page *pages = NULL;
#define PAGE_NUM 0		// 2 ** 0
#define NEW_SIZE 26

static int
__init __krealloc_init(void)
{
	char *temp, *addr;
	char ch;
	int i;

	pages = alloc_pages(GFP_KERNEL, PAGE_NUM);
	if (!pages) {
		printk("alloc_pages failed!\n");
		return -ENOMEM;
	}

	temp = (char *)page_address(pages);
	*temp = 'a';

	for (i = 0; i < NEW_SIZE; i++) {
		ch = *temp;
		temp++;
		*temp = ch + 1;	// 'b' = 'a' + 1;
	}

	addr = __krealloc(page_address(pages), NEW_SIZE, GFP_KERNEL);
	if (!addr) {
		printk("__krealloc failed!\n");
		return -ENOMEM;
	}

	printk("addr = 0x%lx\n", (unsigned long)addr);
	printk("*addr = %c\n", *addr);
	printk("*addr + 4 = %c\b", *(addr + 4));

	temp = addr;
	for (i = 0; i < NEW_SIZE; i++) {
		printk("%c", *temp);
		temp++;
	}

	return 0;
}

static void
__exit __krealloc_exit(void)
{
	if (pages) {
		__free_pages(pages, PAGE_NUM);
		printk("__free_pages\n");
	}

	printk("module exits ok !\n");
}

module_init(__krealloc_init);
module_exit(__krealloc_exit);

// https://elixir.bootlin.com/linux/latest/source/include/linux/slab.h#L180

/*

[   43.302456] addr = 0xffff92a8d502d000
[   43.302456] *addr = a
[   43.302457] *addr + 4 = e
[   43.302457] a
[   43.302457] b
[   43.302458] c
[   43.302458] d
[   43.302458] e
[   43.302459] f
[   43.302459] g
[   43.302459] h
[   43.302460] i
[   43.302460] j
[   43.302460] k
[   43.302461] l
[   43.302461] m
[   43.302461] n
[   43.302462] o
[   43.302462] p
[   43.302462] q
[   43.302463] r
[   43.302463] s
[   43.302463] t
[   43.302464] u
[   43.302464] v
[   43.302464] w
[   43.302465] x
[   43.302465] y
[   43.302465] z
[   50.525465] __free_pages
[   50.525465] module exits ok !

*/
