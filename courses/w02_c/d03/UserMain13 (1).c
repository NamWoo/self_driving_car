#include "../lib2450/Uart.h"

void Ex1()
{
    int arr[3] = {0};

    Uart_Printf("%p , %p \n", arr, &arr[0]);

    Uart_Printf("%d , %d \n", 
        sizeof(arr),
        sizeof(&arr[0]));
} 

void Ex2()
{
	int i;
    int arr[3] = {0, };
    
    arr[0] = 2;
    (arr)[1] = 4;
    (&arr[0])[2] = 6;

    for(i=0; i<3; i++)
        Uart_Printf("arr[%d] = %d \n", i, arr[i]);
}


void User_Main()
{
	Uart_Printf("---------- Ex1 ---------- \n");
    Ex1();
	
	Uart_Printf("\n\n---------- Ex2 ---------- \n");
	Ex2();
}
