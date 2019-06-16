/*
 * wm8960.h  --  WM8960 Soc Audio driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */


/* WM8960 register space */


#define WM8960_CACHEREGNUM 	56

#define WM8960_LINVOL		0x0
#define WM8960_RINVOL		0x1
#define WM8960_LOUT1		0x2
#define WM8960_ROUT1		0x3
#define WM8960_CLOCK1		0x4
#define WM8960_DACCTL1		0x5
#define WM8960_DACCTL2		0x6
#define WM8960_IFACE1		0x7
#define WM8960_CLOCK2		0x8
#define WM8960_IFACE2		0x9
#define WM8960_LDAC		0xa
#define WM8960_RDAC		0xb

#define WM8960_RESET		0xf
#define WM8960_3D		0x10
#define WM8960_ALC1		0x11
#define WM8960_ALC2		0x12
#define WM8960_ALC3		0x13
#define WM8960_NOISEG		0x14
#define WM8960_LADC		0x15
#define WM8960_RADC		0x16
#define WM8960_ADDCTL1		0x17
#define WM8960_ADDCTL2		0x18
#define WM8960_POWER1		0x19
#define WM8960_POWER2		0x1a
#define WM8960_ADDCTL3		0x1b
#define WM8960_APOP1		0x1c
#define WM8960_APOP2		0x1d

#define WM8960_LINPATH		0x20
#define WM8960_RINPATH		0x21
#define WM8960_LOUTMIX1		0x22
                        	
#define WM8960_ROUTMIX2		0x25
#define WM8960_MONOMIX1		0x26
#define WM8960_MONOMIX2		0x27
#define WM8960_LOUT2		0x28//Decimal 41
#define WM8960_ROUT2		0x29
#define WM8960_MONO			0x2a
#define WM8960_INBMIX1		0x2b
#define WM8960_INBMIX2		0x2c
#define WM8960_BYPASS1		0x2d
#define WM8960_BYPASS2		0x2e
#define WM8960_POWER3		0x2f
#define WM8960_ADDCTL4		0x30
#define WM8960_CLASSD1		0x31 //49

#define WM8960_CLASSD3		0x33
#define WM8960_PLLN		0x34
#define WM8960_PLLK1		0x35
#define WM8960_PLLK2		0x36
#define WM8960_PLLK3		0x37

#define WM8960_DELAY		0xFF

/*
 * WM8960 Clock dividers
 */
#define WM8960_SYSCLKDIV 	0
#define WM8960_DACDIV		1
#define WM8960_OPCLKDIV		2
#define WM8960_DCLKDIV		3
#define WM8960_TOCLKSEL		4
#define WM8960_SYSCLKSEL	5

#define WM8960_SYSCLK_DIV_1	(0 << 1)
#define WM8960_SYSCLK_DIV_2	(2 << 1)

#define WM8960_SYSCLK_MCLK	(0 << 0)
#define WM8960_SYSCLK_PLL	(1 << 0)

#define WM8960_DAC_DIV_1	(0 << 3)
#define WM8960_DAC_DIV_1_5	(1 << 3)
#define WM8960_DAC_DIV_2	(2 << 3)
#define WM8960_DAC_DIV_3	(3 << 3)
#define WM8960_DAC_DIV_4	(4 << 3)
#define WM8960_DAC_DIV_5_5	(5 << 3)
#define WM8960_DAC_DIV_6	(6 << 3)

#define WM8960_DCLK_DIV_1_5	(0 << 6)
#define WM8960_DCLK_DIV_2	(1 << 6)
#define WM8960_DCLK_DIV_3	(2 << 6)
#define WM8960_DCLK_DIV_4	(3 << 6)
#define WM8960_DCLK_DIV_6	(4 << 6)
#define WM8960_DCLK_DIV_8	(5 << 6)
#define WM8960_DCLK_DIV_12	(6 << 6)
#define WM8960_DCLK_DIV_16	(7 << 6)

#define WM8960_TOCLK_F19	(0 << 1)
#define WM8960_TOCLK_F21	(1 << 1)

