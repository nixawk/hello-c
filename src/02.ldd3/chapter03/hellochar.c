/* OS     : Arch Linux */
/* Kernel : 5.0.3      */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/cdev.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ldd3");
MODULE_DESCRIPTION("This is a char device");

#ifndef DEV_MAJOR
#define DEV_MAJOR 0
#endif

#ifndef DEV_COUNT
#define DEV_COUNT 4
#endif

static int __init hello_init(void);
static void __exit hello_exit(void);
static void setup_cdev(struct cdev *dev, int index);

ssize_t dev_read(struct file *filp, char __user * buf, size_t count,
		 loff_t * f_pos);
ssize_t dev_write(struct file *filp, const char __user * buf, size_t count,
		  loff_t * f_pos);
static int dev_open(struct inode *inod, struct file *fil);
static int dev_release(struct inode *inod, struct file *fil);

int dev_major = DEV_MAJOR;	/* device major version */
int dev_minor = 0;		/* device minor version */
int dev_count = DEV_COUNT;	/* device count */
const char *name = "hellochar";	/* device name */
struct cdev *cdevs;

struct file_operations dev_fops = {
read:	dev_read,
write:	dev_write,
open:	dev_open,
release:dev_release,
owner:	THIS_MODULE
};

module_param(dev_major, int, S_IRUGO);
module_param(dev_minor, int, S_IRUGO);
module_param(dev_count, int, S_IRUGO);

ssize_t dev_read(struct file *filp, char __user * buf, size_t count,
		 loff_t * f_pos)
{
	printk(KERN_INFO "NAME: %s, METHOD: dev_read, MAJOR: %d, MINOR: %d\n",
	       name, MAJOR(filp->f_inode->i_rdev), MINOR(filp->f_inode->i_rdev)
	    );

	return count;
}

ssize_t dev_write(struct file *filp, const char __user * buf, size_t count,
		  loff_t * f_pos)
{
	printk(KERN_INFO "NAME: %s, METHOD: dev_write, MAJOR: %d, MINOR: %d\n",
	       name, MAJOR(filp->f_inode->i_rdev), MINOR(filp->f_inode->i_rdev)
	    );

	return count;
}

static int dev_open(struct inode *inod, struct file *fil)
{
	printk(KERN_INFO "NAME: %s, METHOD: dev_open, MAJOR: %d, MINOR: %d\n",
	       name, imajor(inod), iminor(inod)
	    );
	return 0;

}

static int dev_release(struct inode *inod, struct file *fil)
{
	printk(KERN_INFO
	       "NAME: %s, METHOD: dev_release, MAJOR: %d, MINOR: %d\n", name,
	       imajor(inod), iminor(inod)
	    );

	return 0;
}

static void setup_cdev(struct cdev *dev, int index)
{
	int err;
	int devno = MKDEV(dev_major, dev_minor + index);

	cdev_init(dev, &dev_fops);
	dev->ops = &dev_fops;
	dev->owner = THIS_MODULE;

	err = cdev_add(dev, devno, 1);
	if (err)
		printk(KERN_NOTICE "%s: can't add %d device\n", name, index);
}

static int __init hello_init(void)
{
	int result;
	int i;
	dev_t dev = 0;

	if (dev_major) {
		dev = MKDEV(dev_major, dev_minor);
		result = register_chrdev_region(dev, dev_count, name);
	} else {
		result = alloc_chrdev_region(&dev, dev_minor, dev_count, name);
		dev_major = MAJOR(dev);
	}

	if (result < 0) {
		printk(KERN_WARNING "%s: can't get major %d\n", name,
		       dev_major);
		return result;
	}

	printk(KERN_INFO "NAME: %s, METHOD: hello_init, MAHOR: %d, MINOR: %d\n",
	       name, dev_major, dev_minor);

	cdevs = kmalloc(dev_count * sizeof(struct cdev), GFP_KERNEL);
	if (!cdevs) {
		result = -ENOMEM;
		goto fail;
	}

	memset(cdevs, 0, dev_count * sizeof(struct cdev));

	for (i = 0; i < dev_count; i++) {
		setup_cdev(&cdevs[i], i);
	}

	return 0;		/* success */

fail:
	hello_exit();
	return result;
}

static void __exit hello_exit(void)
{
	int i;
	dev_t devno = MKDEV(dev_major, dev_minor);

	if (cdevs) {
		for (i = 0; i < dev_count; i++) {
			cdev_del(&cdevs[i]);
		}
		kfree(cdevs);
	}
	unregister_chrdev_region(devno, dev_count);

	printk(KERN_INFO "NAME: %s, METHOD: hello_exit, MAHOR: %d, MINOR: %d\n",
	       name, dev_major, dev_minor);
}

module_init(hello_init);
module_exit(hello_exit);

/* https://lwn.net/Kernel/LDD3/ */
