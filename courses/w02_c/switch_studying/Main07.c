/*
 * =====================================================================
 * NAME         : Main.c
 *
 * Descriptions : Main routine for S3C2450
 *
 * IDE          : GCC-4.1.0
 *
 * Modification
 *	  
 * =====================================================================
 */
#include "2450addr.h"
#include "libc.h"

#define EXAMPLE 500

//from here, my code

#if EXAMPLE == 500 

void my_INIT_LED(void);
void my_LED_ON_OFF(void);
void my_INIT_SW(void);
int my_GET_SW(void);

void Main(void)
{
	int sw;
	int t;
	Uart_Init(115200);	

	Uart_Send_Byte('\n');
//	Uart_Send_Byte('A');	
	Uart_Send_String("Helloooo my switch test\n");
//	Uart_Printf("my switch test\n");
//	Uart_Send_Byte(Uart_Get_Char());
//	Uart_Printf("]\n");	

	my_INIT_LED();
	my_INIT_SW();
	my_LED_ON_OFF();
	
	//rGPFDAT = 0x7F
//	while(1)
//{
//	Uart_Printf("%x\n",rGPFDAT);
//	sw = my_GET_SW();
//	Uart_Printf("%d\n",sw);
//}
	sw = 0;
	while(1)
	{
		
//		sw = 0;
		while(1)
		{
			sw = my_GET_SW();
		 	Uart_Printf("sw %d\n",sw);

			if ((sw>=4) && (sw<=13)) 
			{
				break;
			}
		}
		
		if (sw==4)
		{
			Uart_Send_String("SW4\n");
			my_LED_ON_OFF();			
		}
		
		if (sw==5)
		{
			Uart_Send_String("SW5\n");
			my_LED_ON_OFF();
		}
		
		if (sw==6)
		{
			Uart_Send_String("SW6\n");
			my_LED_ON_OFF();
		}
		
		if (sw==7)
		{
			Uart_Send_String("SW7\n");
			my_LED_ON_OFF();
		}
		if (sw==8)
		{
			Uart_Send_String("SW8\n");
			my_LED_ON_OFF();
		}
		
		if (sw==9)
		{
			Uart_Send_String("SW9\n");
			my_LED_ON_OFF();
		}
      	if (sw==10)
        {
            Uart_Send_String("SW10\n");
            my_LED_ON_OFF();
        }
        		
		if (sw==11)
		{
			Uart_Send_String("SW11\n");
			my_LED_ON_OFF();
		}
      	if (sw==12)
        {
            Uart_Send_String("SW12\n");
            my_LED_ON_OFF();
        }
        		
		if (sw==13)
		{
			Uart_Send_String("SW13\n");
			my_LED_ON_OFF();
		}


	}


}

void my_INIT_LED(void)
{
	//LED INIT GPG[4:7] 4 LEDS
	rGPGCON &= ~(0xff<<8);	//ready 00
	rGPGCON |= (0x55<<8);	//OUTPUT mode 01 GPG4567
	Uart_Printf("LED INIT rGPGCON : %x\n", rGPGCON);
	rGPGDAT |= (0xf<<4);	//set 1, LED off
	Uart_Printf("LED INIT rGPGDAT : %x\n", rGPGDAT);
	Uart_Printf("LED INIT DONE\n");
}

void my_LED_ON_OFF(void)
{
	int i;
	Uart_Printf("LED ONOFF INIT rGPGDAT : %x\n", rGPGDAT);
	rGPGDAT &= ~(0xf<<4);	//set 0, LED on
        Uart_Printf("LED ONOFF set 0 LED ON rGPGDAT : %x\n", rGPGDAT);
	for (i=0;i<0xfffff;i++){ }
	rGPGDAT |= (0xf<<4);	//set 1, LED off
        Uart_Printf("LED ONOFF set 1 LED OFF rGPGDAT : %x\n", rGPGDAT);
}

void my_INIT_SW(void)
{
	//KEY INIT    
	//GPG0                                  
	rGPGCON &= ~(0x03);		//ready 00
	rGPGCON |= (0x01);		//OUTPUT mode 01 
	
	rGPGDAT &= ~(0x01);		//GND, 해당 비트만 clear 0. 
	
	//GPF7
	rGPFCON &= ~(0x03<<14);	//ready 00
	rGPFCON |= (0x01<<14);	//OUTPUT mode 01
	
	rGPFDAT &= ~(0x01<<7);	//GND, 해당 비트만 clear 0.	
	
	//INPUT
	rGPFCON &= ~(0x3ff<<4);	//ready 00 and INPUT mode clear 00.
	Uart_Send_String("SW INIT done\n");
	
	Uart_Printf("KEY INIT rGPGCON : %x\n", rGPGCON);	//0x08f8
	Uart_Printf("KEY INIT rGPGDAT : %x\n", rGPGDAT);	//0x08f8
	
	Uart_Printf("KEY INIT rGPFCON : %x\n", rGPFCON);	//0x4000
	Uart_Printf("KEY INIT rGPFDAT : %x\n", rGPFDAT);	//0x007f
	Uart_Printf("KEY INIT DONE!");	//0x007f


}

