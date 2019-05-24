#include "../lib2450/Uart.h"
#include "../lib2450/Timer.h"

#define GPFCON  (  *(volatile unsigned int *)0x56000050  )
#define GPFDAT  (  *(volatile unsigned int *)0x56000054  )

#define GPGCON  (  *(volatile unsigned int *)0x56000060  )
#define GPGDAT  (  *(volatile unsigned int *)0x56000064  )


void Init_Key(void)
{
    // 1. GPFCON2~6를 input으로 설정
    GPFCON &= ~(0x3ff << 4);
	
    // 2. GPFCON7, GPGCON0을 output으로 설정
    GPFCON = (GPFCON & ~(0x3 << 14)) | 0x1 << 14;
    GPGCON = (GPGCON & ~(0x3 << 0)) | 0x1 << 0;    

    // 3. GPFDAT7, GPGDAT0에 LOW(0) 출력
    GPFDAT &= ~(0x1 << 7);
    GPGDAT &= ~(0x1 << 0);
}


int Get_Key_byPolling(void)
{
    int i;

    GPFDAT |= 0x1 << 7; // off 
    GPGDAT &= ~(0x1 << 0); // on
	
    while(1)
    {
        for(i=0; i<5; i++)
        {
            if( (GPFDAT & 0x1 << (i+2)) == 0 )
            {
                if(GPFDAT & (0x1 << 7))	
                    return i + 6;
				
                else			
                    return i + 1;
            }
         }
		
         GPFDAT ^= 0x1 << 7;
         GPGDAT ^= 0x1 << 0;
    }
}


void User_Main()
{
    int i, pressed_key = 0;

    Init_Key();
	
    while(1)
    {
		Uart_Printf("Press key : ");
		
        pressed_key = Get_Key_byPolling();
        
		Uart_Printf("[%d] pressed !! \n", pressed_key);
		
        for(i=0; i<0x8ffff; i++); // delay for chattering
    }
}