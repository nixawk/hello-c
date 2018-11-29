#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for module_is_live");

static int __init module_is_live_init(void);
static void __exit module_is_live_exit(void);

static int
__init module_is_live_init(void)
{
	struct module *kmodule;
	const char *kmodule_name;

	kmodule_name = "ext4";
	kmodule = find_module(kmodule_name);
	if (kmodule != NULL && module_is_live(kmodule)) {
		printk(KERN_INFO "%s module is live!\n", kmodule_name);
	} else {
		printk(KERN_ERR "failed to find alive module ext4!\n");
	}

	return 0;
}

static void
__exit module_is_live_exit(void)
{
	printk(KERN_INFO "module exits ok!\n");
}

module_init(module_is_live_init);
module_exit(module_is_live_exit);
