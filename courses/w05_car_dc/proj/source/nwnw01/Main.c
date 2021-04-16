#include "my_lib.h"


void Main(void)
{
	
	MMU_Init();

	Uart_Init(115200);
	Uart_Send_String("\nHello ARM !!!\n\n");


#if 1
	Play_Iis_speak();
#else
	Play_Iis_Bypass();

#endif
	for(;;);
	return ;

	
}