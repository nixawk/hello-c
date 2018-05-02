#include <linux/module.h>
#include <linux/init.h>
#include <linux/gfp.h>
#include <linux/mm_types.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for alloc_pages_exact");

static int __init alloc_pages_exact_init(void);
static void __exit alloc_pages_exact_exit(void);
void *pages = NULL;
#define SIZE 8092

static int
__init alloc_pages_exact_init(void)
{
        pages = alloc_pages_exact(SIZE, GFP_KERNEL);
        if (!pages)
        {
                printk("alloc_pages_exact failed !\n");
                return -ENOMEM;
        }

        printk("alloc_pages_exact successfully !\n");
        printk("page_address(pages) = 0x%lx\n", (unsigned long)page_address(pages));

        return 0;
}

static void
__exit alloc_pages_exact_exit(void)
{
        if (pages)
        {
                free_pages_exact(pages, SIZE);
                printk("__free_pages_exact ok!\n");
        }
        printk("module exits ok !\n");
}

module_init(alloc_pages_exact_init);
module_exit(alloc_pages_exact_exit);

// https://elixir.bootlin.com/linux/latest/source/include/linux/gfp.h#L517
