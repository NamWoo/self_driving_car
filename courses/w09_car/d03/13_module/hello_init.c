#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO	*/
#include <linux/init.h>		/* Needed for the macros */

///interrupt
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/de lay.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <mach/gpio.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>

#define DRV_NAME "keyint"
///
#define	DRIVER_AUTHOR	"DongKyu, Kim <dongkyu@mdstec.com>"
#define	DRIVER_DESC		"A sample driver"




static irqreturn_t keyinterrupt_func (int irq, void *dev_id, struct pt_regs *regs)
{
	printk(" \nkeypad was pressed \n");

	return IRQ_HANDLED;
}

static int _init keyint_init(void)
{
	int ret;

	// set Interrupt mode
	s3c_gpio_cfgpin(S3C2410_GPF(0), S3C_GPIO_SFN(2));

	if( request_irq(IRQ_EINT0, (void *)keyinterrupt_func, IRQF_DISABLEDI IRQF_TRIGGER_FALLING, DRV_NAME, NULL) )
	{
		printk( "failed to request external interrupt.\n" );
		ret = -ENDENT;
		return ret;
	}
	printk(KERN_INFD "%s successfully loaded\n" , DRV_NAME};	
	return 0;
}

static void _exit keyint_exit(void)
{
	free_irq(IRQ_EINT0, NULL);\

	printk(KERN_INFO "%s successfully removed\n", DRV_NAME );
}

MODULE_LICENSE("GPL");
module_init(keyint_init);
module_exit(keyint_exit);

// module_init(init_hello_4);
// module_exit(cleanup_hello_4);


static int __init init_hello_4(void)
{
	printk(KERN_INFO "Hello, world 4.\n");
	return 0;
}

static void __exit cleanup_hello_4(void)
{
	printk(KERN_INFO "Goodbye, world 4.\n");
}




/* Get rid of taint message by declaring code as GPL. */

MODULE_AUTHOR(DRIVER_AUTHOR);		/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
MODULE_SUPPORTED_DEVICE("testdevice");
