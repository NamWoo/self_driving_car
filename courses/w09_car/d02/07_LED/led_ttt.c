#include "../lib2450/Uart.h"
#include "../lib2450/Timer.h" // Delay()
#include <stdlib.h> // rand()


// 0x56000060번지를 4바이트 R/W 할 수 있는 매크로 정의
#define GPGCON  (*(volatile unsigned long *)0x56000060)

// 0x56000064번지를 4바이트 R/W 할 수 있는 매크로 정의
#define GPGDAT  (*(volatile unsigned long *)0x56000064)


void Init_Led(void)
{
	// 1. GPGDAT 4,5,6,7에 HIGH(1) 출력 (LED OFF)
	GPGDAT |= 0xf << 4;
	
	// 2. GPGCON 4,5,6,7을 출력(Output) 모드로 설정
	GPGCON &= ~(0xff << 8);
	GPGCON |= 0x55 << 8;
}

void Led_On(int num)
{
	/* 3. num이 1이면 GPGDAT4에 LOW 출력(LED ON)
     *    num이 2이면 GPGDAT5에 LOW 출력
     *    num이 3이면 GPGDAT6에 LOW 출력
     *    num이 4이면 GPGDAT7에 LOW 출력            */
	 GPGDAT &= ~(0x1  <<  3+num);
}

void Led_Off(int num)
{
	/* 4. num이 1이면 GPGDAT4에 HIGH 출력(LED OFF)
     *    num이 2이면 GPGDAT5에 HIGH 출력
     *    num이 3이면 GPGDAT6에 HIGH 출력
     *    num이 4이면 GPGDAT7에 HIGH 출력            */
	 GPGDAT |= (0x1  <<  3+num);
}

void User_Main()
{
	int ranNum = 0;
	
    Init_Led();
	
	while(1)
	{
		ranNum = 1 + rand() % 4;
		
		Led_On(ranNum);
		
		Timer_Delay(500);
		
		Led_Off(ranNum);
	}
}