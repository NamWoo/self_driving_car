#include <linux/module.h>
#include <linux/init.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/slab.h>   /* kmalloc() */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */

#define DEVICE_NAME "timerTest"
#define GPGCON *(volatile unsigned long *)(kva)
#define GPGDAT *(volatile unsigned long *)(kva + 4)

struct timer_list timer;
static int timerTest_major = 0, timerTest_minor = 0;
static int result;
static dev_t timerTest_dev;
static void *kva;

static struct cdev timerTest_cdev;

static int timerTest_register_cdev(void);

/* TODO: Define Prototype of functions */
static int timerTest_open(struct inode *inode, struct file *filp);
static int timerTest_release(struct inode *inode, struct file *filp);
static int timerTest_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int timerTest_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);

void my_timer(unsigned long data)
{
	int i;
	for(i=1; i<=data; i++) {
		printk("Kernel Timer Time-Out Function Doing_%d...\n", i);
	}
	GPGDAT ^= (0xf << 4);

	timer.expires = jiffies + 2*HZ;
	add_timer(&timer);

	printk("Kernel Timer Time-Out Function Done!!!\n");
}

int timerTest_init(void)
{
	
	printk(KERN_INFO "timerTest Module is Loaded!! ....\n");

	if((result = timerTest_register_cdev()) < 0)
	{
		return result;
	}

    init_timer(&timer);
	//timer.expires = get_jiffies_64() + 3*HZ;
	timer.expires = jiffies + 3*HZ;
	timer.function = my_timer;
	timer.data = 5;

    /* H/W Initalization */
    kva = ioremap(0x56000060, 16);
    printk("kva = 0x%x\n", (int)kva);
    
    GPGDAT |= 0xf << 4;

    GPGCON &= ~(0xff << 8);
    GPGCON |= 0x55 << 8;

	add_timer(&timer);
	return 0;
}
/* TODO: Implementation of functions */
static int timerTest_open(struct inode *inode, struct file *filp)
{
    printk("Device has been opened...\n");

//    add_timer(&timer);
    
    return 0;
}

static int timerTest_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");
    
    return 0;
}

static int timerTest_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	printk("timerTest_write is invoked\n");
	
	return count;
}

static int timerTest_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	  printk("timerTest_read is invoked\n");
	  return 0;
}

 
struct file_operations timerTest_fops = { 
    .open       = timerTest_open,
    .release    = timerTest_release,
	.write		= timerTest_write,
	.read		= timerTest_read,
};

void timerTest_exit(void)
{
	del_timer(&timer);
	printk("timerTest Module is Unloaded ....\n");
}

static int timerTest_register_cdev(void)
{
	int error;

	/* allocation device number */
	if(timerTest_major) {
		timerTest_dev = MKDEV(timerTest_major, timerTest_minor);
		error = register_chrdev_region(timerTest_dev, 1, "timerTest");
	} else {
		error = alloc_chrdev_region(&timerTest_dev, timerTest_minor, 1, "timerTest");
		timerTest_major = MAJOR(timerTest_dev);
	}

	if(error < 0) {
		printk(KERN_WARNING "timerTest: can't get major %d\n", timerTest_major);
		return result;
	}
	printk("major number=%d\n", timerTest_major);

	/* register chrdev */
	cdev_init(&timerTest_cdev, &timerTest_fops);
	timerTest_cdev.owner = THIS_MODULE;
	timerTest_cdev.ops = &timerTest_fops;
	error = cdev_add(&timerTest_cdev, timerTest_dev, 1);

	if(error)
		printk(KERN_NOTICE "timerTest Register Error %d\n", error);

	return 0;
}

module_init(timerTest_init);
module_exit(timerTest_exit);

MODULE_LICENSE("Dual BSD/GPL");


/*
 #tail -f /var/log/messages
*/