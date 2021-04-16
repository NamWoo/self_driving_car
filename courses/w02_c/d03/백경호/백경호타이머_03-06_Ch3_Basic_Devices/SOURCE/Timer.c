#include "2450addr.h"
#include "option.h"
#include "libc.h"

//Function Declaration
void TestTimer()
{
	Timer_Init();
	Timer_Delay(10000);
}

void Timer_Init(void)
{
	/* 
	* TO DO :	Timer0 Init 
	* Prescaler value : 255, dead zone length = 0
	* Divider value : 1/16, no DMA mode
	* New frequency : (PCLK/(Prescaler value+1))*Divider value = (66Mhz/(256))*(1/16)
	*				= 16.113Khz(16113Hz)
	*/
	// rTCFG0=0xff; //prescaler 255
	rTCFG0 = 0xff;		//Ŀ������ ������  012 pre scaler ù��° ���ֱ�
	rTCFG1 = 0x3;		// mux input : 1/16   Ŀ������ ������  0,1,2,3 �� ���� �� ����
	rTCFG0 = 0xff << 8; // 2��° 8 ��Ʈ ���ֱ�

	/* TO DO :   TCON���� :Dead zone disable,  auto reload on, output inverter off
	*  manual update no operation, timer0 stop, TCNTB0=0, TCMPB0 =0
	*/

	//auto reload on timer 0 1 2 3
	rTCON = 0x8;
	rTCON |= 1 << 11;
	rTCON |= 1 << 15;
	rTCON |= 1 << 19;

	rTCNTB0 = 0; //clear cnt buffer
	rTCMPB0 = 0; // clear compare buffer

	rTCNTB1 = 0; //clear cnt buffer
	rTCMPB1 = 0; // clear compare buffer

	rTCNTB2 = 0; //clear cnt buffer
	rTCMPB2 = 0; // clear compare buffer

	rTCNTB3 = 0; //clear cnt buffer
	rTCMPB3 = 0; // clear compare buffer
}

void Timer_Delay(int msec)
{
	/*  TO DO :
	* 1) TCNTB0���� : �Ѱܹ޴� data�� ������ msec�̴�.
	*                  ���� msec�� �״�� TCNTB0������ ������ ���� ����.
	* 2) manual update�Ŀ�  timer0�� start��Ų��. 
	* 	 note : The bit has to be cleared at next writing.
	* 3) TCNTO0���� 0�� �ɶ����� ��ٸ���. 	
	*/
	/* YOUR CODE HERE */

	while (1)
	{

		rTCNTB0 = 16.113 * msec;
		rTCON |= (1 << 1) | (0);
		rTCON &= ~(1 << 1);
		rTCON |= 1; //start 0;

		rTCNTB1 = 16.113 * msec;
		rTCON |= (1 << 9) | (0);
		rTCON &= ~(1 << 9);
		rTCON |= 1 << 8; //start 1;

		rTCNTB2 = 16.113 * msec;
		rTCON |= (1 << 13) | (0);
		rTCON &= ~(1 << 13);
		rTCON |= 1 << 12; //start 2;

		rTCNTB3 = 16.113 * msec;
		rTCON |= (1 << 17) | (0);
		rTCON &= ~(1 << 17);
		rTCON |= 1 << 16; //start 3;

		int i;

		while (1)
		{
			for (i = 0; i < 4; ++i)
			{
				//interrrupt
				rTCFG1 &= ~(0xf) << 20; 
				rTCFG1 |= i << 20;
			}
			Uart_Printf("timer 0 : %x ,timer 1: %x, timer 2: %x , timer 3: %x \n", rTCNTO0, rTCNTO1, rTCNTO2, rTCNTO3);
		}

		// while(rTCNTO0)
		// {
		// 	Uart_Printf("%x\n",rTCNTO0);
		// }
	}
}