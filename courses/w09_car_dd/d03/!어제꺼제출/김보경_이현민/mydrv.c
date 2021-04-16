/*
  mydrv.c - kernel 3.0 skeleton device driver
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

#define DEVICE_NAME "mydrv"
#define rGPLCON1 *(volatile unsigned long *)(kva + 0)
#define rGPLDAT *(volatile unsigned long *)(kva + 4)
#define rGPMCON *(volatile unsigned long *)(kva + 0x10)
#define rGPMDAT *(volatile unsigned long *)(kva + 0x14)
static int mydrv_major = 240;
module_param(mydrv_major, int, 0);
static void *kva;

static int mydrv_open(struct inode *inode, struct file *file)
{
  printk("mydrv opened !!\n");
  return 0;
}

static int mydrv_release(struct inode *inode, struct file *file)
{
  printk("mydrv released !!\n");
  return 0;
}

static ssize_t mydrv_read(struct file *filp, char __user *buf, size_t count,
                loff_t *f_pos)
{
  char *k_buf;
  int i;
  
  k_buf = kmalloc(count,GFP_KERNEL);
  for(i = 0 ;i < count;i++)
      k_buf[i] = 'A' + i;
  
  if(copy_to_user(buf,k_buf,count))
  	return -EFAULT;
  printk("mydrv_read is invoked\n");
  kfree(k_buf);
  return 0;

}

static ssize_t mydrv_write(struct file *filp,const char __user *buf, size_t count,
                            loff_t *f_pos)
{
  /*char *k_buf;
    
  k_buf = kmalloc(count,GFP_KERNEL);
  if(copy_from_user(k_buf,buf,count))
  	return -EFAULT;
  printk("k_buf = %s\n",k_buf);
  printk("mydrv_write is invoked\n");
  kfree(k_buf);*/
	/*	
	int i,j;
	for(i = 0; i < 5; i++){
		rGPLDAT  &= ~(0x1  <<  4);
		rGPLDAT  &= ~(0x1  <<  5);
		rGPLDAT  &= ~(0x1  <<  6);
		rGPLDAT  &= ~(0x1  <<  7);
		for(j = 0; j <0xffffff; j++){}
		rGPLDAT  |= (0x1  <<  4);
		rGPLDAT  |= (0x1  <<  5);
		rGPLDAT  |= (0x1  <<  6);
		rGPLDAT  |= (0x1  <<  7);
	}*/

	rGPLDAT  &= ~(0x1  <<  4);
	rGPLDAT  &= ~(0x1  <<  5);
	rGPLDAT  &= ~(0x1  <<  6);
	rGPLDAT  &= ~(0x1  <<  7);
	
	printk("mydrv_write is invoked\n");
  return 0;
}


/* Set up the cdev structure for a device. */
static void mydrv_setup_cdev(struct cdev *dev, int minor,
		struct file_operations *fops)
{
	int err, devno = MKDEV(mydrv_major, minor);
    
	cdev_init(dev, fops);
	dev->owner = THIS_MODULE;
	dev->ops = fops;
	err = cdev_add (dev, devno, 1);
	
	if (err)
		printk (KERN_NOTICE "Error %d adding mydrv%d", err, minor);
}


static struct file_operations mydrv_fops = {
	.owner   = THIS_MODULE,
   	.read	   = mydrv_read,
    	.write   = mydrv_write,
	.open    = mydrv_open,
	.release = mydrv_release,
};

#define MAX_MYDRV_DEV 1

static struct cdev MydrvDevs[MAX_MYDRV_DEV];

static int mydrv_init(void)
{
	int result;
	dev_t dev = MKDEV(mydrv_major, 0);

	kva = ioremap(0x56000060,28);
	printk("kva = 0x%x\n",(int)kva); 

	rGPLDAT |= 0xf<<4;
	rGPLCON1 &= ~(0xff << 8);
	rGPLCON1  |= 0x55<<8;

	/* Figure out our device number. */
	if (mydrv_major)
		result = register_chrdev_region(dev, 1, DEVICE_NAME);
	else {
		result = alloc_chrdev_region(&dev,0, 1, DEVICE_NAME);
		mydrv_major = MAJOR(dev);
	}
	if (result < 0) {
		printk(KERN_WARNING "mydrv: unable to get major %d\n", mydrv_major);
		return result;
	}
	if (mydrv_major == 0)
		mydrv_major = result;

	mydrv_setup_cdev(MydrvDevs,0, &mydrv_fops);
	printk("mydrv_init done\n");	
	return 0;
}

static void mydrv_exit(void)
{
	cdev_del(MydrvDevs);
	unregister_chrdev_region(MKDEV(mydrv_major, 0), 1);
	printk("mydrv_exit done\n");
}

module_init(mydrv_init);
module_exit(mydrv_exit);

MODULE_LICENSE("Dual BSD/GPL");
