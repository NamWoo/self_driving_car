#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/delay.h>
#include <linux/timer.h>

#include <linux/interrupt.h>

#include <asm/io.h>
#include <mach/gpio.h>
#include <mach/regs-gpio.h>

#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <asm/irq.h>
#include <asm/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/string.h>

#define MAX_DEV_SIZE 100
#define GPGCON *(volatile unsigned int*)kva
#define GPGDAT *((volatile unsigned int*)kva+1)

static int MajorNumber = 240;
static struct cdev MyDevs[MAX_DEV_SIZE];
module_param(MajorNumber,int,0);


struct timer_list timer;

static void* kva;

void my_timer(unsigned long data)
{
	int i;
	
	GPGDAT ^= (0xf <<4);
	timer.expires = jiffies + 2*HZ;
	add_timer(&timer);

}

static void my_setup_cdev(struct cdev* dev, int minor, struct file_operations* fops)
{
	int err, devno = MKDEV(MajorNumber,minor);
	cdev_init(dev,fops);
	dev->owner = THIS_MODULE;
	dev->ops = fops;
	err = cdev_add(dev,devno,1);
	printk("===================\n\nMajor Number : %d !!!\n Minor Number : %d !!!\n\n==========================\n\n",MajorNumber,minor);
	if(err)
		printk("err when setting dev");
}

static int my_open(struct inode* inode, struct file* file)
{
	printk("opened");
	return 0;
}

static int my_write(struct file* file, char __user* buf, size_t count, loff_t* f_pos)
{
	if(strcmp(buf,"STOP")	==0)
	{
		del_timer(&timer);
		printk("buf : %s",buf);
	}
	
	if(strcmp(buf,"START")==0)
	{
		printk("buf : %s",buf);
		init_timer(&timer);
		add_timer(&timer);
	}
}

static int my_release(struct inode* inode, struct file* file)
{
	printk("released");
	return 0;
}

static struct file_operations my_fops = {
	.open = my_open,
	.write = my_write,
	.release = my_release
};

int timerTest_init(void)
{
	printk(KERN_INFO "timerTest Module is Loaded!! ....\n");
	
	kva = ioremap(0x56000060,8);

	GPGCON &= ~(0xff <<8);
	GPGCON |= (0x55 << 8);


	init_timer(&timer);
	//timer.expires = get_jiffies_64() + 3*HZ;
	timer.expires = jiffies + 3*HZ;
	timer.function = my_timer;
	timer.data = 5;
	add_timer(&timer);

	my_setup_cdev(MyDevs,0,&my_fops);



	return 0;
}

void timerTest_exit(void)
{
	del_timer(&timer);
	printk("timerTest Module is Unloaded ....\n");
}

module_init(timerTest_init);
module_exit(timerTest_exit);

MODULE_LICENSE("Dual BSD/GPL");


/*
 #tail -f /var/log/messages
*/
