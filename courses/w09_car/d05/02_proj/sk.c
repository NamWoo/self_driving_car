#if 0
#include <linux/module.h>
#include <linux/init.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#endif

#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <asm/page.h>
//#include <asm/hardware.h>
#include <linux/delay.h>
#include <asm/io.h>   // ioremap(),iounmap()
#include <linux/signal.h>
#include <linux/sched.h> //넣은거 확인
#include <linux/timer.h>
#include <asm/signal.h>

#include <linux/cdev.h>
#include <linux/major.h>

#include<mach/gpio.h>
#include<mach/regs-gpio.h>
#include<plat/gpio-cfg.h>
#include<linux/interrupt.h>
#include <asm/irq.h>
#include <linux/errno.h>
#include <linux/device.h>
///


///LED
#include <linux/kdev_t.h>
#include "ioctl_mydrv.h"
#include <linux/slab.h>   /* kmalloc() */
#include <linux/moduleparam.h>
#include <linux/types.h>    /* size_t */
///~LED

#define     DRV_NAME                "keyint"


///LED
#define GPGCON *(volatile unsigned long *)(kva)
#define GPGDAT *(volatile unsigned long *)(kva + 4)
static void *kva;
///~LED


///지연처리
static work_func_t mywork_queue_func(void *data);
DECLARE_DELAYED_WORK(mywork,(work_func_t)mywork_queue_func);
///





MODULE_LICENSE("GPL");

static int sk_major = 0, sk_minor = 0;
static int result;
static dev_t sk_dev;
int  id;
static int p;
static int aa;
static int i=0;

//나가서 소거되면 안되니까 글로벌변수로!


static struct cdev sk_cdev;
int my_kill_proc(pid_t pid, int sig);
static int sk_register_cdev(void);


/* TODO: Define Prototype of functions */
static int sk_open(struct inode *inode, struct file *filp);
static int sk_release(struct inode *inode, struct file *filp);
static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int sk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);


static work_func_t mywork_queue_func (void *data)
{
    //아래가 지연처리될 내용들

	GPGDAT |= (0xf << 4);	//먼저 다 끄고
	for(p=0; p<0x0900; p++)
	{
		printk("\r test = %d",p);

		// GPGDAT &= ~(0x1 << 4); 
		// GPGDAT |= (0xf << 4);
		// for(aa = 0; aa<0x200;aa++){}
		// GPGDAT &= ~(0x1 << 5); 
		// GPGDAT |= (0xf << 4);
		// for(aa = 0; aa<0x200;aa++){}
		// GPGDAT &= ~(0x1 << 6); 
		// GPGDAT |= (0xf << 4);
		// for(aa = 0; aa<0x200;aa++){}
		// GPGDAT &= ~(0x1 << 7); 
		// GPGDAT |= (0xf << 4);
		// for(aa = 0; aa<0x200;aa++){}
	}
	
	printk(" -[Bottom] mywork_queue : 0x%02x\n",(int)i);

	return 0;
}



/* TODO: Implementation of functions */
static int sk_open(struct inode *inode, struct file *filp)
{
    printk("Device has been opened...\n");
    
    /* H/W Initalization */
    
	///LED
	kva = ioremap(0x56000060, 16);
	printk("kva = 0x%x\n", (int)kva);

	GPGDAT |= 0xf << 4;

	GPGCON &= ~(0xff << 8);
	GPGCON |= 0x55 << 8;
	///~LED


    return 0;
}

static int sk_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");
    
    return 0;
}

//프로세스 아이디의 값이 저장되어 있는 변수의 주소 buf 넘어오고
//4바이트 넘어오고 get_user로 확인
//커널단에서 확인!
static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	char data[11];

	//copy_from_user(data, buf, count);
	//printk("data >>>>> = %s\n", data);

        get_user(id, (int *)buf);
        printk("\n [Kernel] id = %d", id);
        my_kill_proc(id,SIGUSR1);
		//응용단의 아이디를 알게된 후 그 정보신호를 쏜거
	return count;
}

static int sk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	char data[20] = "this is read func...";

	copy_to_user(buf, data, count);

	return 0;
}


static int mydrv_ioctl ( struct file *filp, unsigned int cmd, unsigned long arg)  
{  
  
   ioctl_buf *k_buf;
   int   i,err, size;  
      
   if( _IOC_TYPE( cmd ) != IOCTL_MAGIC ) return -EINVAL;  
   if( _IOC_NR( cmd )   >= IOCTL_MAXNR ) return -EINVAL;  

   size = _IOC_SIZE( cmd );   
 
   if( size )  
   {  
       err = -EFAULT;  
       if( _IOC_DIR( cmd ) & _IOC_READ  ) 
		err = !access_ok( VERIFY_WRITE, (void __user *) arg, size );  
       else if( _IOC_DIR( cmd ) & _IOC_WRITE ) 
		err = !access_ok( VERIFY_READ , (void __user *) arg, size );  
       if( err ) return err;          
   }  
            
   switch( cmd )  
   {  
        case IOCTL_LED_ON_TEST1 :
            printk("IOCTL_LED_ON_TEST1\n");
            printk("All LEDs On\n");
            volatile int i;

          
            // GPGDAT &= ~(0xf  <<  4);
            // for(i=0; i<4; i++)
            // {
              GPGDAT ^= (0xf << 4);
            //   mdelay(1000);
            // }
            // GPGDAT |= 0x0f << 4;


        break;

        case IOCTL_LED_ON_TEST2 :
            printk("IOCTL_LED_ON_TEST2\n");

			GPGDAT |= (0xf << 4);
			GPGDAT &= ~(0x1 << 4);


        break;
        
        case IOCTL_LED_ON_TEST3 :
            printk("IOCTL_LED_ON_TEST3\n");
        break;
                
        case IOCTL_LED_ON_TEST4 :
            printk("IOCTL_LED_ON_TEST4\n");
        break;
                
        case IOCTL_LED_ON_TEST5 :
            printk("god MIN JOON\n\n");
        break;
       
    	default :
            printk("Invalid IOCTL  Processed!!\n");
            break; 
    }  
  
    return 0;  
}  





