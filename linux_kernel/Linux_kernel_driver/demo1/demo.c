#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define BASEMINOR 0
#define COUNT 3
#define NAME "chrdev_demo"

dev_t devno;
struct cdev *cdevp = NULL;

int demo_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "---%s---%s---%d---\n", __FILE__, __func__, __LINE__);
    return 0;
}

int demo_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "---%s---%s---%d---\n", __FILE__, __func__, __LINE__);
    return 0;
}

struct file_operations fops =
    {
        .owner = THIS_MODULE,
        .open = demo_open,
        .release = demo_release};

int __init demo_init(void)
{

    // alloc dev_t devno
    int ret;
    ret = alloc_chrdev_region(&devno, BASEMINOR, COUNT, NAME);
    if (ret < 0)
    {
        printk(KERN_ERR "alloc_chrdev_region failed...\n");
        goto ERR1;
    }
    printk(KERN_INFO "major = %d \n",MAJOR(devno));

    // alloc cdev
    cdevp = cdev_alloc();
    if (NULL == cdevp)
    {
        printk(KERN_ERR "cdev_alloc failed...\n");
        ret = -ENOMEM;
        goto ERR2;
    }

    // cdev init
    cdev_init(cdevp, &fops);

    // cdev add
    ret = cdev_add(cdevp, devno, COUNT);
    if (ret < 0)
    {
        printk(KERN_ERR "cdev_add failed...\n");
        goto ERR2;
    }

    printk(KERN_INFO "---%s---%s---%d---\n", __FILE__, __func__, __LINE__);
    return 0;
ERR2:
    unregister_chrdev_region(devno, COUNT);
ERR1:
    return ret;
}

void __exit demo_exit(void)
{
    cdev_del(cdevp);
    unregister_chrdev_region(devno, COUNT);
    printk("---%s---%s---%d---\n", __FILE__, __func__, __LINE__);
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("GPL");