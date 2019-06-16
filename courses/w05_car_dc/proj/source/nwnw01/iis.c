/*======================================================================

 Project Name : S3C2450

 Copyright 2006 by Samsung Electronics, Inc.
 All rights reserved.

 Project Description :
 This software is only for verifying functions of the S3C2450. 
 Anybody can use this code without our permission.

 File Name    : iis.c
 Description  : S3C2450 IIS module code
 Author       : Yeondu Jeoung
 Dept         : AP
 Created Date : 2018.06.20
 Version      : 0.0
 History
   R0.0 (2018.06.20): Yeondu draft
		- S3C2450 IIS test code is derived from S3C2413A IIS test code.
		
=======================================================================*/

#include "my_lib.h"
#include "2450addr.h"
#include "wm8960.h"
#include "sound/heart_44KHz.h"

#define PLAY_IIS_SPEAK    0
#define PLAY_IIS_HP    1
#define RECORD_MIC_IN  2
#define PLAY_BYPASS  3
#define PLAY_nwnw01  4


// Global variables
char IIS_MasterClk_Sel = 0; 
unsigned int save_GPE_CON, save_GPG_CON;
float IIS_Codec_CLK;

void IIS_PlayWave_DMA2(unsigned char *start_addr, unsigned int play_size);
__attribute__ ((interrupt ("IRQ"))) void DMA2_Done(void);

//============================== [ IIS Drivers ] ===============================

// Setting Port related to IIS  
void IIS_Port_Init(void)
{
	save_GPG_CON = rGPGCON;	// L3
	save_GPE_CON = rGPECON;	// IIS
   	
   	//----------------------------------------------------------
	//PORT G GROUP
	//Ports  :   GPG0       GPG1        GPG2  
	//Signal :  L3MODE     L3DATA      L3CLK
	//Setting:  OUTPUT     OUTPUT      OUTPUT 
	//	        [1:0]      [3:2]       [5:4]
	//Binary :  01          01           01 
	//----------------------------------------------------------    
    //rGPGCON = rGPGCON & ~(0x3f) | (1<<4)|(1<<2)|(1); // output setting
   
   	//-------------------------------------------------------------------------------
	//PORT E GROUP
	//Ports  :   GPE4  			GPE3           GPE2         GPE1           GPE0 
	//Signal :   I2S DO         I2S DI         CDCLK        I2S CLK        I2S LRCLK
	//Binary :   10,            10,            10,          10,            10  
	//-------------------------------------------------------------------------------
	rGPECON = (rGPECON & ~(0x3ff)) | 0x2aa; // IIS function setting
	rGPEUDP = 0xffffffff; // pull_up_down disable
	rGPHCON= (rGPHCON&~(0xf<<26))|(0xa<<26);
	rMISCCR = ((rMISCCR  & ~(0x07 << 4)) | (0x04 << 4));	
}


void IIS_Port_Return(void)
{
	rGPGCON = save_GPG_CON;
   	rGPECON = save_GPE_CON;
}


struct WM8960_REG WM8960_Speak_InitValue[]= {

