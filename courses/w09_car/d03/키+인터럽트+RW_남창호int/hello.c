#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO	*/
#include <linux/init.h>		/* Needed for the macros */
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <mach/gpio.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/types.h>

//#define	DRIVER_AUTHOR	"DongKyu, Kim <dongkyu@mdstec.com>"
//#define	DRIVER_DESC		"A sample driver"
#define DRV_NAME "keyint"

static int keyint_major = 0, keyint_minor = 0;
static int result;
static dev_t keyint_dev;
static char kin_buf[50];
static char kout_buf[50];

static struct cdev keyint_cdev;

static int keyint_register_cdev(void);

static int keyint_open(struct inode *inode, struct file *filp);
static int keyint_release(struct inode *inode, struct file *filp);
static int keyint_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int keyint_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);

static int keyint_open(struct inode *inode, struct file *filp)
{
    printk("Device has been opened...\n");
    
	
    /* H/W Initalization */

    return 0;
}

static int keyint_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");

    return 0;
}

static int keyint_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	printk("keyint_write is invoked\n");

	copy_from_user(kin_buf, buf, count);
	printk("What kernel's heard from app : %s\n", kin_buf);

	return count;
}

static int keyint_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	printk("keyint_read is invoked\n");
	
	copy_to_user(buf, kout_buf, count);
	
	return 0;
}

static  irqreturn_t keyinterrupt_func0(int irq, void *dev_id, struct pt_regs *regs)
{
	printk("\nkeypad0 was pressed \n");
	strcpy(kout_buf, "I'm Key0");
	//kout_buf = "I'm Key1";
	return IRQ_HANDLED;
}

static  irqreturn_t keyinterrupt_func1(int irq, void *dev_id, struct pt_regs *regs)
{
	printk("\nkeypad1 was pressed \n");
	strcpy(kout_buf, "I'm Key1");
	//kout_buf = "I'm Key2";
	return IRQ_HANDLED;
}

struct file_operations keyint_fops = { 
    .open       = keyint_open,
    .release    = keyint_release,
	.write		= keyint_write,
	.read		= keyint_read,
};

static int keyint_register_cdev(void)
{
	int error;

	/* allocation device number */
	if(keyint_major) {
		keyint_dev = MKDEV(keyint_major, keyint_minor);
		error = register_chrdev_region(keyint_dev, 1, "keyint");
	} else {
		error = alloc_chrdev_region(&keyint_dev, keyint_minor, 1, "keyint");
		keyint_major = MAJOR(keyint_dev);
	}

	if(error < 0) {
		printk(KERN_WARNING "keyint: can't get major %d\n", keyint_major);
		return result;
	}
	printk("major number=%d\n", keyint_major);

	/* register chrdev */
	cdev_init(&keyint_cdev, &keyint_fops);
	keyint_cdev.owner = THIS_MODULE;
	keyint_cdev.ops = &keyint_fops;
	error = cdev_add(&keyint_cdev, keyint_dev, 1);

	if(error)
		printk(KERN_NOTICE "keyint Register Error %d\n", error);

	return 0;
}

static int __init keyint_init(void)
{
	int ret;

	printk("keyint Module is up... \n");
	if((result = keyint_register_cdev()) < 0)
	{
		return result;
	}

	//set Interrupt mode
	s3c_gpio_cfgpin(S3C2410_GPF(0), S3C_GPIO_SFN(2));
	s3c_gpio_cfgpin(S3C2410_GPF(1), S3C_GPIO_SFN(2));

	if(request_irq(IRQ_EINT0, (void *)keyinterrupt_func0, IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL))
	{
		printk("failed to request external interrupt.\n");
		ret = -ENOENT;
		return ret;
	}
	if(request_irq(IRQ_EINT1, (void *)keyinterrupt_func1, IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL))
	{
		printk("failed to request external interrupt.\n");
		ret = -ENOENT;
		return ret;
	}
	printk(KERN_INFO "%s successfully loaded\n", DRV_NAME);
}

static void __exit keyint_exit(void)
{
	free_irq(IRQ_EINT0, NULL);
	free_irq(IRQ_EINT1, NULL);

	printk(KERN_INFO "%s successfully removed\n", DRV_NAME);
}

module_init(keyint_init);
module_exit(keyint_exit);
/* Get rid of taint message by declaring code as GPL. */
MODULE_LICENSE("GPL");

//MODULE_AUTHOR(DRIVER_AUTHOR);		/* Who wrote this module? */
//MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
//MODULE_SUPPORTED_DEVICE("testdevice");

