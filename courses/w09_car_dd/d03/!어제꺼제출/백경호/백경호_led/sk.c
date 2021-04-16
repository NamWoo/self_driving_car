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
#include <linux/io.h>

// 0x56000060번지를 4바이트 R/W 할 수 있는 매크로 정의
#define GPGCON  (*(volatile unsigned long *)0x56000060)

// 0x56000064번지를 4바이트 R/W 할 수 있는 매크로 정의
#define GPGDAT  (*(volatile unsigned long *)0x56000064)


MODULE_LICENSE("GPL");

static int sk_major = 0, sk_minor = 0;
static int result;
static dev_t sk_dev;

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
    
    /* H/W Initalization */
    
    return 0;
}

static int sk_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");
    
    return 0;
}

static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	char data[11];
static void *kva;
kva = ioremap(0x56000060,28) ;
volatile unsigned int* myGPGCON= (volatile unsigned int*)kva;
volatile unsigned int* myGPGDAT = ((volatile unsigned int*)kva+1);

	// 1. GPGDAT 4,5,6,7에 HIGH(1) 출력 (LED OFF)
	*myGPGDAT |= 0xf << 4;
	
	// 2. GPGCON 4,5,6,7을 출력(Output) 모드로 설정
	*myGPGCON &= ~(0xff << 8);
	*myGPGCON |= 0x55 << 8;

	/* 3. num이 1이면 GPGDAT4에 LOW 출력(LED ON)
     *    num이 2이면 GPGDAT5에 LOW 출력
     *    num이 3이면 GPGDAT6에 LOW 출력
     *    num이 4이면 GPGDAT7에 LOW 출력            */
	 *myGPGDAT &= ~(0x1  <<  4);
	 *myGPGDAT &= ~(0x1  <<  5);
	 *myGPGDAT &= ~(0x1  <<  6);
	 *myGPGDAT &= ~(0x1  <<  7);

	copy_from_user(data, buf, count);
	printk("data >>>>> = %s\n", data);

	return count;
}

struct file_operations sk_fops = { 
    .open       = sk_open,
    .release    = sk_release,
	.write		= sk_write,
};

static int __init sk_init(void)
{
    printk("SK Module is up... \n");

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
