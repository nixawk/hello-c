#include <linux/module.h>
#include <linux/init.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for vmalloc");

static int __init my_vmalloc_init(void);
static void __exit my_vmalloc_exit(void);
void *addr = NULL;

static int
__init my_vmalloc_init(void)
{
	unsigned long size = 4096;

	addr = vmalloc(size);
	if (!addr) {
		printk("failed to vmalloc\n");
		return -ENOMEM;
	}

	printk("vmalloc successfully,\naddr=0x%p\n", addr);

	return 0;
}

static void
__exit my_vmalloc_exit(void)
{
	if (addr) {
		vfree(addr);
		printk("vfree successfully\n");
	}
	printk("module exits ok !\n");
}

module_init(my_vmalloc_init);
module_exit(my_vmalloc_exit);

// https://elixir.bootlin.com/linux/latest/source/include/linux/vmalloc.h#L71

/*

# dmesg -k -w

[ 1721.424860] vmalloc successfully,
               addr=0x00000000d10d253d
[ 1725.472210] vfree successfully
[ 1725.472211] module exits ok !

*/
