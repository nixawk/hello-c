#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __symbol_put");

static int __init __symbol_put_init(void);
static void __exit __symbol_put_exit(void);

static int
__init __symbol_put_init(void)
{
	const char *symbol_name;
	const char *mod_name;
	struct module *fmodule;

	symbol_name = "symbol_A";
	mod_name = "test_module";

	fmodule = find_module(mod_name);
	if (fmodule != NULL) {
		printk(KERN_INFO "before calling __symbol_put,\n");
		printk(KERN_INFO "ret of %s is: %d\n", mod_name,
		       module_refcount(fmodule));

		__symbol_put(symbol_name);

		printk(KERN_INFO "after calling __symbol_put,\n");
		printk(KERN_INFO "ref of %s is: %d\n", mod_name,
		       module_refcount(fmodule));
	} else {
		printk("find %s failed!\n", mod_name);
	}

	return 0;
}

static void
__exit __symbol_put_exit(void)
{
	printk(KERN_INFO "module exits ok !\n");
}

module_init(__symbol_put_init);
module_exit(__symbol_put_exit);
