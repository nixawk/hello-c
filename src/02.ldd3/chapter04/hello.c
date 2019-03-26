#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
	printk(KERN_INFO "This is a info message\n");
	printk(KERN_DEBUG "This is a debug message\n");
	return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);

/* https://elixir.bootlin.com/linux/v5.0.4/source/include/linux/kern_levels.h#L14 */

