#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for try_module_get");

static int __init try_module_get_init(void);
static void __exit try_module_get_exit(void);

static int
__init try_module_get_init(void)
{
	printk(KERN_INFO "before module_refcount: %d\n",
	       module_refcount(THIS_MODULE));
	try_module_get(THIS_MODULE);	// module_refcount += 1
	printk(KERN_INFO "after module_refcount: %d\n",
	       module_refcount(THIS_MODULE));
	module_put(THIS_MODULE);	// module_refcount -= 1

	return 0;
}

static void
__exit try_module_get_exit(void)
{
	printk(KERN_INFO "module exits ok!\n");
}

module_init(try_module_get_init);
module_exit(try_module_get_exit);