	{((WM8960_RESET<<1)+0x0), 0x00},			//Reset WM8960   
	{((WM8960_APOP1  	<<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
    {((WM8960_APOP2  	<<1)+0x0), 0x40},		//Enable DISOP
	{WM8960_DELAY, 0x19},						//Delay (400mS) to remove any residual charge on HP output.    
	{((WM8960_POWER2 	<<1)+0x0), 0x7f},		//Enable LOUT1 and ROUT1
	{((WM8960_APOP2  	<<1)+0x0), 0x00},		//Enable DISOP
	{((WM8960_POWER1 	<<1)+0x0), 0xc0},		//Enable VMID SEL = 2x50K Ohm Dividere
	{WM8960_DELAY, 0x64},				//Delay (50mSeconds) to allow HP amps to settle
	{((WM8960_APOP1  	<<1)+0x0), 0x01},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
	{((WM8960_POWER2 	<<1)+0x1), 0xf8},		//Enable LOUT1 and ROUT1
	{((WM8960_ADDCTL1	<<1)+0x1), 0xD1},		//
	{((WM8960_POWER3  	<<1)+0x0), 0x0C},		//Enable left and right output mixers
	{((WM8960_LOUTMIX1	<<1)+0x1), 0x50},		//Enable Left DAC to left mixer (LINPUT3 to Output Mixer)
	{((WM8960_ROUTMIX2	<<1)+0x1), 0x50},		//Enable Right DAC to right mixer    
	{((WM8960_ADDCTL4	<<1)+0x0), 0x0A},		// JD2 used for Jack Detect Input
	{((WM8960_ADDCTL2	<<1)+0x0), 0x40},		// HPDETECT HIGH = Speaker 
	{((WM8960_ADDCTL3	<<1)+0x0), 0x08},		// HPDETECT HIGH = Speaker 

//PLL 12.288MHz	 SysCLK 12.288MHz	F2 98.304 MHz
	//CLKSEL = 0
	//MS = 0
	//WL = 10
	//SYSCLKDIV =0
	//ADCDIV=000
	//DACDIV=000
	
	{((WM8960_CLOCK1  	<<1)+0x0), 0x00}, // DACDIV, CLKSEL
	{((WM8960_IFACE1  	<<1)+0x0), 0x00},

	{((WM8960_LOUT1   	<<1)+0x1), 0x79},		//LOUT1VOL (HP) = -20dB
	{((WM8960_ROUT1   	<<1)+0x1), 0x79},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
	{((WM8960_LOUT2   	<<1)+0x1), 0x79},		//LOUT2VOL (HP) = -20dB
	{((WM8960_ROUT2   	<<1)+0x1), 0x79},		//ROUT2VOL (HP) = -20dB, Enable OUT2VU, load volume settings to both left and right channels
	{((WM8960_CLASSD3 	<<1)+0x0), 0xcc},		//Left and Right Speakers Enabled	
	{((WM8960_IFACE1  	<<1)+0x0), 0x02},		//
	{((WM8960_CLASSD1 	<<1)+0x0), 0xf7},		//Left and Right Speakers Enabled	
	{((WM8960_DACCTL1 	<<1)+0x0), 0x04}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)
	
};


//WM8960_nwnw01
//only LD2LO off and LB2LO on!
struct WM8960_REG WM8960_nwnw01[]= {

	{((WM8960_RESET<<1)+0x0), 0x00},			//Reset WM8960   
	{((WM8960_APOP1  	<<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
    {((WM8960_APOP2  	<<1)+0x0), 0x40},		//Enable DISOP
	{WM8960_DELAY, 0x19},						//Delay (400mS) to remove any residual charge on HP output.    
	{((WM8960_POWER2 	<<1)+0x0), 0x7f},		//Enable LOUT1 and ROUT1
	{((WM8960_APOP2  	<<1)+0x0), 0x00},		//Enable DISOP
	{((WM8960_POWER1 	<<1)+0x0), 0xE0},		//Enable VMID SEL = 2x50K Ohm Dividere
	{WM8960_DELAY, 0x64},				//Delay (50mSeconds) to allow HP amps to settle
	{((WM8960_APOP1  	<<1)+0x0), 0x01},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
	{((WM8960_POWER2 	<<1)+0x1), 0xf8},		//Enable LOUT1 and ROUT1
	{((WM8960_ADDCTL1	<<1)+0x1), 0xD1},		//
	{((WM8960_POWER3  	<<1)+0x0), 0x2C},		//Enable left channel input PGA, LMIC, LOMIX done from output part ==>>LMIC on
	{((WM8960_LOUTMIX1	<<0)+0x1), 0x50},		//Enable Left DAC to left mixer (LINPUT3 to Output Mixer)	==>>LD2LO OFF
	{((WM8960_ROUTMIX2	<<1)+0x1), 0x50},		//Enable Right DAC to right mixer    
	{((WM8960_ADDCTL4	<<1)+0x0), 0x0A},		// JD2 used for Jack Detect Input
	{((WM8960_ADDCTL2	<<1)+0x0), 0x40},		// HPDETECT HIGH = Speaker 
	{((WM8960_ADDCTL3	<<1)+0x0), 0x08},		// HPDETECT HIGH = Speaker 

//output part
	{((WM8960_BYPASS1<<1)+0x0), 0xF0},	//Enable Left input boost to left output mixer (LB2LO), Left Vol = 0dB             
//input part
	// {((WM8960_RESET<<1)+0x0), 0x00},    //Reset WM8960
	// {((WM8960_POWER1<<1)+0x0), 0xE0},   //VMID=50K, Enable VREF, AINL
	// {((WM8960_POWER3<<1)+0x0), 0x28},   //Enable left channel input PGA, LMIC, LOMIX 출력부분까지 해결
	{((WM8960_LINVOL<<1)+0x1), 0x3F},   //Unmute Left input PGA (LINMUTE), LINVOL = 0dB, Volume Update IPVU 몽땅최대 0011F
	{((WM8960_LINPATH<<1)+0x1), 0x38},   //Left Input PGA to Left Input Mixer (LMIC2B), Boost = 29dB   1.0011.1000


//PLL 12.288MHz	 SysCLK 12.288MHz	F2 98.304 MHz
	//CLKSEL = 0
	//MS = 0
	//WL = 10
	//SYSCLKDIV =0
	//ADCDIV=000
	//DACDIV=000
	
	{((WM8960_CLOCK1  	<<1)+0x0), 0x00}, 		// DACDIV, CLKSEL
	{((WM8960_IFACE1  	<<1)+0x0), 0x00},

	{((WM8960_LOUT1   	<<1)+0x1), 0x79},		//LOUT1VOL (HP) = -20dB
	{((WM8960_ROUT1   	<<1)+0x1), 0x79},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
	{((WM8960_LOUT2   	<<1)+0x1), 0x79},		//LOUT2VOL (HP) = -20dB
	{((WM8960_ROUT2   	<<1)+0x1), 0x79},		//ROUT2VOL (HP) = -20dB, Enable OUT2VU, load volume settings to both left and right channels
	{((WM8960_CLASSD3 	<<1)+0x0), 0xcc},		//Left and Right Speakers Enabled	
	{((WM8960_IFACE1  	<<1)+0x0), 0x02},		//
	{((WM8960_CLASSD1 	<<1)+0x0), 0xf7},		//Left and Right Speakers Enabled	
	{((WM8960_DACCTL1 	<<1)+0x0), 0x04}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)
	
};


struct WM8960_REG WM8960_Bypass_init[]= {

	{((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                                                        
    {((WM8960_POWER1<<1)+0x0), 0xF2},	//VMID=50K, Enable VREF, AINL and AINR                                             
    //{((WM8960_POWER2<<1)+0x0), 0x60},	//Enable LOUT1 and ROUT1                                                           
    {((WM8960_POWER3<<1)+0x0), 0x3C},	//Enable left and right channel input PGA, Enable left and right channel input PGA 
    {((WM8960_LINPATH<<1)+0x1), 0x18},	//LINPUT1 not connected to PGA (LMN1)                                              
    {((WM8960_RINPATH<<1)+0x1), 0x18},	//RINPUT1 not connected to PGA (RMN1)                                              
    {((WM8960_LINVOL<<1)+0x1), 0x3f},	//LIN2 Boost = 0dB                                                                 
    {((WM8960_RINVOL<<1)+0x1), 0x3f},	//RIN2 Boost = 0dB                                                                 
    {((WM8960_BYPASS1<<1)+0x0), 0x80},	//Enable Left input boost to left output mixer (LB2LO), Left Vol = 0dB             
    {((WM8960_BYPASS2<<1)+0x0), 0x80},	//Enable Right input boost to right output mixer (RB2RO), Right Vol = 0dB          
    {((WM8960_CLASSD3 	<<1)+0x0), 0xcc},		//33, Left and Right Speakers Enabled  
    {((WM8960_CLASSD1 	<<1)+0x0), 0xf7},		//31, Left and Right Speakers Enabled                                      
    {((03<<1)+0x1), 0x79}	//ROUT1 Vol = 0dB, volume update enabled 
	

//#define WM8960_POWER1		0x19 	0f2 // AINL, AINR
//#define WM8960_POWER3		0x2f   03c // LMIC, RMIC, LOMIX, ROMIX
//#define WM8960_LINVOL		0x0    13f // LINMUTE???, LINVOL(default)
//#define WM8960_RINVOL		0x1	   13f // RINMUTE???, LINVOL(default)
//#define WM8960_LINPATH	0x20   118 // LMN1,LMN2/,LMN3/, PGA(13dB),LMIC2B
//#define WM8960_RINPATH	0x21   118 // LMN1,LMN2/,LMN3/, PGA(13dB),LMIC2B
//#define WM8960_LOUT2		0x28    17f
//#define WM8960_ROUT2		0x29	17f

//#define WM8960_LOUTMIX1	0x22	150	//LD2LO,LI2LO
//#define WM8960_ROUTMIX2	0x25	150	//RD2LO,RI2RO
//#define WM8960_BYPASS1	0x2d   040 // LB2LO. LB2LOVOL(default)
//#define WM8960_BYPASS2	0x2e	040 // RB2RO, RB2ROVOL(default)
//#define WM8960_CLASSD1	0x31 	0f7 //SPK ON
//#define WM8960_CLASSD3	0x33	080	//DC/AC GAIN
//#define WM8960_MONOMIX1	0x26	3<<3
//#define WM8960_ALC1		0x11	07b
	
};

struct WM8960_REG WM8960_JACK_init[]= {

	{((WM8960_APOP1  	<<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
    {((WM8960_APOP2  	<<1)+0x0), 0x40},		//Enable DISOP 
	{WM8960_DELAY, 0x19},						//Delay (400mS) to remove any residual charge on HP output.    
	{((WM8960_POWER2 	<<1)+0x0), 0x61},		//Enable LOUT1 and ROUT1 SPKL , SPKR disable
	{((WM8960_APOP2  	<<1)+0x0), 0x00},		//Enable DISOP
	{((WM8960_POWER1 	<<1)+0x0), 0xc0},		//Enable VMID SEL = 2x50K Ohm Dividere
	{WM8960_DELAY, 0x64},				//Delay (50mSeconds) to allow HP amps to settle
	{((WM8960_APOP1  	<<1)+0x0), 0x01},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
	{((WM8960_POWER2 	<<1)+0x1), 0xd1},		//Enable LOUT1 and ROUT1
	{((WM8960_ADDCTL1	<<1)+0x1), 0xD1},		//Slow Clock Enable 
	{((WM8960_POWER3  	<<1)+0x0), 0x0C},		//Enable left and right output mixers
	{((WM8960_LOUTMIX1	<<1)+0x1), 0x50},		//Enable Left DAC to left mixer (LINPUT3 to Output Mixer)
	{((WM8960_ROUTMIX2	<<1)+0x1), 0x50},		//Enable Right DAC to right mixer   
	//General purpose input /output
	{((WM8960_IFACE2	<<1)+0x0), (0x01<<6)}, // GPIO pin setting 
	{((WM8960_ADDCTL4	<<1)+0x0), 0x02},		// ADCLRC /GPIO set
	
     //HP jack dectect cap-less mode
	{((WM8960_ADDCTL2	<<1)+0x0), 0x60},		// HPDETECT High =Headphone, switch enable
	{((WM8960_ADDCTL3	<<1)+0x0), 0x0d},		// HPDETECT HIGH = Speaker /ALC Sample Rate 8K    
 
	{((WM8960_LDAC  	<<1)+0x0), 0xfe}, // LDACVOL
	{((WM8960_RDAC  	<<1)+0x0), 0xfe}, // LDACVOL	

	{((WM8960_CLOCK1  	<<1)+0x0), 0x00}, // DACDIV, CLKSEL
	{((WM8960_IFACE1  	<<1)+0x0), 0x00},

	{((WM8960_LOUT1   	<<1)+0x1), 0x7f},		//LOUT1VOL (HP) = -20dB
	{((WM8960_ROUT1   	<<1)+0x1), 0x7f},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
	{((WM8960_LOUT2   	<<1)+0x1), 0x7f},		//LOUT2VOL (HP) = -20dB
	{((WM8960_ROUT2   	<<1)+0x1), 0x7f},		//ROUT2VOL (HP) = -20dB, Enable OUT2VU, load volume settings to both left and right channels
	{((WM8960_CLASSD3 	<<1)+0x0), 0xcc},		//Left and Right Speakers Enabled	
	{((WM8960_IFACE1  	<<1)+0x0), 0x02},		//
	{((WM8960_CLASSD1 	<<1)+0x0), 0xf7},		//Left and Right Speakers Enabled	
	{((WM8960_DACCTL1 	<<1)+0x0), 0x04}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)
};

struct WM8960_REG WM8960_MIC_init[]= {

    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                                                                                  
    {((WM8960_POWER1<<1)+0x0), 0xEA},	//VMID=50K, Enable AINL and MICBIAS                                                                          
    //{((WM8960_POWER2<<1)+0x0), 0x40},	//Enable LOUT1                                                                                               
    {((WM8960_POWER3<<1)+0x0), 0x28},	//Enable left output mixer, Enable Left Input PGA                                                            
    {((32<<1)+0x1), 0x28},	//Not Connect LINPUT2 to non-inverting PGA (LMP2), LMICBOOST = +20dB, Connect left input PGA to Left input mixer 
    {((33<<1)+0x0), 0x00},	//Disconnect RINPUT1 to input PGA (RMN1)                                                                     
    {((00<<1)+0x1), 0x3e},	//Unmute left input PGA (LINMUTE), Left Input PGA Vol = 0dB, Volume Update                                   
    //{((45<<1)+0x0), 0x80},	//Left Input Boost mixer to Left output mixer (LB2L0), Vol = 0dB                                             
    //{((02<<1)+0x1), 0x79},	//LOUT1 Vol = 0dB, volume update enabled                                                                     
    {((48<<1)+0x0), 0x02},	//Microphone Bias Voltage Control = 0.65 * AVDD    
    //ADC control converter 
    {((5<<1)+0x0), 0x00},	//ADC polarity control Not inverted
    {((23<<1)+0x0), 0x00},	//ADC Data Output Select 
    {((21<<1)+0x1), 0xfE},	//LADCVOL volumn control 

	//with ADCLRC must be set  ALRCGPIO set 1 
    {((9<<1)+0x0), 0x60},	//ALRCGPIO GPIO Pin 
  };

#define WM8960_MIC_SIZE (sizeof(WM8960_MIC_init)/sizeof(WM8960_MIC_init[0]))

#define WM8960_JACK_SIZE (sizeof(WM8960_JACK_init)/sizeof(WM8960_JACK_init[0]))

#define WM8960_INIT_SIZE (sizeof(WM8960_Speak_InitValue)/sizeof(WM8960_Speak_InitValue[0]))

#define WM8960_BYPASS_SIZE (sizeof(WM8960_Bypass_init)/sizeof(WM8960_Bypass_init[0]))

void WriteCodecModule( char CodecIICID, char Addr, char Data)
{
	char D[2];
	
	D[0]=Addr;
	D[1]=Data;
	IIC_Write( CodecIICID, D, 2);
	IIC_Wait();
}

void InitWM8960(int mode)
{
   int i;
   IIC_open(100000);
   if(mode==PLAY_IIS_SPEAK)
   {
	for(i=0; i<WM8960_INIT_SIZE; i++) 
		WriteCodecModule( 0x34, WM8960_Speak_InitValue[i].addr, WM8960_Speak_InitValue[i].data);   

   }
   else if(mode==PLAY_IIS_HP)
   {
	for(i=0; i<WM8960_JACK_SIZE; i++) 
		WriteCodecModule( 0x34, WM8960_JACK_init[i].addr, WM8960_JACK_init[i].data);   

   }
   else if(mode==RECORD_MIC_IN)
   {
	for(i=0; i<WM8960_MIC_SIZE; i++) 
		WriteCodecModule( 0x34, WM8960_MIC_init[i].addr, WM8960_MIC_init[i].data);   

   } 
   else if(mode==PLAY_BYPASS)
   {
	for(i=0; i<WM8960_BYPASS_SIZE; i++) 
		WriteCodecModule( 0x34, WM8960_Bypass_init[i].addr, WM8960_Bypass_init[i].data);   
   }
   else if(mode==PLAY_nwnw01)
   {
	for(i=0; i<WM8960_BYPASS_SIZE; i++) 
		WriteCodecModule( 0x34, WM8960_nwnw01[i].addr, WM8960_nwnw01[i].data);   


   }
   




   IIC_close();  
}

// IIS source clock selection
void Select_PCLK(void)
{
	unsigned int pdf = 3; // (5->3) hongyk. prescaler division factor

	/*	;==========================
//	; CLOCK & POWER MANAGEMENT
//	;========================== */
	/*
	.equ	HCLKCON,	0x4c000030
	.equ	PCLKCON,	0x4c000034
	.equ	SCLKCON,	0x4c000038
	.equ	CLKSRCCON,	0x4c000020
	.equ	CLKDIV0CON,	0x4c000024	//Clock divider control
	.equ	CLKDIV1CON,	0x4c000028
	.equ	EPLLCON,	0x4c000018	//EPLL Control
	*/
	// SYSCON register setting
	rPCLKCON |= (1<<9); // PCLK bus block of i2s enable
	rSCLKCON |= (1<<9); // I2S source clock enable
	rCLKSRC = (rCLKSRC & ~(3<<14)) | (0<<14); // I2S first source clock selection
	//rCLKDIV1 &= ~(0xf<<12)|(0x6<<12);	// I2S clock divider for EPLL.
	// IIS clock register setting
	rIISMOD = (rIISMOD & ~(7<<10)) | (0<<12)|(1<<10); // internal codec clock source, PCLK Master mode
	rIISMOD = (rIISMOD & ~(3<<3))|(2<<3);
	rIISPSR = (1<<15)|(pdf<<8);  // prescaler enable, prescaler division factor[9:0]
	//In case PCLK = 50 MHz, IIS Codec CLK = 50/(5+1) = 8.34MHz-->22KHz
	Uart_Printf("\nIIS Master CLK(PCLK) = %4.2f MHz", (float)PCLK/1000000);
	IIS_Codec_CLK = (float)PCLK/(pdf+1);
	Uart_Printf("\nIIS Codec CLK = %4.2f MHz", IIS_Codec_CLK/1000000);

	IIS_MasterClk_Sel = 0;
}
//=================================== [ IIS Test codes ] ==================================

void DMA2_Done(void)
{
	rINTSUBMSK |= BIT_SUB_DMA2; 	
	rINTMSK1 |= (BIT_DMA);
	rSUBSRCPND = BIT_SUB_DMA2;
	ClearPending(BIT_DMA);	

	rIISCON	&= ~(1<<2)|(0<<0);
    rIISCON |= (1<<2)|(1<<0);
	
  	Uart_Printf("\nTX DMA Done ~~~");

	rINTMSK1 &= ~(BIT_DMA);
	rINTSUBMSK &= ~BIT_SUB_DMA2; 	
}

void Play_Iis_speak(void)
{	
	unsigned int wave_size, fs;
	unsigned char *wave_start_addr;

	Uart_Printf("\n Speak Play \n");

	wave_size = *(unsigned int *)(HEART + 0x28); //0x28 = 40
	fs = *(unsigned int *)(HEART + 0x18);
	wave_start_addr = HEART+44;

	Uart_Printf("wave_size is %d\n", wave_size);
	Uart_Printf("fs is %d\n", fs);
	Uart_Printf("wave_start_addr is %p\n", wave_start_addr);

	IIS_Port_Init(); 
	Select_PCLK();

	InitWM8960(PLAY_IIS_SPEAK); //PLAY_nwnw01
	// InitWM8960(PLAY_nwnw01); //PLAY_nwnw01
	IIS_PlayWave_DMA2(wave_start_addr,1160312);

	// need to add mute function
	
	IIS_Port_Return();
}

void Play_Iis_Bypass(void)
{	
	Uart_Printf("\n Bypass Play \n");
        
	IIS_Port_Init(); 
	Select_PCLK();

	InitWM8960(PLAY_BYPASS);

}

void IIS_PlayWave_DMA2(unsigned char *start_addr, unsigned int play_size)
{
	unsigned char Exit_Key;
	
	
	pISR_DMA = (unsigned)DMA2_Done;
	ClearPending(BIT_DMA);	
	rSUBSRCPND = BIT_SUB_DMA2;

		
	// this setting for only TX   	
  	rIISCON = (0<<5) + (0<<4) +(1<<2) + (0<<1)+0;	   
  	// using pclk, tx only , left for channel,iis format ,384fs , 32fs ,16bit  	
 	rIISMOD = (rIISMOD & ~(0xfff)) | (0<<10)|(0<<8)|(0<<7)|(0<<5)|(2<<3)|(0<<1)|(0<<0);

  	
	rIISFIC = 0+(1<<15);	  
    rIISFIC = 0+(0<<15);	  
    	
	Uart_Printf("\nIISLRCK = %d Hz", (int) IIS_Codec_CLK/384);

	rINTMSK1 = ~(BIT_DMA);
	rINTSUBMSK = ~(BIT_SUB_DMA2);


	
	Uart_Printf("If you want to exit, Press the 'x' key.\n");
	Uart_Printf("Now Play...\n");
	
	Uart_Printf("If you want to disable IIS tx(PAUSE), Press '0' key\n");
	Uart_Printf("If you want to enable IIS tx, Press '1' key\n");
	Uart_Printf("If you want to stop DMA channel(STOP), Press '2' key\n");
	Uart_Printf("If you want to start DMA channel, Press '3' key\n");
	
	//DMA2 Register Setting 
	rDISRC2  = (int)(start_addr); 
	rDISRCC2 = (0<<1) + (0<<0); 		  
	rDIDST2  = ((unsigned int)0x55000010);			
	rDIDSTC2 = (1<<1) + (1<<0); 
	// 31: ACK 	30: sync pclk  29:curr_tc int setting 28:unit transfer 27:single service 22: reload 20:half word 
	rDCON2   = (1<<31)+(0<<30)+(1<<29)+(0<<28)+(0<<27)+(0<<22)+(2<<20)+(play_size/4);
	// 5:1= 4th bit is the tx iis     0:set = hw zero = sw
	rDMAREQSEL2 = (4<<1)|(1);
	
	rDMASKTRIG2 = (0<<2) + (1<<1) + (0<<0);	    //No-stop, DMA2 channel On, and No-sw trigger 
       
	//IIS Tx Start
	rIISCON |= 0x1;		 //IIS Interface start

	while(1)
	{
		Exit_Key=Uart_GetChar();
		
    	//->
		//khs.050510
		//	added for I2S bug test
    	if(Exit_Key == '0'){
			rIISCON |= (1<<4);
    		Uart_Printf("\nPAUSE...\n");
    	}
		if(Exit_Key == '1'){
			rIISCON &= ~(1<<3);
		}
		if(Exit_Key == '2'){
			rDMASKTRIG2 |= (1<<2);
			rIISFIC &= ~(1<<13);	//* tx fifo disable
			while((rIISFIC & 0x0FC0)!=0);	//* wait until tx fifo gets empty
    		Uart_Printf("\nSTOP...\n");
		}
		if(Exit_Key == '3'){
			rIISFIC |= (1<<13);	//* tx fifo enable
			rDISRC2  = (int)(start_addr);
			rDMASKTRIG2 &= ~(1<<2);
			rDMASKTRIG2 |= (1<<1);
		}
		//<-		

		if( (Exit_Key == 'x') | (Exit_Key == 'X')) 
			break;
		Uart_Printf("STAT2: 0x%x CURR_TC: 0x%x		DCDST2: 0x%x\n", rDSTAT2&0x300000, rDSTAT2&0xfffff, rDCDST2);
	}
    	
	//IIS Tx Stop
	Timer_Delay(10);			 //For end of H/W Tx
	rIISCON	&= ~(1<<0);	    //IIS Interface stop

	rDMASKTRIG2  = (1<<2);	 //DMA2 stop
	rIISFIC = 0x0;	    //For FIFO flush
		
	rINTSUBMSK |= (BIT_SUB_DMA2);
	rINTMSK1 |= (BIT_DMA);
 	
	Uart_Printf("\nEnd of Play!\n");
}