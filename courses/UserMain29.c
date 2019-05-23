#include "../lib2450/Uart.h"
#include "LibA.h"

// 1. 원하는 동작을 구현
void MyEvent()
{
    Uart_Printf("Plz call me.. \n");
}

void User_Main()
{
	// ...
	
	// 2. 구현한 동작(서브 루틴의 주소)을  (라이브러리 등의) 함수로 전달
    LibFunc(MyEvent);
}