int my_GET_SW(void)
{

	//SWITCH CHECKING
	int sw;
	
	//GPF[2:6] checking
	//GPG0, GPF7 checking

	//00으로 초기화한 밑단 GND 중, 하나씩 비교.
	//GPG0 GND, DAT를 1로 올려 얘를 무시하면  
	//GPF7과 SW4,SW5,SW6,SW7 확인 가능 
	//rGPFDAT = 0x007f
	//sw4567 순으로 7b, 77, 6f, 5f, 3f, // 7e 7d 
	
	rGPGDAT |= (0x01);					//GPG0 ignore 01
	
	Uart_Printf("rGPGDAT %x rGPFDAT %x\n",rGPGDAT,rGPFDAT);	
	//rGPGDAT 8f1 rGPFDAT 7f
	
	if ((rGPFDAT & 0x7b) == 0x7b)			//GPF2
	{
		sw = 4;
	}
	else if ((rGPFDAT & 0x77) == 0x77)	//GPF3
	{
		sw = 5;
	}
	else if ((rGPFDAT & 0x6f) == 0x6f)	//GPF4
	{
		sw = 6;
	}
	else if ((rGPFDAT & 0x5f) == 0x5f)	//GPF5
	{
		sw = 7;
	}
	else if ((rGPFDAT & 0x3f) == 0x3f)	//GPF6
	{
		sw = 8;
	}
	else{}
	
	rGPGDAT &= ~(0x01);					//GPG0 return 00 
	rGPFDAT |= (0x01<<7);				//GPF7 ignore 01

	Uart_Printf("rGPGDAT %x rGPFDAT %x\n",rGPGDAT,rGPFDAT);	


	if ((rGPFDAT & 0x7b) == 0x7b)			//GPF2
	{
		sw = 9;
	}
	else if ((rGPFDAT & 0x77) == 0x77)	//GPF3
	{
		sw = 10;
	}
	else if ((rGPFDAT & 0x6f) == 0x6f)	//GPF4
	{
		sw = 11;
	}
	else if ((rGPFDAT & 0x5f) == 0x5f)	//GPF5
	{
		sw = 12;
	}
	else if ((rGPFDAT & 0x3f) == 0x3f)	//GPF6
	{
		sw = 13;
	}
	else{}
	
	rGPFDAT &= ~(0x01<<7);				//GPF7 return 00 
	return sw;
}




#endif 


/*
 * 310: 실습 3 : LED_ON_Test
 *
 * 311	실습 4-1 : Key_Input_Test_with_LED
 *	
 * 320: 실습 5 : UART_Test
 *
 * 312: 실습 4-2 : Key_Input_Test_with_UART
 *
 * 330: 실습 6 : Timer_Test	
 * 
 */

/***************************************
 * 
 * Title: LED_ON_Test
 * 
 ***************************************/

#if EXAMPLE == 310 
void Main(void)
{	
	int a;
	
	Led_Init();
	
	while(1){
	for(a=0;;a++)
		Led_Display(a%8);	
	}
			
}
#endif 
 
/***************************************
 * 
 * Title: Key_Input_Test_with_LED
 * 
 ***************************************/

#if EXAMPLE == 311
void Main(void)
{	
	int a,i;
	
	Led_Init();
	Key_Port_Init();

	
//	for(a=0;a<8;a++)
//	Led_Display(a);
	
	for(;;)
	{
		//Key_Get_Pressed_with_LED();	
		Key_Get_Pressed();	
	}
			
}
# endif  


/***************************************
 * 
 * Title: UART_Test
 * 
 ***************************************/

#if EXAMPLE == 320
void Main(void)
{	

	Uart_Init(115200);	

	Uart_Send_Byte('\n');
	Uart_Send_Byte('A');	
	Uart_Send_String("Hello Uart Test...!!!\n");
	
	Uart_Printf("input character is [");
	Uart_Send_Byte(Uart_Get_Char());
	Uart_Printf("]\n");	
			
}
#endif

/***************************************
 * 
 * Title: Key_Input_Test_with_UART
 * 
 ***************************************/

#if EXAMPLE == 312
void Main(void)
{	
	int a,i;
	
	Led_Init();
	Uart_Init(115200);
	Key_Port_Init();

	Uart_Send_String("Key Test \n");
	
	for(a=0;a<8;a++)
	Led_Display(a);
	
	for(;;)
	{
		Uart_Printf("Key Value =%d\n",  Key_Wait_Get_Pressed()); 
		Key_Wait_Get_Released();
			
	}
			
}
# endif 

/***************************************
 * 
 * Title: Timer_Test
 * 
 ***************************************/

#if EXAMPLE == 330 
void Main()
{
	Uart_Init(115200);	

	Uart_Send_Byte('\n');
	Uart_Send_Byte('A');	
	Uart_Send_String("Hello Uart Test...!!!\n");
	
	Timer_Init();	
	while(1)
	{
		Uart_Send_String("Time Delay\n");
		Timer_Delay(1000);
	}
}
	Uart_Printf("LED ON!\n");
#endif
