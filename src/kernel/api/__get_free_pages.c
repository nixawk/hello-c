#include <linux/module.h>
#include <linux/gfp.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __get_free_pages");

static int __init __get_free_pages_init(void);
static void __exit __get_free_pages_exit(void);
const unsigned int order = 3;	// pages num
unsigned long address;

static int
__init __get_free_pages_init(void)
{
	address = __get_free_pages(GFP_KERNEL, order);
	if (!address)
		return -ENOMEM;
	else
		printk("__get_free_pages successfully!,\naddress = 0x%lx\n",
		       address);

	return 0;
}

static void
__exit __get_free_pages_exit(void)
{
	if (address) {
		free_pages(address, 3);
		printk("free_pages ok!\n");
	}
	printk("module exits ok !\n");
}

module_init(__get_free_pages_init);
module_exit(__get_free_pages_exit);

// References
// https://elixir.bootlin.com/linux/v4.16.6/source/include/linux/gfp.h#L513
