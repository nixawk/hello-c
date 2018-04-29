#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for module_refcount");

static int __init module_refcount_init(void);
static void __exit module_refcount_exit(void);

static int
__init module_refcount_init(void)
{
        // THIS_MODULE means current module
        printk(KERN_INFO "module_refcount(THIS_MODULE) = %d\n", module_refcount(THIS_MODULE));
        return 0;
}

static void
__exit module_refcount_exit(void)
{
        printk(KERN_INFO "module exits ok!\n");
}

module_init(module_refcount_init);
module_exit(module_refcount_exit);
