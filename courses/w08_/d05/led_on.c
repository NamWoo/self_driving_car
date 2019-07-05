/*
 * core0_main.c
 *
 *  Created on: May 14, 2016
 *      Author: John
 */


#include "IfxPort_reg.h"
//#include "Port.h"

void core0_main(void)
{
	volatile int i = 0;
	//LED control : output
	//p11.6 -> output, gpio
	MODULE_P11.OUT.B.P6 = 0x1;
	MODULE_P11.IOCR4.B.PC6 = 0x10;
//	MODULE_P11.OUT.B.P6 = ((PORT_PIN_OUT | PORT_PIN_MODE_GPIO) >> 3);

	MODULE_P11.IOCR8.B.PC10 = 0;

	while(1)
	{
		//toggle the RED LED
		//MODULE_P11.OMR.U = 0x00400040;
		MODULE_P11.OUT.B.P6 ^= 1;
		//unknown time delay
		for(i = 0; i < 0x1fffff; i++)
		{

		}



	}

}
