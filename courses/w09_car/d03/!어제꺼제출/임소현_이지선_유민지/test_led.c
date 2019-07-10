/* test_led.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

void Led_On(int num,int fd)
{
	int a;
	read(fd,&a,1);
	/* 3. num이 1이면 GPGDAT4에 LOW 출력(LED ON)
     *    num이 2이면 GPGDAT5에 LOW 출력
     *    num이 3이면 GPGDAT6에 LOW 출력
     *    num이 4이면 GPGDAT7에 LOW 출력            */
	 a&=~(0x1  <<  3+num);
	  write(fd,&a,1);
}

void Led_Off(int num,int fd)
{
	int a;
	read(fd,&a,1);
	/* 4. num이 1이면 GPGDAT4에 HIGH 출력(LED OFF)
     *    num이 2이면 GPGDAT5에 HIGH 출력
     *    num이 3이면 GPGDAT6에 HIGH 출력
     *    num이 4이면 GPGDAT7에 HIGH 출력            */
	a|=  (0x1  <<  3+num);
	write(fd,&a,1);
}
int main()
{
  int fd;
  int Num = 0;
 
  fd = open("/dev/led",O_RDWR);


while(1)
	{
	int kkkk;
		//ranNum = 1 + rand() % 4;
		for(Num=1;Num<5;Num++)
		{
			Led_On(Num,fd);
			for(kkkk=0;kkkk<0xffffff;kkkk++);
		}
		for(Num=4;Num>0;Num--)
		{
			Led_Off(Num,fd);
			for(kkkk=0;kkkk<0xffffff;kkkk++);
		}
	}

  
  close(fd);

  return (0);
}