//구조체 안에는 함수포인터 변수 대거 포진
//커널 안에 있다.
struct file_operations sk_fops = { 
    .open       = sk_open,
    .release    = sk_release,
	.write		= sk_write,
	.read		= sk_read,
	.unlocked_ioctl   = mydrv_ioctl,
};



static struct rebis_key_detection
{
    int             irq;
    int             pin;
    int             pin_setting;
    char            *name;
    int             last_state;
};

static struct rebis_key_detection rebis_gd = {
   IRQ_EINT7, S3C2410_GPF(7), S3C2410_GPF7_EINT7, "key-detect", 0
};





static irqreturn_t keyinterrupt_func1(int irq, void *dev_id, struct pt_regs *resgs)
{
//   mydrv_data *k_buf;
//   k_buf = kmalloc(kout_buf,GFP_KERNEL);
  
      printk("14 Key pressed....\n");
	  my_kill_proc(id,SIGUSR1);
    //   printk("age : %d\n",GlobalBuf->age);
//       strcpy(kout_buf, k_buf->age);

      return IRQ_HANDLED;
}

static irqreturn_t keyinterrupt_func2(int irq, void *dev_id, struct pt_regs *resgs)
{
	printk("15 Key pressed....\n");
	my_kill_proc(id,SIGUSR1);
    //   printk("name : %s\n", GlobalBuf->name);
	schedule_delayed_work(&mywork, 0);

	return IRQ_HANDLED;
}


static int __init sk_init(void)
{
	int ret;
    printk("SK Module is up... \n");

	if((result = sk_register_cdev()) < 0)
	{
		return result;
	}


	gpio_request(S3C2410_GPF(2), "led 1");
	gpio_request(S3C2410_GPF(3), "led 2");
	gpio_request(S3C2410_GPF(4), "led 3");
	gpio_request(S3C2410_GPF(5), "led 4");
	gpio_request(S3C2410_GPF(6), "led 5");

    // set output mode
    s3c_gpio_cfgpin(S3C2410_GPF(2), S3C_GPIO_SFN(1));
    s3c_gpio_cfgpin(S3C2410_GPF(3), S3C_GPIO_SFN(1));
    s3c_gpio_cfgpin(S3C2410_GPF(4), S3C_GPIO_SFN(1));
    s3c_gpio_cfgpin(S3C2410_GPF(5), S3C_GPIO_SFN(1));
    s3c_gpio_cfgpin(S3C2410_GPF(6), S3C_GPIO_SFN(1));



	///인터럽트 모드
	// set Interrupt mode
	//2키
	s3c_gpio_cfgpin(S3C2410_GPF(0), S3C_GPIO_SFN(2));
	s3c_gpio_cfgpin(S3C2410_GPF(1), S3C_GPIO_SFN(2));

	///5키 
	s3c_gpio_cfgpin(S3C2410_GPF(7), S3C_GPIO_SFN(2));

    //인터럽트 서비스 루틴
	if( request_irq(IRQ_EINT0, (void *)keyinterrupt_func1, IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL))
	{
		printk("failed to request external interrupt.\n");
		ret = -ENOENT;
		return ret;
	}
	printk(KERN_INFO "%s successfully SW14 loaded\n", DRV_NAME);

	if( request_irq(IRQ_EINT1, (void *)keyinterrupt_func2, IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL))
	{
		printk("failed to request external interrupt.\n");
		ret = -ENOENT;
		return ret;
	}
	printk(KERN_INFO "%s successfully SW15 loaded\n", DRV_NAME);

    return 0;
}

static void __exit sk_exit(void)
{
	//5키
	gpio_free(S3C2410_GPF(2));
	gpio_free(S3C2410_GPF(3));
	gpio_free(S3C2410_GPF(4));
	gpio_free(S3C2410_GPF(5));
	gpio_free(S3C2410_GPF(6));

	//인터럽트 2키
	free_irq(IRQ_EINT0, NULL);
	free_irq(IRQ_EINT1, NULL);
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


int my_kill_proc(pid_t pid, int sig)
{
    int error = ESRCH;
    struct task_struct *p;
    struct task_struct *t = NULL;
    struct pid *pspid;
    rcu_read_lock();
	//lock 이니까 뮤텍스(소유권있는)
	//언락할때까지 기다리는
	//세마포어(소유권없는)
	//카운팅 세마포어 99 97 어느 쓰레드나 집어갈 수 있는
	//카운팅 값이 0이면 다 멈추는
	//쓰레드 간의 동기화 다양한 기법들


	//C에서 프로세스를 처음부터 링크드리스트로 탐색하는거
	//프로세스 등록이되면
	//커널단에 처음부터 찾다가 맞으면 break로 나오는
	//do while 한번은 무조건 실행
    p = &init_task;
    do
    {
	if(p->pid == pid)
        {
            t=p;
            break;
        }
        p = next_task(p);
    }while(p != &init_task);

    if(t != NULL)
    {
        pspid = t-> pids[PIDTYPE_PID].pid;
        if(pspid != NULL)
            error = kill_pid(pspid,sig,1);
    }
    rcu_read_unlock();
	//뮤텍스 언락
    return error;
}





module_init(sk_init); 
module_exit(sk_exit); 
