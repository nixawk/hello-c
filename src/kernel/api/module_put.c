#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for module_put");

static int __init module_put_init(void);
static void __exit module_put_exit(void);

static int
__init module_put_init(void)
{
        struct module *kmodule;
        const char *kmodule_name = "ext4";

        kmodule = find_module(kmodule_name);
        if (kmodule != NULL)
        {
                printk(KERN_INFO "before module refcount: %d\n", module_refcount(kmodule));
                module_put(kmodule);
                printk(KERN_INFO "after  module refcount: %d\n", module_refcount(kmodule));
        }
        else
        {
                printk(KERN_ERR "failed to find_module %s\n", kmodule_name);
        }

        return 0;
}

static void
__exit module_put_exit(void)
{
        printk(KERN_INFO "module exits ok!\n");
}

module_init(module_put_init);
module_exit(module_put_exit);
