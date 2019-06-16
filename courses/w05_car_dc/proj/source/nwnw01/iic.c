/*********************************************************************
;* Project Name : mDirac III
;*
;* Copyright 2005 by Samsung Electronics, Inc.
;* All rights reserved.
;*
;* Project Description :
;* This software is only for verifying functions of the mDirac III
;* Anybody can use this code without our permission.
;**********************************************************************
;*
;*	Description	:	Code for the basic function for IIC.
;*					It can support write and read mode with 7-bit addresses
;*					Can make the 10-bit address write and read mode
;*					with assemble these functions.
;*	
;*	History
;*			R0.0 (2005.9.30) : Y.C.Kwon draft
;*
;**********************************************************************/

#include "2450addr.h"
#include "my_lib.h"

#define	SlaveRX			(0)
#define	SlaveTX			(1)
#define	MasterRX		(2)
#define	MasterTX		(3)



static volatile char *IIC_BUFFER;
static volatile unsigned int IIC_PT;
static unsigned int IIC_DATALEN;
static volatile unsigned char IIC_STAT;


__attribute__ ((interrupt ("IRQ"))) void IIC_Int(void);
void IIC_Int( void)
{
	IIC_STAT = rIICSTAT;
      
	switch( (IIC_STAT>>6)&0x3) {

	case SlaveRX	:	break;

	case SlaveTX	:	break;

	case MasterRX	:	if (IIC_PT>0)
							IIC_BUFFER[IIC_PT-1] = rIICDS;
						IIC_PT++;

						if (IIC_PT==IIC_DATALEN)
							rIICCON 	&=  ~(1<<7);
						else if (IIC_PT>IIC_DATALEN)
							rIICSTAT	=	0x90;			//	Stop Master Rx condition

						rIICCON &= ~(1<<4);					//	Clear pending bit to resume
						break;

	case MasterTX	:	if (IIC_PT<IIC_DATALEN)
							rIICDS	=	IIC_BUFFER[IIC_PT];
						else	
							rIICSTAT= 	0xd0;				//	Stop Master Tx condition, ACK flag clear
						IIC_PT++;

						rIICCON &= ~(1<<4);					//	Clear pending bit to resume
						break;
	}

	IIC_STAT&=0xf;
	ClearPending(BIT_IIC);
}


void IIC_open( unsigned int freq)		//	Hz order.
{
	unsigned int	clk_prescaler, clk_divider;

	rGPECON &= ~(0xf<<28);			//IICSCL& IICSDA fixed-
    rGPECON |= (0xa<<28);			//fixed-
    rGPEUDP &= ~(0xf<<28);			//pull-up enable fixed-
    rGPEUDP |= (0xa<<28);			//fixed-
	
     Uart_Printf("(PCLK>>4) =0x%x ((PCLK>>4)/freq)=0x%x\n",(PCLK>>4),((PCLK>>4)/freq));
	if (((PCLK>>4)/freq)>0xf) {
		clk_prescaler	=	1;
		clk_divider		=	(PCLK>>9)/freq;		//	PCLK/512/freq
	} else {
		clk_prescaler	=	0;
		clk_divider		=	(PCLK>>4)/freq;		//	PCLK/16/freq
	}

    pISR_IIC = (unsigned)IIC_Int;
	rINTMSK1 &= ~(BIT_IIC);

	//	Prescaler IICCLK=PCLK/16, Enable interrupt, Transmit clock value Tx clock=IICCLK/16
	rIICCON		=	(clk_prescaler<<6) | (1<<5) | (clk_divider&0xf);

	rIICADD		=	0x10;							//	Slave address = [7:1]
	rIICSTAT	=	0x10;                  			//	IIC bus data output enable(Rx/Tx)
	rIICLC		=	0;		 						//	SDA Filter disable
}


void IIC_close( void)
{
	rINTMSK1 |= BIT_IIC;

	rIICSTAT = 0x0;                    		//	IIC bus data output disable(Rx/Tx)
}


//	Write Mode Format with 7-bit addresses
void IIC_Write( unsigned char SlaveAddr, char *Data, unsigned int n)
{
	while(rIICSTAT&(1<<5));					//	Wait until IIC bus is free.

	IIC_BUFFER	=	Data;
	IIC_PT		=	0;
	IIC_DATALEN	=	n;

	rIICCON 	|=  (1<<7);
	rIICDS		=	SlaveAddr;
	rIICSTAT	=	0xF0;					//	Master Tx Start.
}


void IIC_Wait( void)						//	Waiting for the command takes effect.
{											//	But not for IIS bus free.
	while(IIC_PT<=IIC_DATALEN);
}


unsigned char IIC_Status( void)						//	Return IIC Status Register value at last interrupt occur.
{
	return	IIC_STAT;
}