#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for kmalloc");

static int __init kmalloc_init(void);
static void __exit kmalloc_exit(void);
void *addr = NULL;
#define SIZE 4096

static int
__init kmalloc_init(void)
{
	addr = kmalloc(SIZE, GFP_KERNEL);
	if (!addr) {
		printk("failed to kmalloc\n");
		return -ENOMEM;
	}
	printk("kmalloc successfully\naddr=0x%p\n", addr);

	return 0;
}

static void
__exit kmalloc_exit(void)
{
	if (addr) {
		kfree(addr);
		printk("kfree successfully\n");
	}
	printk("module exits ok !\n");
}

module_init(kmalloc_init);
module_exit(kmalloc_exit);

// https://elixir.bootlin.com/linux/latest/source/include/linux/slab.h#L500

/*

# dmesg -k -w

[ 1074.230603] kmalloc successfully
               addr=0x000000004cfacbdf
[ 1075.732545] kfree successfully
[ 1075.732545] module exits ok !

*/
