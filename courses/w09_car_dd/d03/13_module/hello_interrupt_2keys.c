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

#define	DRIVER_AUTHOR	"DongKyu, Kim <dongkyu@mdstec.com>"
#define	DRIVER_DESC		"A sample driver"
#define     DRV_NAME                "keyint"

static irqreturn_t keyinterrupt_func1(int irq, void *dev_id, struct pt_regs *resgs)
{
      printk("14 Key pressed....\n");
      return IRQ_HANDLED;
}

static irqreturn_t keyinterrupt_func2(int irq, void *dev_id, struct pt_regs *resgs)
{
      printk("15 Key pressed....\n");
      return IRQ_HANDLED;
}

static int __init init_hello_4(void)
{
	int ret;
        printk("------------------------------\n");
	printk(KERN_INFO "Hell!!!!!!!!!!!!!\n");
    
    // set Interrupt mode
        s3c_gpio_cfgpin(S3C2410_GPF(0), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(1), S3C_GPIO_SFN(2));
        //ioremap 


        if( request_irq(IRQ_EINT0, (void *)keyinterrupt_func1,
                IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL) )
        {
                printk("failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }
        printk(KERN_INFO "%s successfully SW14 loaded\n", DRV_NAME);

        if( request_irq(IRQ_EINT1, (void *)keyinterrupt_func2,
                IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL) )
        {
                printk("failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }
        printk(KERN_INFO "%s successfully SW15 loaded\n", DRV_NAME);

	return 0;
}

static void __exit cleanup_hello_4(void)
{
	printk(KERN_INFO "Go hell!!!!!!!!!!!\n");

        free_irq(IRQ_EINT0, NULL);
        free_irq(IRQ_EINT1, NULL);

    printk(KERN_INFO "%s successfully removed\n", DRV_NAME);
    printk("------------------------------\n");

}

module_init(init_hello_4);
module_exit(cleanup_hello_4);
/* Get rid of taint message by declaring code as GPL. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);		/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
MODULE_SUPPORTED_DEVICE("testdevice");
