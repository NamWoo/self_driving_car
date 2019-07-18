/*
  led_on.c - kernel 3.0 skeleton device driver
               copy_to_user()
 */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>   /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <asm/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/io.h>

#define DEVICE_NAME "led"

static int led_on_major = 240;
module_param(led_on_major, int, 0);

#define rGPGCON *(volatile unsigned long *)(kva)
#define rGPGDAT *(volatile unsigned long *)(kva + 4)


static void *kva;



static int led_on_open(struct inode *inode, struct file *file)
{
  printk("led_on opened !!\n");
  
  return 0;
}

static int led_on_release(struct inode *inode, struct file *file)
{
  printk("led_on released !!\n");
  return 0;
}

static ssize_t led_on_read(struct file *filp, char __user *buf, size_t count,
                loff_t *f_pos)
{
 
	int *i;
	
	i = kmalloc(count,GFP_KERNEL);
	i=&rGPGDAT;
     
 	 if(copy_to_user(buf,i,count))
  		return -EFAULT;
  	printk("led_on_read is invoked\n");

  	return 0;

}

static ssize_t led_on_write(struct file *filp,const char __user *buf, size_t count,
                            loff_t *f_pos)
{


  	int *i;
	
	i = kmalloc(count,GFP_KERNEL);
  	if(copy_from_user(i,buf,count))
  		return -EFAULT;

	rGPGDAT = *i;

	

  	printk("led_on_write is invoked\n");
  	kfree(i);
  	return 0;
}


/* Set up the cdev structure for a device. */
static void led_on_setup_cdev(struct cdev *dev, int minor,
		struct file_operations *fops)
{
	int err, devno = MKDEV(led_on_major, minor);
    
	cdev_init(dev, fops);
	dev->owner = THIS_MODULE;
	dev->ops = fops;
	err = cdev_add (dev, devno, 1);
	
	if (err)
		printk (KERN_NOTICE "Error %d adding led_on%d", err, minor);
}


static struct file_operations led_on_fops = {
	.owner   = THIS_MODULE,
   	.read	   = led_on_read,
    	.write   = led_on_write,
	.open    = led_on_open,
	.release = led_on_release,
};



#define MAX_led_on_DEV 1

static struct cdev MydrvDevs[MAX_led_on_DEV];

static int led_on_init(void)
{
	int result;
	dev_t dev = MKDEV(led_on_major, 0);

	/* Figure out our device number. */
	if (led_on_major)
		result = register_chrdev_region(dev, 1, DEVICE_NAME);
	else {
		result = alloc_chrdev_region(&dev,0, 1, DEVICE_NAME);
		led_on_major = MAJOR(dev);
	}
	if (result < 0) {
		printk(KERN_WARNING "led_on: unable to get major %d\n", led_on_major);
		return result;
	}
	if (led_on_major == 0)
		led_on_major = result;

	led_on_setup_cdev(MydrvDevs,0, &led_on_fops);

	kva = ioremap(0x56000060,8) ;
	printk("kva = 0x%x\n",(int)kva);


	rGPGDAT |= 0xff << 4;
	
	rGPGCON &= ~(0xff << 8);
	rGPGCON |= 0x55 << 8;
	//rGPGDAT &= ~(0xf  <<  4);

	printk("led_on_init done\n");
	
	return 0;
}

static void led_on_exit(void)
{
	cdev_del(MydrvDevs);
	unregister_chrdev_region(MKDEV(led_on_major, 0), 1);
	rGPGDAT |= 0xff << 4;
	printk("led_on_exit done\n");
}

module_init(led_on_init);
module_exit(led_on_exit);

MODULE_LICENSE("Dual BSD/GPL");

