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
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/major.h>
#include <asm/uaccess.h>

#define	DRIVER_AUTHOR	"DongKyu, Kim <dongkyu@mdstec.com>"
#define	DRIVER_DESC		"A sample driver"
#define     DRV_NAME                "keyint"
#define     DEV_LED_MAJOR         241
#define     DEV_LED_NAME          "g2450_led"

static int g2450_led_open(struct inode *inode, struct file *filp)
{
    return 0;
}

static int g2450_led_release(struct inode *inode, struct file *filp)
{
    return 0;
}

static int sk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	char data[20] = "this is read func...";
	copy_to_user(buf, data, count);
	return 0;
}

static irqreturn_t keyinterrupt_func(int irq, void *dev_id, struct pt_regs *resgs)
{
        printk("Key pressed....\n");
      return IRQ_HANDLED;
}

struct file_operations g2450_led_fops = { 
    .open			= g2450_led_open,
    .read		= sk_read,
 };

static int __init init_hello_4(void)
{
	int ret;
	printk(KERN_INFO "Hello, world 4.\n");
    
    // set Interrupt mode
        s3c_gpio_cfgpin(S3C2410_GPF(0), S3C_GPIO_SFN(2));
        register_chrdev(DEV_LED_MAJOR, DEV_LED_NAME, &g2450_led_fops);

        if( request_irq(IRQ_EINT0, (void *)keyinterrupt_func,
                IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL) )
        {
                printk("failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }
        printk(KERN_INFO "%s successfully loaded\n", DRV_NAME);

	return 0;
}

static void __exit cleanup_hello_4(void)
{
	printk(KERN_INFO "Goodbye, world 4.\n");

        free_irq(IRQ_EINT0, NULL);

    printk(KERN_INFO "%s successfully removed\n", DRV_NAME);

}

module_init(init_hello_4);
module_exit(cleanup_hello_4);
/* Get rid of taint message by declaring code as GPL. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);		/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
MODULE_SUPPORTED_DEVICE("testdevice");
