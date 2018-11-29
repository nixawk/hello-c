#include <linux/module.h>
#include <linux/init.h>
#include <linux/gfp.h>
#include <linux/mm_types.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for alloc_pages");

static int __init alloc_pages_init(void);
static void __exit alloc_pages_exit(void);
struct page *pages = NULL;

static int
__init alloc_pages_init(void)
{
	pages = alloc_pages(GFP_KERNEL, 3);
	if (!pages) {
		return -ENOMEM;
	}

	printk("alloc_pages successfully !\n");
	printk("page_address(pages) = 0x%lx\n",
	       (unsigned long)page_address(pages));

	return 0;
}

static void
__exit alloc_pages_exit(void)
{
	if (pages) {
		__free_pages(pages, 3);
		printk("__free_pages ok!\n");
	}
	printk("module exits ok !\n");
}

module_init(alloc_pages_init);
module_exit(alloc_pages_exit);
