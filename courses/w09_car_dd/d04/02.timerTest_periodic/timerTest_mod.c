#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>

#include <linux/timer.h>

#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/cdev.h>


///
#define GPGCON *(volatile unsigned long *)(kva)
#define GPGDAT *(volatile unsigned long *)(kva + 4)

static void *kva;

///

struct timer_list timer;
//구조체 변수 타이머 사용하려면 무조건 올려야한다.






void my_timer(unsigned long data)
{
	int i, c;
	for(i=1; i<=data; i++) {
		printk("Kernel Timer Time-Out Function Doing_%d...\n", i);
		c++;
		if (c==3)
		{
			del_timer(&timer);
		}
	}

	// GPGDAT &= ~(0xf  <<  4); z켜기
	GPGDAT ^= (0xf << 4);
	// GPGDAT |= 0xf << 4;	꺼기





	timer.expires = jiffies + 2*HZ;
	//들어와서 또 셋팅, 또 불리는, 계속 도는
	add_timer(&timer);
	//위 두줄을 제거하고 돌리면 타이머가 1번 밖에 뜨지 않는다.
	//테엽을 감아주는 느낌, 계속 뜨게 할 수 있는 곳
	printk("Kernel Timer Time-Out Function Done!!!\n");

	///
}

int timerTest_init(void)
{
	printk(KERN_INFO "timerTest Module is Loaded!! ....\n");

	init_timer(&timer);
	//이걸 꼭 해야한다. init_timer 초기화!
	//timer.expires = get_jiffies_64() + 3*HZ;
	timer.expires = jiffies + 3*HZ;
	//구조체맴버접근 연산자를 통해 expires(만기)
	//터지기 위한 기간, 시간 3~2~1~빵~ 할때 3
	//이 변수를 읽어올 때 시간 jiffies에 + 3HZ 늘렸고 그때가 바로 만료기간
	timer.function = my_timer;
	//이게 펑션으로 타이머핸들러
	//만료기간 끝나면 이 함수로 
	//리눅스 3가지 핸들러 시그널 핸들러, 인터럽트 핸들러, 타이머 핸들러 
	timer.data = 5;
	//이 데이터 들고 보내
	add_timer(&timer);
	//여기까지 하고 함수로 보내
	//이제 기간만큼 지나고 다음 함수 콜


	///LED
	kva = ioremap(0x56000060, 16);
    // printk("kva = 0x%x\n", (int)kva);
    
    GPGDAT |= 0xf << 4;

    GPGCON &= ~(0xff << 8);
    GPGCON |= 0x55 << 8;
	return 0;
}

void timerTest_exit(void)
{
	GPGDAT |= 0xf << 4;
	del_timer(&timer);
	printk("timerTest Module is Unloaded ....\n");
}

module_init(timerTest_init);
module_exit(timerTest_exit);

MODULE_LICENSE("Dual BSD/GPL");


/*
 #tail -f /var/log/messages
*/
