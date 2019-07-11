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
#include <asm/io.h>         //ioremap(), iounmap()
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <asm/signal.h>

MODULE_LICENSE("GPL");

static int my_major = 0, my_minor = 0;
static int result;
static dev_t my_dev;
int id;

static struct cdev my_cdev;
static int my_register_cdev(void);
int my_kill_proc(pid_t pid, int sig);

static int my_open(struct inode *inode, struct file *filp);
static int my_release(struct inode *inode, struct file *filp);
static int my_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int my_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);

static int my_open(struct inode *inode, struct file *filp);
static int my_release(struct inode *inode, struct file *filp);
static int my_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int my_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);

static int my_open(struct inode *inode, struct file *filp)
{
    printk("Device has been opened\n");
    return 0;
}

static int my_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed\n");
    return 0;
}

static int my_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    char data[11];
    
    get_user(id, (int *)buf);
    printk("\n [kernel] id = %d", id);
    my_kill_proc(id, SIGUSR1);
    return count;
}

static int my_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    char data[20] = "this is read func...";
    copy_to_user(buf, data, count);
    return 0;
}

struct file_operations my_fops = {
    .open       = my_open,
    .release    = my_release,
    .write      = my_write,
    .read       = my_read,
};

static int __init my_init(void)
{
    printk("MY Module is up\n");
    if((result = my_register_cdev()) < 0)
    {
        return result;
    }
    return 0;
}

static void __exit my_exit(void)
{
    printk("The module is down\n");
    cdev_del(&my_cdev);
    unregister_chrdev_region(my_dev, 1);
}

static int my_register_cdev(void)
{
    int error;

    if(my_major)
    {
        my_dev = MKDEV(my_major, my_minor);
        error = register_chrdev_region(my_dev, 1, "w09d04");
    }
    else
    {
        error = alloc_chrdev_region(&my_dev, my_minor, 1, "w09d04");
        my_major = MAJOR(my_dev);
    }
    
    if(error < 0)
    {
        printk(KERN_WARNING "my: can't get major %d\n", my_major);
        return result;
    }
    printk("major number=%d\n", my_major);

    cdev_init(&my_cdev, &my_fops);
    my_cdev.owner = THIS_MODULE;
    my_cdev.ops = &my_fops;
    error = cdev_add(&my_cdev, my_dev, 1);

    if(error)
        printk(KERN_NOTICE "my Register Error %d\n", error);
    
    return 0;
}

int my_kill_proc(pid_t pid, int sig) {
    int error = -ESRCH;           /* default return value */
    struct task_struct* p;
    struct task_struct* t = NULL; 
    struct pid* pspid;
    rcu_read_lock();
    p = &init_task;               /* start at init */
    do {
        if (p->pid == pid) {      /* does the pid (not tgid) match? */
            t = p;    
            break;
        }
        p = next_task(p);         /* "this isn't the task you're looking for" */
    } while (p != &init_task);    /* stop when we get back to init */
    if (t != NULL) {
        pspid = t->pids[PIDTYPE_PID].pid;
        if (pspid != NULL) error = kill_pid(pspid,sig,1);
    }
    rcu_read_unlock();
    return error;
}


module_init(my_init);
module_exit(my_exit);