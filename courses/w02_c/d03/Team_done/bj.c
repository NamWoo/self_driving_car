#include "2450addr.h"

volatile unsigned int *const GPGCON = (unsigned int *)0x56000060; //LED Con
volatile unsigned int *const GPGDAT  = (unsigned int *)0x56000064; //LED Dat
volatile unsigned int *const GPFCON = (unsigned int *)0x56000050; //Button Con
volatile unsigned int *const GPFDAT  = (unsigned int *)0x56000054; //Button Dat



void LED_Init(){
	*GPGCON |= (0x55<<8);
 	*GPGDAT  |= (0xf<<4);
}

void Key_Init(){
	*GPFCON = 0x4001;	//01 00 00 00 00 00 00 01
	*GPFDAT = 0x7e;	//0 1 1 1 1 1 1 0
}


void LED_On(){

	rGPGDAT &= ~(0xf<<4);

}

void LED_Off(){

	rGPGDAT |= (0xf<<4);

}


int Get_Key_byPolling(){
	//GPF2 가 눌려서 0으로 변했을 때, GPFDAT는 0111 1010 ->0x7a
	//0111 1'1'10 -> 0111 1'0'10
	if ((*GPFDAT & 0x7e) == 0x7a) return 1;
	else return 0;
}



void Main()

{

	volatile int i, key = 0;



	LED_Init(); 

	Key_Init();

	while(1){

		key = Get_Key_byPolling();

		if(key) LED_On();

		else LED_Off();
	}

}


