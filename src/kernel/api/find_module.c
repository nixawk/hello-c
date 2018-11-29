#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("Module for __find_module");

static int __init __find_module_init(void);
static void __exit __find_module_exit(void);

static int
__init __find_module_init(void)
{
	const char *module_name;
	struct module *fmodule;

	module_name = "ext4";
	fmodule = find_module(module_name);
	if (fmodule != NULL) {
		printk(KERN_INFO "module->name: %s\n", fmodule->name);
	} else {
		printk(KERN_ERR "failed to find module !\n");
	}

	return 0;
}

static void
__exit __find_module_exit(void)
{
	printk(KERN_INFO "module exits ok !\n");
}

module_init(__find_module_init);
module_exit(__find_module_exit);
