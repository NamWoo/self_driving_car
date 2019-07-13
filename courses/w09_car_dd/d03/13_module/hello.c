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

///into driver
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/major.h>

#include <asm/uaccess.h>
///~


#define	DRIVER_AUTHOR	"DongKyu, Kim <dongkyu@mdstec.com>"
#define	DRIVER_DESC		"A sample driver"
#define     DRV_NAME                "keyint"

static struct cdev hell_cdev;
static int hell_register_cdev(void);
static int hell_open(struct inode *inode, struct file *filp);
static int hell_release(struct inode *inode, struct file *filp);
static int hell_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int hell_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);


///

static int hell_major = 0, hell_minor = 0;
static int result;
static dev_t hell_dev;

///

static char kout_buf[50];

///

typedef struct
{
   int age;  //나이 :35
   char name[30];// 이름 : HONG KILDONG
   char address[20]; // 주소 : SUWON CITY
   int  phone_number; // 전화번호 : 1234
   char depart[20]; // 부서 : ELAYER
} __attribute__ ((packed)) mydrv_data;

static mydrv_data* GlobalBuf;


struct file_operations hell_fops = { 
    .open       = hell_open,
    .release    = hell_release,
    .write      = hell_write,
    .read       = hell_read,
};


static irqreturn_t keyinterrupt_func1(int irq, void *dev_id, struct pt_regs *resgs)
{
//   mydrv_data *k_buf;
//   k_buf = kmalloc(kout_buf,GFP_KERNEL);
  
      printk("14 Key pressed....\n");
      printk("age : %d\n",GlobalBuf->age);
//       strcpy(kout_buf, k_buf->age);

      return IRQ_HANDLED;
}

static irqreturn_t keyinterrupt_func2(int irq, void *dev_id, struct pt_regs *resgs)
{
      printk("15 Key pressed....\n");
      printk("name : %s\n", GlobalBuf->name);
   
      return IRQ_HANDLED;
}




static int __init init_hello_4(void)
{
	int ret;
        printk("------------------------------\n");
	printk(KERN_INFO "Let's go hell ya!!!!!!!!!!!!!\n");
    
    //driver
        printk(KERN_INFO "module's up\n");

        if((result = hell_register_cdev()) < 0)
	{
		return result;
	}


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
	printk(KERN_INFO "bye hell\n");

        free_irq(IRQ_EINT0, NULL);
        free_irq(IRQ_EINT1, NULL);
        kfree(GlobalBuf);

        printk("module's down\n");
	cdev_del(&hell_cdev);
	unregister_chrdev_region(hell_dev, 1);

    printk(KERN_INFO "%s successfully removed\n", DRV_NAME);

}

static int hell_register_cdev(void)
{
	int error;

	/* allocation device number */
	if(hell_major) {
		hell_dev = MKDEV(hell_major, hell_minor);
		error = register_chrdev_region(hell_dev, 1, "hell");
	} else {
		error = alloc_chrdev_region(&hell_dev, hell_minor, 1, "hell");
		hell_major = MAJOR(hell_dev);
	}

	if(error < 0) {
		printk(KERN_WARNING "hell: can't get major %d\n", hell_major);
		return result;
	}
	printk("major number=%d\n", hell_major);

	/* register chrdev */
	cdev_init(&hell_cdev, &hell_fops);
	hell_cdev.owner = THIS_MODULE;
	hell_cdev.ops = &hell_fops;
	error = cdev_add(&hell_cdev, hell_dev, 1);

	if(error)
		printk(KERN_NOTICE "hell Register Error %d\n", error);

	return 0;
}

static int hell_release(struct inode *inode, struct file *file)
{
  printk("hell released\n");
  return 0;
}

static int hell_open(struct inode *inode, struct file *file)
{
  printk("hell opened\n");
  return 0;
}


static int hell_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	char data[11];

	copy_from_user(data, buf, count);
	printk("data >>>>> = %s\n", data);

	return count;
}

static int hell_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
  mydrv_data *k_buf;
  
  k_buf = kmalloc(count,GFP_KERNEL);
  k_buf->age = 18;
  sprintf(k_buf->name,"HONG KILDONG");
//   k_buf->name = "HONG KILDONG";
  sprintf(k_buf->address,"SUWON CITY");
  k_buf->phone_number = 121232;
  sprintf(k_buf->depart,"ELAYER");
  
  if(copy_to_user(buf,k_buf,count))
  	return -EFAULT;
  printk("mydrv_read is invoked\n");
  GlobalBuf = k_buf;
//   kfree(k_buf);
  return 0;
}


module_init(init_hello_4);
module_exit(cleanup_hello_4);

/* Get rid of taint message by declaring code as GPL. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);		/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
MODULE_SUPPORTED_DEVICE("testdevice");
