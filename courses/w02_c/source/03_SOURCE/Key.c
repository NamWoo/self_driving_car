#include "2450addr.h"
#include "option.h"
#include "libc.h"

//Function Declaration 
void Key_Port_Init(void);
void Key_Get_Pressed_with_LED();
int Key_Get_Pressed();
int Key_Wait_Get_Pressed();
void Key_Wait_Get_Released();

//Function
void Key_Port_Init(void)
{
	/* GPFCON -Input Mode GPF[2:6] */
	/* YOUR CODE HERE */
	
    rGPFDAT &= ~(0x3f<<2);
	rGPFUDP &= ~(0x3ff <<4);
	rGPFUDP |= (0x2aa <<4);
	rGPFCON &= ~(0x3ff <<4); 	

	/* GPFCON, GPGCON - outputmode GPF7, GPG0 */
	/* YOUR CODE HERE */	
	rGPFDAT |= (0x1<<7);
	rGPGDAT |= 0x1;

	rGPFCON &= ~(0x3<<14);
	rGPGCON &= ~0x3;
	rGPFCON |= (0x1<<14);
	rGPGCON |= 0x1;

}

/*void Key_Get_Pressed_with_LED()
{
	// TO DO : [1]1�� key => LED1, [2]2�� key => LED2, [3]3�� key => LED3, [4]4�� key => LED4
	int i;	

	rGPFDAT &= ~(0x1<<7);

	if((~(rGPFDAT) >> 2) & 0x1)
	{
		rGPGDAT &= ~(0x1<<4);
		for(i=0;i<0xffff;i++);
		rGPGDAT |= (0x1<<4);
				
	}

	if((~(rGPFDAT) >>3) & 0x1)
	{
		rGPGDAT &= ~(0x1<<5);
		for(i=0;i<0xffff;i++);
		rGPGDAT |= (0x1<<5);
	}
	if((~(rGPFDAT) >>4) & 0x1)	
	{
		rGPGDAT &= ~(0x1<<6);
		for(i=0;i<0xffff;i++);
		rGPGDAT |= (0x1<<6);
	}
	if((~(rGPFDAT) >>5) & 0x01)
	{
		rGPGDAT &= ~(0x1<<7);
		for(i=0;i<0xffff;i++);
		rGPGDAT |= (0X1<<7);
	}	
}*/

int Key_Get_Pressed()
{
	/* TO DO : �Էµ� Ű���� Ȯ���Ͽ� �����ϴ� �Լ� */
	int i,j, keyval;
	int arr[4]={4,5,6,7};	
	/* YOUR CODE HERE */
	for(i=0; i<2; i++)
	{	
		rGPFDAT |= 0x1<<7;
		rGPGDAT |= 0x1<<0;
		(i==1)?(rGPGDAT &= ~0x1):(rGPFDAT &= ~(0x1<<7));

		keyval = (~(rGPFDAT>>2) & 0xF);
		/* TO DO : �Էµ� Ű���� Ȯ���Ͽ� �����ϴ� switch case���� �ۼ��Ͻÿ� */

/*		switch(keyval)
		{
			case 1: 
				rGPGDAT &= ~(0x1<<4); 
				for(i=0;i<0xffff;i++);
				break;
			case 2: 
				rGPGDAT &= ~(0x1<<5); 
				for(i=0;i<0xffff;i++);
				break;
			case 4: 
				rGPGDAT &= ~(0x1<<6); 
				for(i=0;i<0xffff;i++);
				break;
			case 8: 
				rGPGDAT &= ~(0x1<<7); 
				for(i=0;i<0xffff;i++);
				break;
			default:
				rGPGDAT |= (0xf<<4);
		}*/
		
		//Array ver
		for(j=0; j<4;)
		{
			if(keyval & 0x1)
			{
				rGPGDAT &= ~( 0x1<< arr[j] );
				for(i=0;i<0xffff;i++);
			}
			else
			{
				j++;
				keyval >> 1;
			}
		}

/*
		for(i=0; i<2; i++)
		{
			rGPGDAT |= 0x1 <<7;
			rGPGDAT |= 0x1 <<0;
			(i==1`)?(rGPGDAT &= !0x1):
			*/
	}

	return 0;

}

int Key_Wait_Get_Pressed()
{
	/* TO DO : Ű�� �������� ������ ���� �����ϵ��� ��ٷ� �ִ� �Լ� */
	int a; 
	while (! (a= Key_Get_Pressed()));
	return a; 
}

void Key_Wait_Get_Released()
{	
	/* TO DO : Ű�� �������� �ʾ��� ���� ��Ÿ���� �Լ� */
	Uart_Send_String("released\n");
	while(Key_Get_Pressed());
}
