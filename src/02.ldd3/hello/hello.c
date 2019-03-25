/* OS     : Arch Linux */
/* Kernel : 5.0.3      */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LDD3");
MODULE_DESCRIPTION("HELLO LDD3");

static char *whoami = "ldd3";

module_param(whoami, charp, S_IRUGO);

/* __init is a hint to the kernel that the given function is used only at initi
 * -alization time */
static int __init hello_init(void)
{
	printk(KERN_INFO "hello %s\n", whoami);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "bye linux kernel module\n");
}

module_init(hello_init);
module_exit(hello_exit);

/*
 * $ sudo insmod hello.ko
 * $ sudo rmmod hello

   [ 1930.329014] hello: loading out-of-tree module taints kernel.
   [ 1930.329168] hello: module verification failed: signature and/or required key missing - tainting kernel
   [ 1930.330875] hello linux kernel module
   [ 2022.157137] bye linux kernel module

 *
 */
