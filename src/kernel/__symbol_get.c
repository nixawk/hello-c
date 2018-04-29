#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __symbol_get");

static int __init __symbol_get_init(void);
static void __exit __symbol_get_exit(void);

static int
__init __symbol_get_init(void)
{
	const char * symbol_name;
	void * addr;

	symbol_name = "init_module";
	addr = __symbol_get(symbol_name);

	if (addr != NULL)
		printk(KERN_INFO "the address of %s is: %lx\n", symbol_name,
			(unsigned long)addr);
	else
	printk("%s isn't found\n", symbol_name);

	symbol_name = "cleanup_module";
	addr = __symbol_get(symbol_name);

	if (addr != NULL)
		printk(KERN_INFO "the address of %s is: %lx\n", symbol_name,
			(unsigned long)addr);
	else
	printk("%s isn't found\n", symbol_name);

	return 0;
}

static void
__exit __symbol_get_exit(void)
{
	printk(KERN_INFO "module exit ok !\n");
}

module_init(__symbol_get_init);
module_exit(__symbol_get_exit);


/*

# nm -g /lib/modules/`uname -r`/kernel/fs/ext4/ext4.ko

*/
