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
#include "KeyLogger.h"
#include "Timer.h"
// #define EXAMPLE 312

void Main()
{
	TestTimer();
	// TestKeyLogger();
}
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

void LedInterleave()
{
	//set output;
	rGPGCON |= (0x55 << 8);
	int j = 0;
	int interleaveCnt;
	while (1)
	{
		if (interleaveCnt++ == 0)
		{
			rGPGDAT ^= (0xa << 4);
		}
		else
		{
			rGPGDAT ^= (0x5 << 4);
		}

		while (j++ < 0xffff)
		{
		}
		// rGPGDAT &= ~(0xf << 4);
		j = 0;
	}
}

void LedLoop()
{
	//init GPG
	rGPGCON &= ~(0xff << 8);
	rGPGCON |= (0x55 << 8);

	int i = 0;
	int j = 0;
	while (1)
	{
		int cnt = 0;
		for (j = 0; j < 16; ++j)
		{
			rGPGDAT |= (j << 4);
			while (++cnt < 0xffff)
			{
			}
			rGPGDAT &= ~(0xf << 4);
			cnt = 0;
		}
	}
}

void Main(void)
{
	LedInterleave();
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
	int a, i;

	Led_Init();
	Key_Port_Init();

	//	for(a=0;a<8;a++)
	//	Led_Display(a);

	for (;;)
	{
		//Key_Get_Pressed_with_LED();
		Key_Get_Pressed();
	}
}
#endif

/***************************************
 * 
 * Title: UART_Test
 * 
 ***************************************/

#if EXAMPLE == 320

extern void Func();

void Main(void)
{

	// Uart_Init(115200);

	// Uart_Send_Byte('\n');
	// Uart_Send_Byte('A');
	// Uart_Send_String("Hello Uart Test...!!!\n");

	// Uart_Printf("input character is [");
	// Uart_Send_Byte(Uart_Get_Char());
	Uart_Printf("]\n");

	int i;
	for (i = 0; i < 5; ++i)
	{
		Func();
	}
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
	int a, i;

	Led_Init();
	Uart_Init(115200);
	Key_Port_Init();

	Uart_Send_String("Key Test \n");

	for (a = 0; a < 8; a++)
		Led_Display(a);

	for (;;)
	{
		Uart_Printf("Key Value =%d\n", Key_Wait_Get_Pressed());
		Key_Wait_Get_Released();
	}
}
#endif

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
	while (1)
	{
		Uart_Send_String("Time Delay\n");
		Timer_Delay(1000);
	}
}
#endif
