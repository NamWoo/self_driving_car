/***************************************

 * Filename: sk.c

 * Title: Skeleton Device

 * Desc: Implementation of system call

 ***************************************/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL");

#define rGPGCON *(volatile unsigned long *)(kva)
#define rGPGDAT *(volatile unsigned long *)(kva + 4)

static int sk_major = 0, sk_minor = 0;
static int result;
static dev_t sk_dev;
static void *kva;

static struct cdev sk_cdev;

static int sk_register_cdev(void);

/* TODO: Define Prototype of functions */
static int sk_open(struct inode *inode, struct file *filp);
static int sk_release(struct inode *inode, struct file *filp);
static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
/* TODO: Implementation of functions */
static int sk_open(struct inode *inode, struct file *filp)
{
    printk("Device has been opened...\n");
    return 0;
}

static int sk_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");
	return 0;
}

static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    int i;
    for(i=0;i<10;i++) {
        rGPGDAT &= ~(0xf << 4); // LED ON
        mdelay(1000);
        rGPGDAT |= (0xf << 4);
        mdelay(1000);
    }
	return count;
}

struct file_operations sk_fops = { 
    .open       = sk_open,
    .release    = sk_release,
    .write      = sk_write,
};

static int __init sk_init(void)
{
    printk("SK Module is up... \n");

    kva = ioremap(0x56000060,32);
    printk("kva = 0x%x\n",(int)kva);	
    // LED init
    rGPGDAT |= 0xf << 4;
    rGPGCON &= ~(0xff << 8);
    rGPGCON |= 0x55 << 8;   

    if((result = sk_register_cdev()) < 0)
    {
        return result;
    }
    return 0;
}

static void __exit sk_exit(void)
{
    printk("The module is down...\n");
    cdev_del(&sk_cdev);
    unregister_chrdev_region(sk_dev, 1);
}

static int sk_register_cdev(void)
{
    int error;
    /* allocation device number */
    if(sk_major) {
        sk_dev = MKDEV(sk_major, sk_minor);
        error = register_chrdev_region(sk_dev, 1, "sk");
    } else {
        error = alloc_chrdev_region(&sk_dev, sk_minor, 1, "sk");
        sk_major = MAJOR(sk_dev);
    }

    if(error < 0) {
        printk(KERN_WARNING "sk: can't get major %d\n", sk_major);
        return result;
    }

    printk("major number=%d\n", sk_major);
    
    /* register chrdev */
    cdev_init(&sk_cdev, &sk_fops);
    sk_cdev.owner = THIS_MODULE;
    sk_cdev.ops = &sk_fops;
    error = cdev_add(&sk_cdev, sk_dev, 1);
    
    if(error)
        printk(KERN_NOTICE "sk Register Error %d\n", error);

    return 0;
}

module_init(sk_init); 
module_exit(sk_exit); 