#define WM8960_OPCLK_DIV_1	(0 << 0)
#define WM8960_OPCLK_DIV_2	(1 << 0)
#define WM8960_OPCLK_DIV_3	(2 << 0)
#define WM8960_OPCLK_DIV_4	(3 << 0)
#define WM8960_OPCLK_DIV_5_5	(4 << 0)
#define WM8960_OPCLK_DIV_6	(5 << 0)
struct WM8960_REG {
	unsigned char addr;
	unsigned char data;
};
void WriteCodecModule( char CodecIICID, char Addr, char Data);
void ReadCodecModule( char CodecIICID, char Addr, char *Data);
//void SetupCodecModule( char CodecIICID, WM8960_REG CodecModulData[], int CodecModuleDataSize);
#if 0
//------------------------------------------ WM8960 ----------------------------------------------
	// MISC
		
	/* Jack_Detect_Switch */
	/* Stereo DAC to HP and SPK output. Jack Detect Enabled for JD2 */
	{((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960
	
	{((WM8960_POWER1<<1)+0x0), 0xC0},	//VMID=50K, Enable VREF  
	{((WM8960_POWER2<<1)+0x1), 0xF8},	//Enable DACL, DACR, LOUT1, ROUT1, SPKL and SPKR  
	{((WM8960_POWER3<<1)+0x0), 0x0C},	//Enable left output mixer and right output mixer  
	
	{((49<<1)+0x0), 0xF7},	//Left and Right Speakers Enabled  
	{((37<<1)+0x1), 0x50},	//Right DAC to right output mixer enabled (RD2RO)
	{((34<<1)+0x1), 0x50},	//Left DAC to left output mixer enabled (LD2LO) 
	{((48<<1)+0x0), 0x0A},	//JD2 used for Jack Detect Input 
	{((24<<1)+0x0), 0x40},	//HPDETECT HIGH = Speaker 
	{((23<<1)+0x1), 0xC1},	//Enable slow clock (TOEN) 
	{0xff,0xff},
	{((40<<1)+0x1), 0x79}, 	//LSPK Vol = 0dB, volume update enabled  
	{((41<<1)+0x1), 0x79}, 	//RSPK Vol = 0dB, volume update enabled
	{((02<<1)+0x1), 0x79}, 	//LOUT1 Vol = 0dB, volume update enabled   
	{((03<<1)+0x1), 0x79}, 	//ROUT1 Vol = 0dB, volume update enabled    
	{((05<<1)+0x0), 0x00} 	//Unmute DAC digital soft mute          	


 	/* JackMic_to_HPR_ForMIC */
 	/* Customer evaluation board, Jack microphone to HPR */
   {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960
   {((WM8960_POWER1<<1)+0x0), 0xD2},	//VMID=50K, Enable AINR and MICBIAS  
   {((WM8960_POWER2<<1)+0x0), 0x20},	//Enable ROUT1  
   {((WM8960_POWER3<<1)+0x0), 0x14},	//Right output mixer enable, Right input PGA enable 
   {((33<<1)+0x1), 0x38},	//RMICBOOST = +29dB, Connect right input PGA to Right Input Boost (RMIC2B) 
   {((01<<1)+0x1), 0x17},	//Unmute right input PGA (RINMUTE), Right Input PGA Vol = 0dB, Volume Update  
   {((46<<1)+0x0), 0x80},	//Right input boost mixer to right output mixer (RB2RO, vOL = 0dB 
   {((03<<1)+0x1), 0x79}	//ROUT1 Vol = 0dB, volume update enabled    
    
    
    /* SiliconMIC_to_HPL */
    /* Customer evaluation Board, on board silicon microphone to HPL */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                                                                                  
    {((WM8960_POWER1<<1)+0x0), 0xE2},	//VMID=50K, Enable AINL and MICBIAS                                                                          
    {((WM8960_POWER2<<1)+0x0), 0x40},	//Enable LOUT1                                                                                               
    {((WM8960_POWER3<<1)+0x0), 0x28},	//Enable left output mixer, Enable Left Input PGA                                                            
    {((32<<1)+0x1), 0x68},	//Connect LINPUT2 to non-inverting PGA (LMP2), LMICBOOST = +20dB, Connect left input PGA to Left input mixer 
    {((33<<1)+0x0), 0x00},	//Disconnect RINPUT1 to input PGA (RMN1)                                                                     
    {((00<<1)+0x1), 0x17},	//Unmute left input PGA (LINMUTE), Left Input PGA Vol = 0dB, Volume Update                                   
    {((45<<1)+0x0), 0x80},	//Left Input Boost mixer to Left output mixer (LB2L0), Vol = 0dB                                             
    {((02<<1)+0x1), 0x79},	//LOUT1 Vol = 0dB, volume update enabled                                                                     
    {((48<<1)+0x0), 0x03}	//Microphone Bias Voltage Control = 0.65 * AVDD                                                              
    
    
    
    
    //DAC setup
    /* DAC_to_ClassD_3.3V_Slave */ 
    /* Stereo DAC to Class D SPKVDD=+3.3V, 24 bit I2S, Slave Mode */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                            
    {((WM8960_POWER1<<1)+0x0), 0xC0},	//VMID=50K, Enable VREF                                
    {((WM8960_POWER2<<1)+0x1), 0x98},	//Enable DACL, DACR, SPKL and SPKR                     
    {((WM8960_POWER3<<1)+0x0), 0x0C},	//Enable left output mixer and right output mixer      
    {((49<<1)+0x0), 0xF7},	//Left and Right Speakers Enabled                      
    {((34<<1)+0x1), 0x00},	//Left DAC to left output mixer enabled (LD2LO), 0dB   
    {((37<<1)+0x1), 0x00},	//Right DAC to right output mixer enabled (RD2RO), 0dB 
    {((40<<1)+0x1), 0x79},	//LSPK Vol = 0dB, volume update enabled                
    {((41<<1)+0x1), 0x79},	//RSPK Vol = 0dB, volume update enabled                
    {((05<<1)+0x0), 0x00}	//Unmute DAC digital soft mute                         
    
    
    /* DAC_to_ClassD_5V_Slave */
    /* Stereo DAC to Class D SPKVDD=+5V, 24 bit I2S, Slave Mode */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                            
    {((WM8960_POWER1<<1)+0x0), 0xC0},	//VMID=50K, Enable VREF                                
    {((WM8960_POWER2<<1)+0x1), 0x98},	//Enable DACL, DACR, SPKL and SPKR                     
    {((WM8960_POWER3<<1)+0x0), 0x0C},	//Enable left output mixer and right output mixer      
    {((49<<1)+0x0), 0xF7},	//Left and Right Speakers Enabled                      
    {((51<<1)+0x1), 0x1B},	//DCGAIN = 1.52x (+3.6dB) and ACGAIN = 1.52x (+3.6dB)  
    {((34<<1)+0x1), 0x00},	//Left DAC to left output mixer enabled (LD2LO), 0dB   
    {((37<<1)+0x1), 0x00},	//Right DAC to right output mixer enabled (RD2RO), 0dB 
    {((40<<1)+0x1), 0x79},	//LSPK Vol = 0dB, volume update enabled                
    {((41<<1)+0x1), 0x79},	//RSPK Vol = 0dB, volume update enabled                
    {((05<<1)+0x0), 0x00}	//Unmute DAC digital soft mute                         
    
    /* DAC_to_L_ROUT1_Slave */
    /* Stereo DAC to HPL/R, 24bit I2S, Slave Mode */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                           
    {((WM8960_POWER1<<1)+0x0), 0xC0},	//VMID=50K, Enable VREF                               
    {((WM8960_POWER2<<1)+0x1), 0xE0},	//Enable DACL, DACR, LOUT1 and ROUT1                  
    {((WM8960_POWER3<<1)+0x0), 0x0C},	//Enable left output mixer and right output mixer     
    {((34<<1)+0x1), 0x00},	//Left DAC to left output mixer enabled (LD2LO), 0dB  
    {((37<<1)+0x1), 0x00},	//Right DAC to right output mixer enabled (RD2RO), 0dB
    {((02<<1)+0x1), 0x79},	//LOUT1 Vol = 0dB, volume update enabled              
    {((03<<1)+0x1), 0x79},	//ROUT1 Vol = 0dB, volume update enabled              
    {((05<<1)+0x0), 0x00}	//Unmute DAC digital soft mute  
    	
    	
    /* DAC_to_OUT3_Slave */
    /* DACL to OUT3, 24bit I2S, Slave Mode */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                         
    {((WM8960_POWER1<<1)+0x0), 0xC0},	//VMID=50K, Enable VREF                             
    {((WM8960_POWER2<<1)+0x1), 0x02},	//Enable DACL and OUT3                              
    {((WM8960_POWER3<<1)+0x0), 0x08},	//Enable Left Output Mixer                          
    {((38<<1)+0x0), 0x80},	//Left Channel mix enabled (L2MO)                   
    {((10<<1)+0x1), 0xFF},	//Left DAC = 0dB, volume update enabled             
    {((42<<1)+0x0), 0x00},	//Monoout mixer volume = 0dB                        
    {((34<<1)+0x1), 0x00},	//Left DAC to left output mixer enabled (LD2LO), 0dB
    {((05<<1)+0x0), 0x00}	//Unmute DAC digital soft mute                      
    
    
    
    
    // Bypass Setup
    /* L_RINPUT2_to_L_ROUT1_Bypass */
    /* L/RINPUT2 to L/ROUT1 Bypass */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                                                        
    {((WM8960_POWER1<<1)+0x0), 0xF0},	//VMID=50K, Enable VREF, AINL and AINR                                             
    {((WM8960_POWER2<<1)+0x0), 0x60},	//Enable LOUT1 and ROUT1                                                           
    {((WM8960_POWER3<<1)+0x0), 0x3C},	//Enable left and right channel input PGA, Enable left and right channel input PGA 
    {((32<<1)+0x0), 0x00},	//LINPUT1 not connected to PGA (LMN1)                                              
    {((33<<1)+0x0), 0x00},	//RINPUT1 not connected to PGA (RMN1)                                              
    {((43<<1)+0x0), 0x0A},	//LIN2 Boost = 0dB                                                                 
    {((44<<1)+0x0), 0x0A},	//RIN2 Boost = 0dB                                                                 
    {((45<<1)+0x0), 0x80},	//Enable Left input boost to left output mixer (LB2LO), Left Vol = 0dB             
    {((46<<1)+0x0), 0x80},	//Enable Right input boost to right output mixer (RB2RO), Right Vol = 0dB          
    {((02<<1)+0x1), 0x79},	//LOUT1 Vol = 0dB, volume update enabled                                           
    {((03<<1)+0x1), 0x79}	//ROUT1 Vol = 0dB, volume update enabled                                           
        
    
    /* L_RINPUT1_to_L_ROUT1_Bypass */
    /* L/RINPUT1 to L/ROUT1 Bypass */
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                                                       
    {((WM8960_POWER1<<1)+0x0), 0xF0},	//VMID=50K, Enable VREF, AINL and AINR                                            
    {((WM8960_POWER2<<1)+0x0), 0x60},	//Enable LOUT1 and ROUT1                                                          
    {((WM8960_POWER3<<1)+0x0), 0x3C},	//Enable left and right channel input PGA, Enable left and right channel input PGA
    {((00<<1)+0x1), 0x17},	//Unmute Left input PGA (LINMUTE), LINVOL = 0dB, Volume Update                    
    {((01<<1)+0x1), 0x17},	//Unmute Right input PGA (RINMUTE), RINVOL = 0dB, Volume Update                   
    {((32<<1)+0x1), 0x08},	//Left Input PGA to Left Input Mixer (LMIC2B), Boost = 0dB                        
    {((33<<1)+0x1), 0x08},	//Right Input PGA to Right Input Mixer (RMIC2B), Boost = 0dB                      
    {((45<<1)+0x0), 0x80},	//Left Input Boost mixer to Left output mixer (LB2L0), Vol = 0dB                  
    {((46<<1)+0x0), 0x80},	//Right Input Boost mixer to Right output mixer (RB2R0), Vol = 0dB                
    {((02<<1)+0x1), 0x79},	//LOUT1 Vol = 0dB, volume update enabled                                          
    {((03<<1)+0x1), 0x79}	//ROUT1 Vol = 0dB, volume update enabled                                          
        
        
    /* Jack_Mic_to_OUT3_Performance */
    /* Jack MIC (RINPUT1) to OUT3 - 0dB Path	*/
    
    {((WM8960_RESET<<1)+0x0), 0x00},	//Reset WM8960                                                                              
    {((WM8960_POWER1<<1)+0x0), 0xD0},	//VMID=50K, Enable VREF and AINR                                                         
    {((WM8960_POWER2<<1)+0x0), 0x02},	//Enable OUT3 + Mono Mix                                                                 
    {((WM8960_POWER3<<1)+0x0), 0x14},	//Right output mixer enable, Right input PGA enable                                      
    {((32<<1)+0x0), 0x00},	//LINPUT1 not connected to PGA                                                           
    {((33<<1)+0x1), 0x08},	//RINPUT1 connected to PGA, Right input PGA to Roght Input Boost mixer connected (RMIC2B)
    {((39<<1)+0x0), 0x80},	//Right output mixer to Mono output mixer = Enabled                                      
    {((46<<1)+0x0), 0x80},	//Enable Right Input boost mixer to Right output mixer, Vol = 0dB (RB2ROVOL)             
    {((42<<1)+0x0), 0x00},	//Mono output volume mixer = 0dB                                                         
    {((01<<1)+0x1), 0x17}	//Unmute right input PGA (RINMUTE), Right Input PGA Vol = 0dB, Volume Update             
        
        
    /* L_RINPUT3_to_L_ROUT1_Bypass */
    /* L/RINPUT3 to L/ROUT1 Bypass */
    (((WM8960_RESET<<1)+0x0), 0x00),	//Reset WM8960                                                                      
    (((WM8960_POWER1<<1)+0x0), 0xF0),	//VMID=50K, Enable VREF, AINL and AINR                                           
    (((WM8960_POWER2<<1)+0x0), 0x60),	//Enable LOUT1 and ROUT1                                                         
    (((WM8960_POWER3<<1)+0x0), 0x0C),	//Enable left and right channel input PGA                                        
    (((34<<1)+0x0), 0x80),	//Enable LINPUT3 to left output mixer (LI2LO), LINPUT3 to Left mixer vol = 0dB   
    (((37<<1)+0x0), 0x80),	//Enable RINPUT3 to right output mixer (RI2RO), RINPUT3 to Right mixer vol = 0dB 
    (((02<<1)+0x1), 0x79),	//LOUT1 Vol = 0dB, volume update enabled                                         
    (((03<<1)+0x1), 0x79),	//ROUT1 Vol = 0dB, volume update enabled                                         
        
    
        
	// ADC Setup
	/* L_RINPUT2_to_ADC_SlaveMode_24bitI2S */
	/*L/RINPUT2 to ADC, Slave Mode 24 bit I2S 48KHz */
	(((WM8960_RESET<<1)+0x0), 0x00),	//Reset WM8960  
	(((WM8960_POWER1<<1)+0x0), 0xFC),	//VMID=50K, Enable VREF, AINL, AINR, ADCL and ADCR  
	(((WM8960_POWER3<<1)+0x0), 0x30),	//Enable left and right channel input PGA  
	(((43<<1)+0x0), 0x0A),	//LIN2 Boost = 0dB 
	(((44<<1)+0x0), 0x0A),	//RIN2 Boost = 0dB 
	(((32<<1)+0x0), 0x08),	//LINPUT1 not connected to PGA (LMN1), Connect left input PGA to left input boost (LMIC2B), Left PGA Boost = 0dB
	(((33<<1)+0x0), 0x08),	//RINPUT1 not connected to PGA (RMN1), Connect right input PGA to right input boost (RMIC2B), Right PGA Boost = 0dB 
	(((21<<1)+0x1), 0xC3),	//Left ADC Vol = 0dB, Volume Update
	(((22<<1)+0x1), 0xC3),	//Right ADC Vol = 0dB, Volume Update 
   
	/* L_RINPUT1_to_ADC_SlaveMode_24bitI2S */
	/* L/RINPUT1 to ADC, 48KHz, 24 bit I2S Slave Mode */
	(((WM8960_RESET<<1)+0x0), 0x00),	//Reset WM8960
	(((WM8960_POWER1<<1)+0x0), 0xFC),	//VMID=50K, Enable VREF, AINL, AINR, ADCL and ADCR  
	(((WM8960_POWER3<<1)+0x0), 0x30),	//Enable left and right channel input PGA 
	(((32<<1)+0x1), 0x08),	//LINPUT1 to PGA (LMN1), Connect left input PGA to left input boost (LMIC2B), Left PGA Boost = 0dB 
	(((33<<1)+0x1), 0x08),	//RINPUT1 to PGA (RMN1), Connect right input PGA to right input boost (RMIC2B), Right PGA Boost = 0dB 
	(((00<<1)+0x1), 0x17),	//Unmute left input PGA (LINMUTE), Left Input PGA Vol = 0dB, Volume Update
	(((01<<1)+0x1), 0x17),	//Unmute right input PGA (RINMUTE), Right Input PGA Vol = 0dB, Volume Update 
	(((21<<1)+0x1), 0xC3),	//Left ADC Vol = 0dB, Volume Update
	(((22<<1)+0x1), 0xC3),	//Right ADC Vol = 0dB, Volume Update 
	
	
	/* L_RINPUT3_to_ADC_SlaveMode_24bitI2S */
	/* L/RINPUT3 to ADC, Slave Mode 24 bit I2S 48KHz */
	(((WM8960_RESET<<1)+0x0), 0x00),	//Reset WM8960  
	(((WM8960_POWER1<<1)+0x0), 0xFC),	//VMID=50K, Enable VREF, AINL, AINR, ADCL and ADCR  
	(((WM8960_POWER3<<1)+0x0), 0x30),	//Enable left and right channel input PGA  
	(((32<<1)+0x0), 0x08),	//LINPUT1 not connected to PGA (LMN1), Connect left input PGA to left input boost (LMIC2B), Left PGA Boost = 0dB 
	(((33<<1)+0x0), 0x08),	//RINPUT1 not connected to PGA (RMN1), Connect right input PGA to right input boost (RMIC2B), Right PGA Boost = 0dB  
	(((43<<1)+0x0), 0x50),	//LIN3 Boost = 0dB  
	(((44<<1)+0x0), 0x50),	//RIN3 Boost = 0dB 
	(((21<<1)+0x1), 0xC3),	//Left ADC Vol = 0dB, Volume Update 
	(((22<<1)+0x1), 0xC3),	//Right ADC Vol = 0dB, Volume Update
   
   
   
   /* WM8960_HP_DAC_Power_Down_Sequence_GBR */
   /* Power down sequence for headphones. */
   {((05<<1)+0x0), 0x08},		//DAC Digital Soft Mute = Mute
   {((28<<1)+0x0), 0x94},		//Enable POBCTRL and BUFDCOPEN and SOFT_ST
   {((WM8960_POWER1<<1)+0x0), 0x00},		//Disable VMID and VREF, (allow output to discharge with S-Curve)
   {0xff, 0x19},									   	//Delay 400mS to discharge HP outputs.
   {((WM8960_POWER2<<1)+0x0), 0x00},		//Disable DACL, DACR, LOUT and ROUT1
   {((WM8960_RESET<<1)+0x0), 0x00}		//Reset Device (default registers)
   
   
   
   /* WM8960_HP_DAC_Power_Up_Sequence_GBR_400R */
   /* DAC to HP Full Power Up Sequence, from COLD start */
   {((WM8960_APOP2<<1)+0x0), 0x40},		//Enable DISOP
   {0xff, 0x19},								  		//Delay (400mS) to remove any residual charge on HP output.    
   {((WM8960_APOP1<<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
   {((WM8960_POWER2<<1)+0x0), 0x60},		//Enable LOUT1 and ROUT1
   {0xff, 0x64},										//Delay (50mSeconds) to allow HP amps to settle
   {((WM8960_APOP1<<1)+0x0), 0x94},		//Disable DLOUT1 DROUT1 and HPSTBY. BUFDCOPEN, POBCTRL, SOFT_ST remain enabled  
   {((WM8960_POWER1<<1)+0x0), 0x80},		//Enable VMID SEL = 2x50K Ohm Dividere
   {0xff, 0x64},										//Delay (100mSeconds) to allow VMID to initially charge
   {((WM8960_POWER1<<1)+0x0), 0xC0},		//Enable VREF. VMID SEL = 2x50K Ohm Divider remain.
   {((WM8960_APOP1<<1)+0x0), 0x10},		//Disable POBCTRL and SOFT_ST. BUFDCOPEN remain enabled  (Delay from R25 = 080 to Disable POBCTRL and SOFT_ST >100mS)
   {((WM8960_POWER2<<1)+0x1), 0xE0},		//Enable DACL, DACR. LOUT1 and ROUT1 remain enabled 
   {((WM8960_POWER3<<1)+0x0), 0x0C},		//Enable left and right output mixers
   {((WM8960_LOUTMIX1<<1)+0x1), 0x50},		//Enable Left DAC to left mixer
   {((WM8960_ROUTMIX2<<1)+0x1), 0x50},		//Enable Right DAC to right mixer
   {((WM8960_LOUT1<<1)+0x0), 0x65},		//LOUT1VOL (HP) = -20dB
   {((WM8960_ROUT1<<1)+0x1), 0x65},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
   {((WM8960_DACCTL1<<1)+0x0), 0x00}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)

//04.12-1
/* WM8960_HP_DAC_Power_Up_Sequence_GBR_400R */
   	/* DAC to HP Full Power Up Sequence, from COLD start */
	{((29<<1)+0x0), 0x40},		//Enable DISOP
	{0xff, 0x19},				//Delay (400mS) to remove any residual charge on HP output.    
	{((28<<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
	{((WM8960_POWER2<<1)+0x1), 0xF9},		//Enable LOUT1 and ROUT1
	{((51<<1)+0x1), 0x1B},	    //DCGAIN = 1.52x (+3.6dB) and ACGAIN = 1.52x (+3.6dB)  

	{((52<<1)+0),0x37}, // Fractional mode 
	{((53<<1)+0),0x86}, // PLLK 1
	{((54<<1)+0),0xc2}, // PLLK 2
	{((55<<1)+0),0x26}, // PLLK 3

	{((8<<1)+0),0x74}, // DCLKDIV, BCLKDIV
	{((4<<1)+0),0x00}, // DACDIV, CLKSEL
	{((7<<1)+0),0x4a}, // 

	{0xff, 0x64},				//Delay (50mSeconds) to allow HP amps to settle
	{((28<<1)+0x0), 0x94},		//Disable DLOUT1 DROUT1 and HPSTBY. BUFDCOPEN, POBCTRL, SOFT_ST remain enabled  

	{((WM8960_POWER1<<1)+0x0), 0x80},		//Enable VMID SEL = 2x50K Ohm Dividere
	{0xff, 0x64},				//Delay (100mSeconds) to allow VMID to initially charge
	{((WM8960_POWER1<<1)+0x0), 0xC0},		//Enable VREF. VMID SEL = 2x50K Ohm Divider remain.


	{((28<<1)+0x1), 0xff},		//Disable POBCTRL and SOFT_ST. BUFDCOPEN remain enabled  (Delay from R25 = 080 to Disable POBCTRL and SOFT_ST >100mS)


	{((WM8960_POWER2<<1)+0x1), 0xFB},		//Enable DACL, DACR. LOUT1 and ROUT1 remain enabled 
	
	
	{((WM8960_POWER3<<1)+0x0), 0x0C},		//Enable left and right output mixers
	{((34<<1)+0x1), 0xf0},		//Enable Left DAC to left mixer (LINPUT3 to Output Mixer)
	{((37<<1)+0x1), 0xf0},		//Enable Right DAC to right mixer
	
	{((02<<1)+0x0), 0xff},		//LOUT1VOL (HP) = -20dB
	{((03<<1)+0x1), 0xff},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
	
	{((05<<1)+0x0), 0x00}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)
	

//04-13

	/* WM8960_HP_DAC_Power_Up_Sequence_GBR_400R */
   	/* DAC to HP Full Power Up Sequence, from COLD start */
	{((29<<1)+0x0), 0x40},		//Enable DISOP
	{0xff, 0x19},				//Delay (400mS) to remove any residual charge on HP output.    
	{((28<<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
	{((WM8960_POWER2<<1)+0x1), 0xF9},		//Enable LOUT1 and ROUT1
	{((51<<1)+0x1), 0x1B},	    //DCGAIN = 1.52x (+3.6dB) and ACGAIN = 1.52x (+3.6dB)  

	{0xff, 0x19},				//Delay (400mS) to remove any residual charge on HP output.    
	{((52<<1)+0),(0x08)}, // PLLK 1
	{((4<<1)+0),0x0c}, // DACDIV, CLKSEL
	{((8<<1)+0),0xc4}, // DCLKDIV, BCLKDIV

	// PLL(K)
	{((53<<1)+0),0x31}, // PLLK 1
	{((54<<1)+0),0x26}, // PLLK 2
	{((55<<1)+0),0xe8}, // PLLK 3

	{((7<<1)+0),0x4a}, // 

	{0xff, 0x64},				//Delay (50mSeconds) to allow HP amps to settle
	{((28<<1)+0x0), 0x94},		//Disable DLOUT1 DROUT1 and HPSTBY. BUFDCOPEN, POBCTRL, SOFT_ST remain enabled  

	{((WM8960_POWER1<<1)+0x0), 0x80},		//Enable VMID SEL = 2x50K Ohm Dividere
	{0xff, 0x64},				//Delay (100mSeconds) to allow VMID to initially charge
	{((WM8960_POWER1<<1)+0x0), 0xC0},		//Enable VREF. VMID SEL = 2x50K Ohm Divider remain.


	{((28<<1)+0x1), 0xff},		//Disable POBCTRL and SOFT_ST. BUFDCOPEN remain enabled  (Delay from R25 = 080 to Disable POBCTRL and SOFT_ST >100mS)


	{((WM8960_POWER2<<1)+0x1), 0xFB},		//Enable DACL, DACR. LOUT1 and ROUT1 remain enabled 
	{((10<<1)+0),0xff}, // LOUT1 Vol = 0dB, volume update enabled
	{((11<<1)+1),0xff}, // ROUT1 Vol = 0dB, volume update enabled
	
	{((WM8960_POWER3<<1)+0x0), 0x0C},		//Enable left and right output mixers
	{((34<<1)+0x1), 0xf0},		//Enable Left DAC to left mixer (LINPUT3 to Output Mixer)
	{((37<<1)+0x1), 0xf0},		//Enable Right DAC to right mixer
	
	{((02<<1)+0x0), 0xff},		//LOUT1VOL (HP) = -20dB
	{((03<<1)+0x1), 0xff},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
	
	{((05<<1)+0x0), 0x04}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)
	
//4-16
	{((WM8960_APOP2  <<1)+0x0), 0x40},		//Enable DISOP
	{0xff, 0x19},							//Delay (400mS) to remove any residual charge on HP output.    
	{((WM8960_APOP1  <<1)+0x0), 0x94},		//Enable POBCTRL, SOFT_ST and BUFDCOPEN
	{((WM8960_POWER2 <<1)+0x1), 0x60},		//Enable LOUT1 and ROUT1
	{((WM8960_CLASSD3<<1)+0x1), 0x1B},	    //DCGAIN = 1.52x (+3.6dB) and ACGAIN = 1.52x (+3.6dB)  

//	{((WM8960_CLOCK1 <<1)+0x0), 0x00}, 		// DACDIV, CLKSEL
//	{((WM8960_IFACE1 <<1)+0x0), 0x0},

	{0xff, 0x64},				//Delay (50mSeconds) to allow HP amps to settle
	{((WM8960_APOP1   <<1)+0x0), 0x94},		//Disable DLOUT1 DROUT1 and HPSTBY. BUFDCOPEN, POBCTRL, SOFT_ST remain enabled  
	{((WM8960_POWER1  <<1)+0x0), 0x80},		//Enable VMID SEL = 2x50K Ohm Dividere
	{0xff, 0x19},		
#if 1	
	//PLL 27 MHz	 SysCLK 12.288MHz	F2 98.304 MHz
	
	{((WM8960_PLLN    <<1)+0),(0x17)}, // PLLK 1
	{((WM8960_CLOCK1  <<1)+0),0x0c}, // DACDIV, CLKSEL
	{((WM8960_CLOCK2  <<1)+0),0xc4}, // DCLKDIV, BCLKDIV
	// PLL(K)
	{((WM8960_PLLK1   <<1)+0),0x48}, // PLLK 1
	{((WM8960_PLLK2   <<1)+0),0x22}, // PLLK 2
	{((WM8960_PLLK3   <<1)+0),0x96}, // PLLK 3
#endif	
	
	{0xff, 0x19},							//Delay (100mSeconds) to allow VMID to initially charge
	{((WM8960_POWER1  <<1)+0x0), 0xC0},		//Enable VREF. VMID SEL = 2x50K Ohm Divider remain.
	{((WM8960_APOP1   <<1)+0x0), 0x10},		//Disable POBCTRL and SOFT_ST. BUFDCOPEN remain enabled  (Delay from R25 = 080 to Disable POBCTRL and SOFT_ST >100mS)
	{((WM8960_POWER2  <<1)+0x1), 0xE0},		//Enable DACL, DACR. LOUT1 and ROUT1 remain enabled 
	{((WM8960_POWER3  <<1)+0x0), 0x0C},		//Enable left and right output mixers

	{((WM8960_LOUTMIX1<<1)+0x0), 0x50},		//Enable Left DAC to left mixer (LINPUT3 to Output Mixer)
	{((WM8960_ROUTMIX2<<1)+0x1), 0x50},		//Enable Right DAC to right mixer
	{((WM8960_LOUT1   <<1)+0x0), 0x65},		//LOUT1VOL (HP) = -20dB
	{((WM8960_ROUT1   <<1)+0x1), 0x65},		//ROUT1VOL (HP) = -20dB, Enable OUT1VU, load volume settings to both left and right channels
	{((WM8960_DACCTL1 <<1)+0x0), 0x00}		//DAC Digital Soft Mute = Unmute (Delay from R25 = 080 to unmute >250mS)
	
	
////////////////////////////////////////////////////////////////////////////////
	
	//PLL 12MHz	 SysCLK 12.288MHz	F2 98.304 MHz

	// PLL(N)
	{((WM8960_PLLN<<1)+0),(0x08)}, // PLLK 1
	{((WM8960_CLOCK1<<1)+0),0x0c}, // DACDIV, CLKSEL
	{((WM8960_CLOCK2<<1)+0),0xc4}, // DCLKDIV, BCLKDIV
	// PLL(K)
	{((WM8960_PLLK1<<1)+0),0x31}, // PLLK 1
	{((WM8960_PLLK2<<1)+0),0x26}, // PLLK 2
	{((WM8960_PLLK3<<1)+0),0xe8}, // PLLK 3
	
////////////////////////////////////////////////////////////////////////////////
	
	//PLL 12.288MHz	 SysCLK 12.288MHz	F2 98.304 MHz
	//CLKSEL = 0
	//MS = 0
	//WL = 10
	//SYSCLKDIV =0
	//ADCDIV=000
	//DACDIV=000
	{((WM8960_CLOCK1<<1)+0),0x00}, // DACDIV, CLKSEL
	{((WM8960_IFACE1<<1)+0),0x0)},
	
////////////////////////////////////////////////////////////////////////////////
	
	//PLL 27 8MHz	 SysCLK 12.288MHz	F2 98.304 MHz
	
	{((WM8960_PLLN<<1)+0),(0x17)}, // PLLK 1

	{((WM8960_CLOCK1<<1)+0),0x0c}, // DACDIV, CLKSEL
	{((WM8960_CLOCK2<<1)+0),0xc4}, // DCLKDIV, BCLKDIV
	// PLL(K)
	{((WM8960_PLLK1<<1)+0),0x48}, // PLLK 1
	{((WM8960_PLLK2<<1)+0),0x22}, // PLLK 2
	{((WM8960_PLLK3<<1)+0),0x96}, // PLLK 3
		

#endif


