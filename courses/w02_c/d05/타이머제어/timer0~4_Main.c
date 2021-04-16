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

#define EXAMPLE 330
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
	int sel;
	Uart_Init(115200);	

	Uart_Send_Byte('\n');
	Uart_Send_Byte('A');	
	Uart_Send_String("Hello Uart Test...!!!\n");
	

	Uart_Printf("\n timer0:10ms\n timer1:100ms\n timer2:500ms\n timer3:1000ms\n timer4:2000ms\n");
	Uart_Printf("\nselect timer : ");
	sel = Uart_Get_Char();
	my_Timer_Init(sel);
	while(1)
	{
		my_Timer_delay(sel);
		Uart_Send_String("Time Delay\n");		
	}
}
#endif
