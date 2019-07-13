/***************************************
 * Filename: sk.c
 * Title: Skeleton Device
 * Desc: Implementation of system call
 ***************************************/
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

MODULE_LICENSE("GPL");

static int sk_major = 0, sk_minor = 0;
static int result;
static dev_t sk_dev;
int  id;
//나가서 소거되면 안되니까 글로벌변수로!


static struct cdev sk_cdev;
int my_kill_proc(pid_t pid, int sig);
static int sk_register_cdev(void);
int my_kill_proc(pid_t pid, int sig);

/* TODO: Define Prototype of functions */
static int sk_open(struct inode *inode, struct file *filp);
static int sk_release(struct inode *inode, struct file *filp);
static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int sk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);

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

//구조체 안에는 함수포인터 변수 대거 포진
//커널 안에 있다.
struct file_operations sk_fops = { 
    .open       = sk_open,
    .release    = sk_release,
	.write		= sk_write,
	.read		= sk_read,
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
