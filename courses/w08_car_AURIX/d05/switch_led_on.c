/*
 * core0_main.c
 *
 *  Created on: May 14, 2016
 *      Author: John
 */


#include "IfxPort_reg.h"
//#include "Port.h"
#define RELEASE 1
#define PRESSED 0


void core0_main(void)
{
	volatile int i = 0;
	//switch control : input
	//p11.6 -> output, gpio
	MODULE_P11.IOCR4.B.PC6 = 0x10;
	//11.10 -> input, gpio
	MODULE_P11.IOCR8.B.PC10 = 0;

	for(;;)
	{
		//detect the state of whether the switch is pushed or
		if(MODULE_P11.IN.B.P10 == PRESSED)
		{
			i++;
			//RED LED on
			MODULE_P11.OMCR4.B.PCL6 = 1;
		}
		else
		{
			//RED LED off
			MODULE_P11.OMSR4.B.PS6 = 1;
		}

	}

}
