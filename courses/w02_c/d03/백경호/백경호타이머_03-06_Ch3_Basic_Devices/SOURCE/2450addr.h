//=============================================================================
// File Name : 2450addr.h
// Function  : S3C2450 Define Address Register
//=============================================================================

#ifndef __2450ADDR_H__
#define __2450ADDR_H__

#ifdef __cplusplus
extern "C" {
#endif


// Memory control 
#define rBWSCON    (*(volatile unsigned *)0x48000000)	//Bus width & wait status
#define rBANKCON0  (*(volatile unsigned *)0x48000004)	//Boot ROM control
#define rBANKCON1  (*(volatile unsigned *)0x48000008)	//BANK1 control
#define rBANKCON2  (*(volatile unsigned *)0x4800000c)	//BANK2 cControl
#define rBANKCON3  (*(volatile unsigned *)0x48000010)	//BANK3 control
#define rBANKCON4  (*(volatile unsigned *)0x48000014)	//BANK4 control
#define rBANKCON5  (*(volatile unsigned *)0x48000018)	//BANK5 control
#define rBANKCON6  (*(volatile unsigned *)0x4800001c)	//BANK6 control
#define rBANKCON7  (*(volatile unsigned *)0x48000020)	//BANK7 control
#define rREFRESH   (*(volatile unsigned *)0x48000024)	//DRAM/SDRAM refresh
#define rBANKSIZE  (*(volatile unsigned *)0x48000028)	//Flexible Bank Size
#define rMRSRB6    (*(volatile unsigned *)0x4800002c)	//Mode register set for SDRAM
#define rMRSRB7    (*(volatile unsigned *)0x48000030)	//Mode register set for SDRAM


// USB Host


// INTERRUPT
#define	rSRCPND1	(*(volatile unsigned *)	0x4a000000)    /*Interrupt request status*/		
#define	rINTMOD1	(*(volatile unsigned *)	0x4a000004)    /*Interrupt mode control*/		
#define	rINTMSK1 	(*(volatile unsigned *)	0x4a000008 )   /*Interrupt mask control*/  		
#define	rINTPND1	(*(volatile unsigned *)	0x4a000010)		  /*Interrupt request status*/
#define	rINTOFFSET1	(*(volatile unsigned *)	0x4a000014 )   /*Interruot request source offset*/		
#define	rSUBSRCPND	(*(volatile unsigned *)	0x4a000018)    /*Sub source pending*/		
#define	rINTSUBMSK	(*(volatile unsigned *)	0x4a00001c)    /*Interrupt sub mask*/		
#define	rPRIORITY_MODE 	(*(volatile unsigned *)	0x4a000030 )   /*IRQ priority mode    */		
#define	rPRIORITY_UPDATE1	(*(volatile unsigned *)	0x4a000034)    /*IRQ priority update    */		
#define	rSRCPND2	(*(volatile unsigned *)	0x4a000040 )   /*Interrupt request status*/		
#define	rINTMOD2	(*(volatile unsigned *)	0x4a000044)    /*Interrupt mode control*/		
#define	rINTMSK2	(*(volatile unsigned *)	0x4a000048)    /*Interrupt mask control*/		
#define	rINTPND2	(*(volatile unsigned *)	0x4a000050)		  /*Interrupt request status*/
#define	rINTOFFSET2	(*(volatile unsigned *)	0x4a000054 )   /*Interruot request source offset*/		
#define	rPRIORITY_MODE2	(*(volatile unsigned *)	0x4a000070 )   /*IRQ priority mode    */		
#define	rPRIORITY_UPDATE2	(*(volatile unsigned *)	0x4a000074)


// DMA
#define rDISRC0     (*(volatile unsigned *)0x4b000000)	//DMA 0 Initial source
#define rDISRCC0    (*(volatile unsigned *)0x4b000004)	//DMA 0 Initial source control
#define rDIDST0     (*(volatile unsigned *)0x4b000008)	//DMA 0 Initial Destination
#define rDIDSTC0    (*(volatile unsigned *)0x4b00000c)	//DMA 0 Initial Destination control
#define rDCON0      (*(volatile unsigned *)0x4b000010)	//DMA 0 Control
#define rDSTAT0     (*(volatile unsigned *)0x4b000014)	//DMA 0 Status
#define rDCSRC0     (*(volatile unsigned *)0x4b000018)	//DMA 0 Current source
#define rDCDST0     (*(volatile unsigned *)0x4b00001c)	//DMA 0 Current destination
#define rDMASKTRIG0 (*(volatile unsigned *)0x4b000020)	//DMA 0 Mask trigger
#define rDMAREQSEL0	(*(volatile unsigned *)0x4b000024)	//DMA 0 Request Selection

#define rDISRC1     (*(volatile unsigned *)0x4b000100)	//DMA 1 Initial source
#define rDISRCC1    (*(volatile unsigned *)0x4b000104)	//DMA 1 Initial source control
#define rDIDST1     (*(volatile unsigned *)0x4b000108)	//DMA 1 Initial Destination
#define rDIDSTC1    (*(volatile unsigned *)0x4b00010c)	//DMA 1 Initial Destination control
#define rDCON1      (*(volatile unsigned *)0x4b000110)	//DMA 1 Control
#define rDSTAT1     (*(volatile unsigned *)0x4b000114)	//DMA 1 Status
#define rDCSRC1     (*(volatile unsigned *)0x4b000118)	//DMA 1 Current source
#define rDCDST1     (*(volatile unsigned *)0x4b00011c)	//DMA 1 Current destination
#define rDMASKTRIG1 (*(volatile unsigned *)0x4b000120)	//DMA 1 Mask trigger
#define rDMAREQSEL1	(*(volatile unsigned *)0x4b000124)	//DMA 1 Request Selection

#define rDISRC2     (*(volatile unsigned *)0x4b000200)	//DMA 2 Initial source
#define rDISRCC2    (*(volatile unsigned *)0x4b000204)	//DMA 2 Initial source control
#define rDIDST2     (*(volatile unsigned *)0x4b000208)	//DMA 2 Initial Destination
#define rDIDSTC2    (*(volatile unsigned *)0x4b00020c)	//DMA 2 Initial Destination control
#define rDCON2      (*(volatile unsigned *)0x4b000210)	//DMA 2 Control
#define rDSTAT2     (*(volatile unsigned *)0x4b000214)	//DMA 2 Status
#define rDCSRC2     (*(volatile unsigned *)0x4b000218)	//DMA 2 Current source
#define rDCDST2     (*(volatile unsigned *)0x4b00021c)	//DMA 2 Current destination
#define rDMASKTRIG2 (*(volatile unsigned *)0x4b000220)	//DMA 2 Mask trigger
#define rDMAREQSEL2	(*(volatile unsigned *)0x4b000224)	//DMA 2 Request Selection

#define rDISRC3     (*(volatile unsigned *)0x4b000300)	//DMA 3 Initial source
#define rDISRCC3    (*(volatile unsigned *)0x4b000304)	//DMA 3 Initial source control
#define rDIDST3     (*(volatile unsigned *)0x4b000308)	//DMA 3 Initial Destination
#define rDIDSTC3    (*(volatile unsigned *)0x4b00030c)	//DMA 3 Initial Destination control
#define rDCON3      (*(volatile unsigned *)0x4b000310)	//DMA 3 Control
#define rDSTAT3     (*(volatile unsigned *)0x4b000314)	//DMA 3 Status
#define rDCSRC3     (*(volatile unsigned *)0x4b000318)	//DMA 3 Current source
#define rDCDST3     (*(volatile unsigned *)0x4b00031c)	//DMA 3 Current destination
#define rDMASKTRIG3 (*(volatile unsigned *)0x4b000320)	//DMA 3 Mask trigger
#define rDMAREQSEL3	(*(volatile unsigned *)0x4b000324)	//DMA 3 Request Selection

#define rDISRC4     (*(volatile unsigned *)0x4b000400)	//DMA 4 Initial source
#define rDISRCC4    (*(volatile unsigned *)0x4b000404)	//DMA 4 Initial source control
#define rDIDST4     (*(volatile unsigned *)0x4b000408)	//DMA 4 Initial Destination
#define rDIDSTC4    (*(volatile unsigned *)0x4b00040c)	//DMA 4 Initial Destination control
#define rDCON4      (*(volatile unsigned *)0x4b000410)	//DMA 4 Control
#define rDSTAT4     (*(volatile unsigned *)0x4b000414)	//DMA 4 Status
#define rDCSRC4     (*(volatile unsigned *)0x4b000418)	//DMA 4 Current source
#define rDCDST4     (*(volatile unsigned *)0x4b00041c)	//DMA 4 Current destination
#define rDMASKTRIG4 (*(volatile unsigned *)0x4b000420)	//DMA 4 Mask trigger
#define rDMAREQSEL4	(*(volatile unsigned *)0x4b000424)	//DMA 4 Request Selection

#define rDISRC5     (*(volatile unsigned *)0x4b000500)	//DMA 5 Initial source
#define rDISRCC5    (*(volatile unsigned *)0x4b000504)	//DMA 5 Initial source control
#define rDIDST5     (*(volatile unsigned *)0x4b000508)	//DMA 5 Initial Destination
#define rDIDSTC5    (*(volatile unsigned *)0x4b00050c)	//DMA 5 Initial Destination control
#define rDCON5      (*(volatile unsigned *)0x4b000510)	//DMA 5 Control
#define rDSTAT5     (*(volatile unsigned *)0x4b000514)	//DMA 5 Status
#define rDCSRC5     (*(volatile unsigned *)0x4b000518)	//DMA 5 Current source
#define rDCDST5     (*(volatile unsigned *)0x4b00051c)	//DMA 5 Current destination
#define rDMASKTRIG5 (*(volatile unsigned *)0x4b000520)	//DMA 5 Mask trigger
#define rDMAREQSEL5	(*(volatile unsigned *)0x4b000524)	//DMA 5 Request Selection

#define rDISRC6     (*(volatile unsigned *)0x4b000600)	//DMA 6 Initial source
#define rDISRCC6    (*(volatile unsigned *)0x4b000604)	//DMA 6 Initial source control
#define rDIDST6     (*(volatile unsigned *)0x4b000608)	//DMA 6 Initial Destination
#define rDIDSTC6    (*(volatile unsigned *)0x4b00060c)	//DMA 6 Initial Destination control
#define rDCON6      (*(volatile unsigned *)0x4b000610)	//DMA 6 Control
#define rDSTAT6     (*(volatile unsigned *)0x4b000614)	//DMA 6 Status
#define rDCSRC6     (*(volatile unsigned *)0x4b000618)	//DMA 6 Current source
#define rDCDST6     (*(volatile unsigned *)0x4b00061c)	//DMA 6 Current destination
#define rDMASKTRIG6 (*(volatile unsigned *)0x4b000620)	//DMA 6 Mask trigger
#define rDMAREQSEL6	(*(volatile unsigned *)0x4b000624)	//DMA 6 Request Selection

#define rDISRC7     (*(volatile unsigned *)0x4b000700)	//DMA 7 Initial source
#define rDISRCC7    (*(volatile unsigned *)0x4b000704)	//DMA 7 Initial source control
#define rDIDST7     (*(volatile unsigned *)0x4b000708)	//DMA 7 Initial Destination
#define rDIDSTC7    (*(volatile unsigned *)0x4b00070c)	//DMA 7 Initial Destination control
#define rDCON7      (*(volatile unsigned *)0x4b000710)	//DMA 7 Control
#define rDSTAT7     (*(volatile unsigned *)0x4b000714)	//DMA 7 Status
#define rDCSRC7     (*(volatile unsigned *)0x4b000718)	//DMA 7 Current source
#define rDCDST7     (*(volatile unsigned *)0x4b00071c)	//DMA 7 Current destination
#define rDMASKTRIG7 (*(volatile unsigned *)0x4b000720)	//DMA 7 Mask trigger
#define rDMAREQSEL7	(*(volatile unsigned *)0x4b000724)	//DMA 7 Request Selection

// CLOCK & POWER MANAGEMENT
#if 1
#define rLOCKTIME   (*(volatile unsigned *)0x4c000000)	//PLL lock time counter
#define rMPLLCON    (*(volatile unsigned *)0x4c000004)	//MPLL Control
#define rUPLLCON    (*(volatile unsigned *)0x4c000008)	//UPLL Control
#define rCLKCON     (*(volatile unsigned *)0x4c00000c)	//Clock generator control
#define rCLKSLOW    (*(volatile unsigned *)0x4c000010)	//Slow clock control
#define rCLKDIVN    (*(volatile unsigned *)0x4c000014)	//Clock divider control
#define rCAMDIVN    (*(volatile unsigned *)0x4c000018)	//USB, CAM Clock divider control
#else	
#endif

// LCD Controller
#define	rVIDCON0	(*(volatile unsigned *)	0x4C800000	)
#define	rVIDCON1	(*(volatile unsigned *)	0x4C800004 	)
#define	rVIDTCON0	(*(volatile unsigned *)	0x4C800008	)
#define	rVIDTCON1	(*(volatile unsigned *)	0x4C80000C	)
#define	rVIDTCON2	(*(volatile unsigned *)	0x4C800010 	)
#define	rWINCON0	(*(volatile unsigned *)	0x4C800014	)
#define	rWINCON1	(*(volatile unsigned *)	0x4C800018 	)
#define	rVIDOSD0A	(*(volatile unsigned *)	0x4C800028 	)
#define	rVIDOSD0B	(*(volatile unsigned *)	0x4C80002C	)
#define	rVIDOSD1A	(*(volatile unsigned *)	0x4C800034 	)
#define	rVIDOSD1B	(*(volatile unsigned *)	0x4C800038 	)
#define	rVIDOSD1C	(*(volatile unsigned *)	0x4C80003C	)
#define	rVIDW00ADD0B0 	(*(volatile unsigned *)	0x4C800064 	)
#define	rVIDW00ADD0B1 	(*(volatile unsigned *)	0x4C800068	)
#define	rVIDW01ADD0 	(*(volatile unsigned *)	0x4C80006C	)
#define	rVIDW00ADD1B0	(*(volatile unsigned *)	 0x4C80007C	)
#define	rVIDW00ADD1B1 	(*(volatile unsigned *)	0x4C800080	)
#define	rVIDW01ADD1 	(*(volatile unsigned *)	0x4C800084 	)	
#define	rVIDW00ADD2B0	(*(volatile unsigned *)	0x4C800094	)
#define	rVIDW00ADD2B1	(*(volatile unsigned *)	0x4C800098	)
#define	rVIDW01ADD2	(*(volatile unsigned *)	0x4C80009C	)
#define	rVIDINTCON	(*(volatile unsigned *)	0x4C8000AC	)
#define	rW1KEYCON0	(*(volatile unsigned *)	0x4C8000B0	)
#define	rW1KEYCON1	(*(volatile unsigned *)	0x4C8000B4	)
#define	rW2KEYCON0	(*(volatile unsigned *)	0x4C8000B8	)
#define	rW2KEYCON1	(*(volatile unsigned *)	0x4C8000BC	)
#define	rW3KEYCON0	(*(volatile unsigned *)	0x4C8000C0	)
#define	rW3KEYCON1	(*(volatile unsigned *)	0x4C8000C4	)
#define	rW4KEYCON0	(*(volatile unsigned *)	0x4C8000C8	)
#define	rW4KEYCON1	(*(volatile unsigned *)	0x4C8000CC	)
#define	rWIN0MAP	(*(volatile unsigned *)	0x4C8000D0	)
#define	rWIN1MAP	(*(volatile unsigned *)	0x4C8000D4	)
#define	rWPALCON	(*(volatile unsigned *)	0x4C8000E4	)
#define	rSYSIFCON0	(*(volatile unsigned *)	0x4C800130	)
#define	rSYSIFCON1	(*(volatile unsigned *)	0x4C800134	)
#define	rDITHMODE	(*(volatile unsigned *)	0x4C800138	)
#define	rSIFCCON0	(*(volatile unsigned *)	0x4C80013C	)
#define	rSIFCCON1	(*(volatile unsigned *)	0x4C800140	)
#define	rSIFCCON2	(*(volatile unsigned *)	0x4C800144	)
#define	rCPUTRIGCON2	(*(volatile unsigned *)	0x4C800160	)
#define	rWIN0 Palette RAM	(*(volatile unsigned *)	0x4C800400	)
#define	rWIN1 Palette RAM	(*(volatile unsigned *)	0x4C800800	)


//Nand Flash
#define rNFCONF		(*(volatile unsigned *)0x4E000000)		//NAND Flash configuration
#define rNFCONT		(*(volatile unsigned *)0x4E000004)      //NAND Flash control
#define rNFCMD		(*(volatile unsigned *)0x4E000008)      //NAND Flash command
#define rNFADDR		(*(volatile unsigned *)0x4E00000C)      //NAND Flash address
#define rNFDATA		(*(volatile unsigned *)0x4E000010)      //NAND Flash data
#define rNFDATA8	(*(volatile unsigned char *)0x4E000010)     //NAND Flash data
#define NFDATA		(0x4E000010)      //NAND Flash data address
#define rNFMECCD0	(*(volatile unsigned *)0x4E000014)      //NAND Flash ECC for Main Area
#define rNFMECCD1	(*(volatile unsigned *)0x4E000018)
#define rNFSECCD	(*(volatile unsigned *)0x4E00001C)		//NAND Flash ECC for Spare Area
#define rNFSTAT		(*(volatile unsigned *)0x4E000020)		//NAND Flash operation status
#define rNFESTAT0	(*(volatile unsigned *)0x4E000024)
#define rNFESTAT1	(*(volatile unsigned *)0x4E000028)
#define rNFMECC0	(*(volatile unsigned *)0x4E00002C)
#define rNFMECC1	(*(volatile unsigned *)0x4E000030)
#define rNFSECC		(*(volatile unsigned *)0x4E000034)
#define rNFSBLK		(*(volatile unsigned *)0x4E000038)		//NAND Flash Start block address
#define rNFEBLK		(*(volatile unsigned *)0x4E00003C)		//NAND Flash End block address


//Camera Interface.  Edited for 2440A                              
#define rCISRCFMT           (*(volatile unsigned *)0x4F000000)        
#define rCIWDOFST           (*(volatile unsigned *)0x4F000004)        
#define rCIGCTRL            (*(volatile unsigned *)0x4F000008)        
#define rCICOYSA1           (*(volatile unsigned *)0x4F000018)
#define rCICOYSA2           (*(volatile unsigned *)0x4F00001C)
#define rCICOYSA3           (*(volatile unsigned *)0x4F000020)        
#define rCICOYSA4           (*(volatile unsigned *)0x4F000024)        
#define rCICOCBSA1          (*(volatile unsigned *)0x4F000028)        
#define rCICOCBSA2          (*(volatile unsigned *)0x4F00002C)        
#define rCICOCBSA3          (*(volatile unsigned *)0x4F000030)        
#define rCICOCBSA4          (*(volatile unsigned *)0x4F000034)
#define rCICOCRSA1          (*(volatile unsigned *)0x4F000038)
#define rCICOCRSA2          (*(volatile unsigned *)0x4F00003C)
#define rCICOCRSA3          (*(volatile unsigned *)0x4F000040)
#define rCICOCRSA4          (*(volatile unsigned *)0x4F000044)
#define rCICOTRGFMT         (*(volatile unsigned *)0x4F000048)
#define rCICOCTRL           (*(volatile unsigned *)0x4F00004C)        
#define rCICOSCPRERATIO     (*(volatile unsigned *)0x4F000050)        
#define rCICOSCPREDST       (*(volatile unsigned *)0x4F000054)
#define rCICOSCCTRL         (*(volatile unsigned *)0x4F000058)
#define rCICOTAREA          (*(volatile unsigned *)0x4F00005C)
#define rCICOSTATUS         (*(volatile unsigned *)0x4F000064)
#define rCIPRCLRSA1         (*(volatile unsigned *)0x4F00006C)
#define rCIPRCLRSA2         (*(volatile unsigned *)0x4F000070)
#define rCIPRCLRSA3         (*(volatile unsigned *)0x4F000074)        
#define rCIPRCLRSA4         (*(volatile unsigned *)0x4F000078)        
#define rCIPRTRGFMT         (*(volatile unsigned *)0x4F00007C)        
#define rCIPRCTRL           (*(volatile unsigned *)0x4F000080)        
#define rCIPRSCPRERATIO     (*(volatile unsigned *)0x4F000084)        
#define rCIPRSCPREDST       (*(volatile unsigned *)0x4F000088)        
#define rCIPRSCCTRL         (*(volatile unsigned *)0x4F00008C)        
#define rCIPRTAREA          (*(volatile unsigned *)0x4F000090)
#define rCIPRSTATUS         (*(volatile unsigned *)0x4F000098)
#define rCIIMGCPT           (*(volatile unsigned *)0x4F0000A0)


// UART
#define rULCON0     (*(volatile unsigned *)0x50000000)	//UART 0 Line control
#define rUCON0      (*(volatile unsigned *)0x50000004)	//UART 0 Control
#define rUFCON0     (*(volatile unsigned *)0x50000008)	//UART 0 FIFO control
#define rUMCON0     (*(volatile unsigned *)0x5000000c)	//UART 0 Modem control
#define rUTRSTAT0   (*(volatile unsigned *)0x50000010)	//UART 0 Tx/Rx status
#define rUERSTAT0   (*(volatile unsigned *)0x50000014)	//UART 0 Rx error status
#define rUFSTAT0    (*(volatile unsigned *)0x50000018)	//UART 0 FIFO status
#define rUMSTAT0    (*(volatile unsigned *)0x5000001c)	//UART 0 Modem status
#define rUBRDIV0    (*(volatile unsigned *)0x50000028)	//UART 0 Baud rate divisor

#define rULCON1     (*(volatile unsigned *)0x50004000)	//UART 1 Line control
#define rUCON1      (*(volatile unsigned *)0x50004004)	//UART 1 Control
#define rUFCON1     (*(volatile unsigned *)0x50004008)	//UART 1 FIFO control
#define rUMCON1     (*(volatile unsigned *)0x5000400c)	//UART 1 Modem control
#define rUTRSTAT1   (*(volatile unsigned *)0x50004010)	//UART 1 Tx/Rx status
#define rUERSTAT1   (*(volatile unsigned *)0x50004014)	//UART 1 Rx error status
#define rUFSTAT1    (*(volatile unsigned *)0x50004018)	//UART 1 FIFO status
#define rUMSTAT1    (*(volatile unsigned *)0x5000401c)	//UART 1 Modem status
#define rUBRDIV1    (*(volatile unsigned *)0x50004028)	//UART 1 Baud rate divisor
#define rULCON2     (*(volatile unsigned *)0x50008000)	//UART 2 Line control
#define rUCON2      (*(volatile unsigned *)0x50008004)	//UART 2 Control
#define rUFCON2     (*(volatile unsigned *)0x50008008)	//UART 2 FIFO control
#define rUMCON2     (*(volatile unsigned *)0x5000800c)	//UART 2 Modem control
#define rUTRSTAT2   (*(volatile unsigned *)0x50008010)	//UART 2 Tx/Rx status
#define rUERSTAT2   (*(volatile unsigned *)0x50008014)	//UART 2 Rx error status
#define rUFSTAT2    (*(volatile unsigned *)0x50008018)	//UART 2 FIFO status
#define rUMSTAT2    (*(volatile unsigned *)0x5000801c)	//UART 2 Modem status
#define rUBRDIV2    (*(volatile unsigned *)0x50008028)	//UART 2 Baud rate divisor

#ifdef __BIG_ENDIAN
#define rUTXH0      (*(volatile unsigned char *)0x50000023)	//UART 0 Transmission Hold
#define rURXH0      (*(volatile unsigned char *)0x50000027)	//UART 0 Receive buffer
#define rUTXH1      (*(volatile unsigned char *)0x50004023)	//UART 1 Transmission Hold
#define rURXH1      (*(volatile unsigned char *)0x50004027)	//UART 1 Receive buffer
#define rUTXH2      (*(volatile unsigned char *)0x50008023)	//UART 2 Transmission Hold
#define rURXH2      (*(volatile unsigned char *)0x50008027)	//UART 2 Receive buffer

#define WrUTXH0(ch) (*(volatile unsigned char *)0x50000023)=(unsigned char)(ch)
#define RdURXH0()   (*(volatile unsigned char *)0x50000027)
#define WrUTXH1(ch) (*(volatile unsigned char *)0x50004023)=(unsigned char)(ch)
#define RdURXH1()   (*(volatile unsigned char *)0x50004027)
#define WrUTXH2(ch) (*(volatile unsigned char *)0x50008023)=(unsigned char)(ch)
#define RdURXH2()   (*(volatile unsigned char *)0x50008027)

#define UTXH0       (0x50000020+3)  //Byte_access address by DMA
#define URXH0       (0x50000024+3)
#define UTXH1       (0x50004020+3)
#define URXH1       (0x50004024+3)
#define UTXH2       (0x50008020+3)
#define URXH2       (0x50008024+3)

#else //Little Endian
#define rUTXH0 (*(volatile unsigned char *)0x50000020)	//UART 0 Transmission Hold
#define rURXH0 (*(volatile unsigned char *)0x50000024)	//UART 0 Receive buffer
#define rUTXH1 (*(volatile unsigned char *)0x50004020)	//UART 1 Transmission Hold
#define rURXH1 (*(volatile unsigned char *)0x50004024)	//UART 1 Receive buffer
#define rUTXH2 (*(volatile unsigned char *)0x50008020)	//UART 2 Transmission Hold
#define rURXH2 (*(volatile unsigned char *)0x50008024)	//UART 2 Receive buffer

#define WrUTXH0(ch) (*(volatile unsigned char *)0x50000020)=(unsigned char)(ch)
#define RdURXH0()   (*(volatile unsigned char *)0x50000024)
#define WrUTXH1(ch) (*(volatile unsigned char *)0x50004020)=(unsigned char)(ch)
#define RdURXH1()   (*(volatile unsigned char *)0x50004024)
#define WrUTXH2(ch) (*(volatile unsigned char *)0x50008020)=(unsigned char)(ch)
#define RdURXH2()   (*(volatile unsigned char *)0x50008024)

#define UTXH0       (0x50000020)    //Byte_access address by DMA
#define URXH0       (0x50000024)
#define UTXH1       (0x50004020)
#define URXH1       (0x50004024)
#define UTXH2       (0x50008020)
#define URXH2       (0x50008024)
#endif


// PWM TIMER
#define rTCFG0  (*(volatile unsigned *)0x51000000)	//Timer 0 configuration
#define rTCFG1  (*(volatile unsigned *)0x51000004)	//Timer 1 configuration
#define rTCON   (*(volatile unsigned *)0x51000008)	//Timer control
#define rTCNTB0 (*(volatile unsigned *)0x5100000c)	//Timer count buffer 0
#define rTCMPB0 (*(volatile unsigned *)0x51000010)	//Timer compare buffer 0
#define rTCNTO0 (*(volatile unsigned *)0x51000014)	//Timer count observation 0
#define rTCNTB1 (*(volatile unsigned *)0x51000018)	//Timer count buffer 1
#define rTCMPB1 (*(volatile unsigned *)0x5100001c)	//Timer compare buffer 1
#define rTCNTO1 (*(volatile unsigned *)0x51000020)	//Timer count observation 1
#define rTCNTB2 (*(volatile unsigned *)0x51000024)	//Timer count buffer 2
#define rTCMPB2 (*(volatile unsigned *)0x51000028)	//Timer compare buffer 2
#define rTCNTO2 (*(volatile unsigned *)0x5100002c)	//Timer count observation 2
#define rTCNTB3 (*(volatile unsigned *)0x51000030)	//Timer count buffer 3
#define rTCMPB3 (*(volatile unsigned *)0x51000034)	//Timer compare buffer 3
#define rTCNTO3 (*(volatile unsigned *)0x51000038)	//Timer count observation 3
#define rTCNTB4 (*(volatile unsigned *)0x5100003c)	//Timer count buffer 4
#define rTCNTO4 (*(volatile unsigned *)0x51000040)	//Timer count observation 4


// USB DEVICE
#ifdef __BIG_ENDIAN
<ERROR IF BIG_ENDIAN>
#define rFUNC_ADDR_REG     (*(volatile unsigned char *)0x52000143)	//Function address
#define rPWR_REG           (*(volatile unsigned char *)0x52000147)	//Power management
#define rEP_INT_REG        (*(volatile unsigned char *)0x5200014b)	//EP Interrupt pending and clear
#define rUSB_INT_REG       (*(volatile unsigned char *)0x5200015b)	//USB Interrupt pending and clear
#define rEP_INT_EN_REG     (*(volatile unsigned char *)0x5200015f)	//Interrupt enable
#define rUSB_INT_EN_REG    (*(volatile unsigned char *)0x5200016f)
#define rFRAME_NUM1_REG    (*(volatile unsigned char *)0x52000173)	//Frame number lower byte
#define rFRAME_NUM2_REG    (*(volatile unsigned char *)0x52000177)	//Frame number higher byte
#define rINDEX_REG         (*(volatile unsigned char *)0x5200017b)	//Register index
#define rMAXP_REG          (*(volatile unsigned char *)0x52000183)	//Endpoint max packet
#define rEP0_CSR           (*(volatile unsigned char *)0x52000187)	//Endpoint 0 status
#define rIN_CSR1_REG       (*(volatile unsigned char *)0x52000187)	//In endpoint control status
#define rIN_CSR2_REG       (*(volatile unsigned char *)0x5200018b)
#define rOUT_CSR1_REG      (*(volatile unsigned char *)0x52000193)	//Out endpoint control status
#define rOUT_CSR2_REG      (*(volatile unsigned char *)0x52000197)
#define rOUT_FIFO_CNT1_REG (*(volatile unsigned char *)0x5200019b)	//Endpoint out write count
#define rOUT_FIFO_CNT2_REG (*(volatile unsigned char *)0x5200019f)
#define rEP0_FIFO          (*(volatile unsigned char *)0x520001c3)	//Endpoint 0 FIFO
#define rEP1_FIFO          (*(volatile unsigned char *)0x520001c7)	//Endpoint 1 FIFO
#define rEP2_FIFO          (*(volatile unsigned char *)0x520001cb)	//Endpoint 2 FIFO
#define rEP3_FIFO          (*(volatile unsigned char *)0x520001cf)	//Endpoint 3 FIFO
#define rEP4_FIFO          (*(volatile unsigned char *)0x520001d3)	//Endpoint 4 FIFO
#define rEP1_DMA_CON       (*(volatile unsigned char *)0x52000203)	//EP1 DMA interface control
#define rEP1_DMA_UNIT      (*(volatile unsigned char *)0x52000207)	//EP1 DMA Tx unit counter
#define rEP1_DMA_FIFO      (*(volatile unsigned char *)0x5200020b)	//EP1 DMA Tx FIFO counter
#define rEP1_DMA_TTC_L     (*(volatile unsigned char *)0x5200020f)	//EP1 DMA total Tx counter
#define rEP1_DMA_TTC_M     (*(volatile unsigned char *)0x52000213)
#define rEP1_DMA_TTC_H     (*(volatile unsigned char *)0x52000217)
#define rEP2_DMA_CON       (*(volatile unsigned char *)0x5200021b)	//EP2 DMA interface control
#define rEP2_DMA_UNIT      (*(volatile unsigned char *)0x5200021f)	//EP2 DMA Tx unit counter
#define rEP2_DMA_FIFO      (*(volatile unsigned char *)0x52000223)	//EP2 DMA Tx FIFO counter
#define rEP2_DMA_TTC_L     (*(volatile unsigned char *)0x52000227)	//EP2 DMA total Tx counter
#define rEP2_DMA_TTC_M     (*(volatile unsigned char *)0x5200022b)
#define rEP2_DMA_TTC_H     (*(volatile unsigned char *)0x5200022f)
#define rEP3_DMA_CON       (*(volatile unsigned char *)0x52000243)	//EP3 DMA interface control
#define rEP3_DMA_UNIT      (*(volatile unsigned char *)0x52000247)	//EP3 DMA Tx unit counter
#define rEP3_DMA_FIFO      (*(volatile unsigned char *)0x5200024b)	//EP3 DMA Tx FIFO counter
#define rEP3_DMA_TTC_L     (*(volatile unsigned char *)0x5200024f)	//EP3 DMA total Tx counter
#define rEP3_DMA_TTC_M     (*(volatile unsigned char *)0x52000253)
#define rEP3_DMA_TTC_H     (*(volatile unsigned char *)0x52000257) 
#define rEP4_DMA_CON       (*(volatile unsigned char *)0x5200025b)	//EP4 DMA interface control
#define rEP4_DMA_UNIT      (*(volatile unsigned char *)0x5200025f)	//EP4 DMA Tx unit counter
#define rEP4_DMA_FIFO      (*(volatile unsigned char *)0x52000263)	//EP4 DMA Tx FIFO counter
#define rEP4_DMA_TTC_L     (*(volatile unsigned char *)0x52000267)	//EP4 DMA total Tx counter
#define rEP4_DMA_TTC_M     (*(volatile unsigned char *)0x5200026b)
#define rEP4_DMA_TTC_H     (*(volatile unsigned char *)0x5200026f)

#else  // Little Endian
#define rFUNC_ADDR_REG     (*(volatile unsigned char *)0x52000140)	//Function address
#define rPWR_REG           (*(volatile unsigned char *)0x52000144)	//Power management
#define rEP_INT_REG        (*(volatile unsigned char *)0x52000148)	//EP Interrupt pending and clear
#define rUSB_INT_REG       (*(volatile unsigned char *)0x52000158)	//USB Interrupt pending and clear
#define rEP_INT_EN_REG     (*(volatile unsigned char *)0x5200015c)	//Interrupt enable
#define rUSB_INT_EN_REG    (*(volatile unsigned char *)0x5200016c)
#define rFRAME_NUM1_REG    (*(volatile unsigned char *)0x52000170)	//Frame number lower byte
#define rFRAME_NUM2_REG    (*(volatile unsigned char *)0x52000174)	//Frame number higher byte
#define rINDEX_REG         (*(volatile unsigned char *)0x52000178)	//Register index
#define rMAXP_REG          (*(volatile unsigned char *)0x52000180)	//Endpoint max packet
#define rEP0_CSR           (*(volatile unsigned char *)0x52000184)	//Endpoint 0 status
#define rIN_CSR1_REG       (*(volatile unsigned char *)0x52000184)	//In endpoint control status
#define rIN_CSR2_REG       (*(volatile unsigned char *)0x52000188)
#define rOUT_CSR1_REG      (*(volatile unsigned char *)0x52000190)	//Out endpoint control status
#define rOUT_CSR2_REG      (*(volatile unsigned char *)0x52000194)
#define rOUT_FIFO_CNT1_REG (*(volatile unsigned char *)0x52000198)	//Endpoint out write count
#define rOUT_FIFO_CNT2_REG (*(volatile unsigned char *)0x5200019c)
#define rEP0_FIFO          (*(volatile unsigned char *)0x520001c0)	//Endpoint 0 FIFO
#define rEP1_FIFO          (*(volatile unsigned char *)0x520001c4)	//Endpoint 1 FIFO
#define rEP2_FIFO          (*(volatile unsigned char *)0x520001c8)	//Endpoint 2 FIFO
#define rEP3_FIFO          (*(volatile unsigned char *)0x520001cc)	//Endpoint 3 FIFO
#define rEP4_FIFO          (*(volatile unsigned char *)0x520001d0)	//Endpoint 4 FIFO
#define rEP1_DMA_CON       (*(volatile unsigned char *)0x52000200)	//EP1 DMA interface control
#define rEP1_DMA_UNIT      (*(volatile unsigned char *)0x52000204)	//EP1 DMA Tx unit counter
#define rEP1_DMA_FIFO      (*(volatile unsigned char *)0x52000208)	//EP1 DMA Tx FIFO counter
#define rEP1_DMA_TTC_L     (*(volatile unsigned char *)0x5200020c)	//EP1 DMA total Tx counter
#define rEP1_DMA_TTC_M     (*(volatile unsigned char *)0x52000210)
#define rEP1_DMA_TTC_H     (*(volatile unsigned char *)0x52000214)
#define rEP2_DMA_CON       (*(volatile unsigned char *)0x52000218)	//EP2 DMA interface control
#define rEP2_DMA_UNIT      (*(volatile unsigned char *)0x5200021c)	//EP2 DMA Tx unit counter
#define rEP2_DMA_FIFO      (*(volatile unsigned char *)0x52000220)	//EP2 DMA Tx FIFO counter
#define rEP2_DMA_TTC_L     (*(volatile unsigned char *)0x52000224)	//EP2 DMA total Tx counter
#define rEP2_DMA_TTC_M     (*(volatile unsigned char *)0x52000228)
#define rEP2_DMA_TTC_H     (*(volatile unsigned char *)0x5200022c)
#define rEP3_DMA_CON       (*(volatile unsigned char *)0x52000240)	//EP3 DMA interface control
#define rEP3_DMA_UNIT      (*(volatile unsigned char *)0x52000244)	//EP3 DMA Tx unit counter
#define rEP3_DMA_FIFO      (*(volatile unsigned char *)0x52000248)	//EP3 DMA Tx FIFO counter
#define rEP3_DMA_TTC_L     (*(volatile unsigned char *)0x5200024c)	//EP3 DMA total Tx counter
#define rEP3_DMA_TTC_M     (*(volatile unsigned char *)0x52000250)
#define rEP3_DMA_TTC_H     (*(volatile unsigned char *)0x52000254)
#define rEP4_DMA_CON       (*(volatile unsigned char *)0x52000258)	//EP4 DMA interface control
#define rEP4_DMA_UNIT      (*(volatile unsigned char *)0x5200025c)	//EP4 DMA Tx unit counter
#define rEP4_DMA_FIFO      (*(volatile unsigned char *)0x52000260)	//EP4 DMA Tx FIFO counter
#define rEP4_DMA_TTC_L     (*(volatile unsigned char *)0x52000264)	//EP4 DMA total Tx counter
#define rEP4_DMA_TTC_M     (*(volatile unsigned char *)0x52000268)
#define rEP4_DMA_TTC_H     (*(volatile unsigned char *)0x5200026c)
#endif   // __BIG_ENDIAN


// WATCH DOG TIMER
#define rWTCON   (*(volatile unsigned *)0x53000000)	//Watch-dog timer mode
#define rWTDAT   (*(volatile unsigned *)0x53000004)	//Watch-dog timer data
#define rWTCNT   (*(volatile unsigned *)0x53000008)	//Eatch-dog timer count


// IIC
#define rIICCON		(*(volatile unsigned *)0x54000000)	//IIC control
#define rIICSTAT	(*(volatile unsigned *)0x54000004)	//IIC status
#define rIICADD		(*(volatile unsigned *)0x54000008)	//IIC address
#define rIICDS		(*(volatile unsigned *)0x5400000c)	//IIC data shift
#define rIICLC		(*(volatile unsigned *)0x54000010)	//IIC multi-master line control


// IIS
#define rIISCON  (*(volatile unsigned *)0x55000000)	//IIS Control
#define rIISMOD  (*(volatile unsigned *)0x55000004)	//IIS Mode
#define rIISPSR  (*(volatile unsigned *)0x55000008)	//IIS Prescaler
#define rIISFCON (*(volatile unsigned *)0x5500000c)	//IIS FIFO control
#ifdef __BIG_ENDIAN
#define IISFIFO  ((volatile unsigned short *)0x55000012)	//IIS FIFO entry
#else //Little Endian
#define IISFIFO  ((volatile unsigned short *)0x55000010)	//IIS FIFO entry
#endif


//AC97, Added for S3C2440A 
#define rAC_GLBCTRL		*(volatile unsigned *)0x5b000000
#define rAC_GLBSTAT		*(volatile unsigned *)0x5b000004
#define rAC_CODEC_CMD		*(volatile unsigned *)0x5b000008
#define rAC_CODEC_STAT		*(volatile unsigned *)0x5b00000C
#define rAC_PCMADDR		*(volatile unsigned *)0x5b000010
#define rAC_MICADDR		*(volatile unsigned *)0x5b000014
#define rAC_PCMDATA		*(volatile unsigned *)0x5b000018
#define rAC_MICDATA		*(volatile unsigned *)0x5b00001C

#define AC_PCMDATA		0x5b000018
#define AC_MICDATA		0x5b00001C

// I/O PORT 
#define rGPACON    (*(volatile unsigned *)0x56000000)	//Port A control
#define rGPADAT    (*(volatile unsigned *)0x56000004)	//Port A data

#define rGPBCON    (*(volatile unsigned *)0x56000010)	//Port B control
#define rGPBDAT    (*(volatile unsigned *)0x56000014)	//Port B data
#define rGPBUDP     (*(volatile unsigned *)0x56000018)	//Pull-up control B

#define rGPCCON    (*(volatile unsigned *)0x56000020)	//Port C control
#define rGPCDAT    (*(volatile unsigned *)0x56000024)	//Port C data
#define rGPCUDP     (*(volatile unsigned *)0x56000028)	//Pull-up control C

#define rGPDCON    (*(volatile unsigned *)0x56000030)	//Port D control
#define rGPDDAT    (*(volatile unsigned *)0x56000034)	//Port D data
#define rGPDUDP     (*(volatile unsigned *)0x56000038)	//Pull-up control D

#define rGPECON    (*(volatile unsigned *)0x56000040)	//Port E control
#define rGPEDAT    (*(volatile unsigned *)0x56000044)	//Port E data
#define rGPEUDP     (*(volatile unsigned *)0x56000048)	//Pull-up control E

#define rGPFCON    (*(volatile unsigned *)0x56000050)	//Port F control
#define rGPFDAT    (*(volatile unsigned *)0x56000054)	//Port F data
#define rGPFUDP     (*(volatile unsigned *)0x56000058)	//Pull-up control F

#define rGPGCON    (*(volatile unsigned *)0x56000060)	//Port G control
#define rGPGDAT    (*(volatile unsigned *)0x56000064)	//Port G data
#define rGPGUDP     (*(volatile unsigned *)0x56000068)	//Pull-up control G

#define rGPHCON    (*(volatile unsigned *)0x56000070)	//Port H control
#define rGPHDAT    (*(volatile unsigned *)0x56000074)	//Port H data
#define rGPHUDP     (*(volatile unsigned *)0x56000078)	//Pull-up control H

#define rGPJCON    (*(volatile unsigned *)0x560000d0)	//Port J control
#define rGPJDAT    (*(volatile unsigned *)0x560000d4)	//Port J data
#define rGPJUDP     (*(volatile unsigned *)0x560000d8)	//Pull-up control J

#define rGPKCON    (*(volatile unsigned *)0x560000e0)	//Port K control
#define rGPKDAT    (*(volatile unsigned *)0x560000e4)	//Port K data
#define rGPKUDP     (*(volatile unsigned *)0x560000e8)	//Pull-up control K

#define rGPLCON    (*(volatile unsigned *)0x560000f0)	//Port L control
#define rGPLDAT    (*(volatile unsigned *)0x560000f4)	//Port L data
#define rGPLUDP     (*(volatile unsigned *)0x560000f8)	//Pull-up control L
#define rGPLSEL     (*(volatile unsigned *)0x560000fc)	//Port L Selection the function

#define rGPMCON    (*(volatile unsigned *)0x56000100)	//Port M control
#define rGPMDAT    (*(volatile unsigned *)0x56000104)	//Port M data
#define rGPMUDP    (*(volatile unsigned *)0x56000108)	//Pull-up control M

#define rMISCCR    (*(volatile unsigned *)0x56000080)	//Miscellaneous control
#define rDCLKCON   (*(volatile unsigned *)0x56000084)	//DCLK0/1 control
#define rEXTINT0   (*(volatile unsigned *)0x56000088)	//External interrupt control register 0
#define rEXTINT1   (*(volatile unsigned *)0x5600008c)	//External interrupt control register 1
#define rEXTINT2   (*(volatile unsigned *)0x56000090)	//External interrupt control register 2
#define rEINTFLT0  (*(volatile unsigned *)0x56000094)	//Reserved
#define rEINTFLT1  (*(volatile unsigned *)0x56000098)	//Reserved
#define rEINTFLT2  (*(volatile unsigned *)0x5600009c)	//External interrupt filter control register 2
#define rEINTFLT3  (*(volatile unsigned *)0x560000a0)	//External interrupt filter control register 3
#define rEINTMASK  (*(volatile unsigned *)0x560000a4)	//External interrupt mask
#define rEINTPEND  (*(volatile unsigned *)0x560000a8)	//External interrupt pending
#define rGSTATUS0  (*(volatile unsigned *)0x560000ac)	//External pin status
#define rGSTATUS1  (*(volatile unsigned *)0x560000b0)	//Chip ID(0x32440000)
#define rGSTATUS2  (*(volatile unsigned *)0x560000b4)	//Reset type
#define rGSTATUS3  (*(volatile unsigned *)0x560000b8)	//Saved data0(32-bit) before entering POWER_OFF mode 
#define rGSTATUS4  (*(volatile unsigned *)0x560000bc)	//Saved data0(32-bit) before entering POWER_OFF mode 

// Added for 2440
#define rFLTOUT		(*(volatile unsigned *)0x560000c0)	// Filter output(Read only)
#define rDSC0			(*(volatile unsigned *)0x560000c4)	// Strength control register 0
#define rDSC1			(*(volatile unsigned *)0x560000c8)	// Strength control register 1
#define rMSLCON		(*(volatile unsigned *)0x560000cc)	// Memory sleep control register

// RTC
#ifdef __BIG_ENDIAN
#define rRTCCON    (*(volatile unsigned char *)0x57000043)	//RTC control
#define rTICNT     (*(volatile unsigned char *)0x57000047)	//Tick time count
#define rRTCALM    (*(volatile unsigned char *)0x57000053)	//RTC alarm control
#define rALMSEC    (*(volatile unsigned char *)0x57000057)	//Alarm second
#define rALMMIN    (*(volatile unsigned char *)0x5700005b)	//Alarm minute
#define rALMHOUR   (*(volatile unsigned char *)0x5700005f)	//Alarm Hour
#define rALMDATE   (*(volatile unsigned char *)0x57000063)	//Alarm date   //edited by junon
#define rALMMON    (*(volatile unsigned char *)0x57000067)	//Alarm month
#define rALMYEAR   (*(volatile unsigned char *)0x5700006b)	//Alarm year
#define rRTCRST    (*(volatile unsigned char *)0x5700006f)	//RTC round reset
#define rBCDSEC    (*(volatile unsigned char *)0x57000073)	//BCD second
#define rBCDMIN    (*(volatile unsigned char *)0x57000077)	//BCD minute
#define rBCDHOUR   (*(volatile unsigned char *)0x5700007b)	//BCD hour
#define rBCDDATE   (*(volatile unsigned char *)0x5700007f)	//BCD date  //edited by junon
#define rBCDDAY    (*(volatile unsigned char *)0x57000083)	//BCD day   //edited by junon
#define rBCDMON    (*(volatile unsigned char *)0x57000087)	//BCD month
#define rBCDYEAR   (*(volatile unsigned char *)0x5700008b)	//BCD year

#else //Little Endian
#define rRTCCON    (*(volatile unsigned char *)0x57000040)	//RTC control
#define rTICNT     (*(volatile unsigned char *)0x57000044)	//Tick time count
#define rRTCALM    (*(volatile unsigned char *)0x57000050)	//RTC alarm control
#define rALMSEC    (*(volatile unsigned char *)0x57000054)	//Alarm second
#define rALMMIN    (*(volatile unsigned char *)0x57000058)	//Alarm minute
#define rALMHOUR   (*(volatile unsigned char *)0x5700005c)	//Alarm Hour
#define rALMDATE   (*(volatile unsigned char *)0x57000060)	//Alarm date  // edited by junon
#define rALMMON    (*(volatile unsigned char *)0x57000064)	//Alarm month
#define rALMYEAR   (*(volatile unsigned char *)0x57000068)	//Alarm year
#define rRTCRST    (*(volatile unsigned char *)0x5700006c)	//RTC round reset
#define rBCDSEC    (*(volatile unsigned char *)0x57000070)	//BCD second
#define rBCDMIN    (*(volatile unsigned char *)0x57000074)	//BCD minute
#define rBCDHOUR   (*(volatile unsigned char *)0x57000078)	//BCD hour
#define rBCDDATE   (*(volatile unsigned char *)0x5700007c)	//BCD date  //edited by junon
#define rBCDDAY    (*(volatile unsigned char *)0x57000080)	//BCD day   //edited by junon
#define rBCDMON    (*(volatile unsigned char *)0x57000084)	//BCD month
#define rBCDYEAR   (*(volatile unsigned char *)0x57000088)	//BCD year
#endif  //RTC


// ADC
#define rADCCON    (*(volatile unsigned *)0x58000000)	//ADC control
#define rADCTSC    (*(volatile unsigned *)0x58000004)	//ADC touch screen control
#define rADCDLY    (*(volatile unsigned *)0x58000008)	//ADC start or Interval Delay
#define rADCDAT0   (*(volatile unsigned *)0x5800000c)	//ADC conversion data 0
#define rADCDAT1   (*(volatile unsigned *)0x58000010)	//ADC conversion data 1
#define rADCUPDN   (*(volatile unsigned *)0x58000014)	//Stylus Up/Down interrupt status


// SPI       
#define rSPCON0    (*(volatile unsigned *)0x59000000)	//SPI0 control
#define rSPSTA0    (*(volatile unsigned *)0x59000004)	//SPI0 status
#define rSPPIN0    (*(volatile unsigned *)0x59000008)	//SPI0 pin control
#define rSPPRE0    (*(volatile unsigned *)0x5900000c)	//SPI0 baud rate prescaler
#define rSPTDAT0   (*(volatile unsigned *)0x59000010)	//SPI0 Tx data
#define rSPRDAT0   (*(volatile unsigned *)0x59000014)	//SPI0 Rx data

#define rSPCON1    (*(volatile unsigned *)0x59000020)	//SPI1 control
#define rSPSTA1    (*(volatile unsigned *)0x59000024)	//SPI1 status
#define rSPPIN1    (*(volatile unsigned *)0x59000028)	//SPI1 pin control
#define rSPPRE1    (*(volatile unsigned *)0x5900002c)	//SPI1 baud rate prescaler
#define rSPTDAT1   (*(volatile unsigned *)0x59000030)	//SPI1 Tx data
#define rSPRDAT1   (*(volatile unsigned *)0x59000034)	//SPI1 Rx data


// SD Interface
#define rSDICON     (*(volatile unsigned *)0x5a000000)	//SDI control
#define rSDIPRE     (*(volatile unsigned *)0x5a000004)	//SDI baud rate prescaler
#define rSDICARG    (*(volatile unsigned *)0x5a000008)	//SDI command argument
#define rSDICCON    (*(volatile unsigned *)0x5a00000c)	//SDI command control
#define rSDICSTA    (*(volatile unsigned *)0x5a000010)	//SDI command status
#define rSDIRSP0    (*(volatile unsigned *)0x5a000014)	//SDI response 0
#define rSDIRSP1    (*(volatile unsigned *)0x5a000018)	//SDI response 1
#define rSDIRSP2    (*(volatile unsigned *)0x5a00001c)	//SDI response 2
#define rSDIRSP3    (*(volatile unsigned *)0x5a000020)	//SDI response 3
#define rSDIDTIMER  (*(volatile unsigned *)0x5a000024)	//SDI data/busy timer
#define rSDIBSIZE   (*(volatile unsigned *)0x5a000028)	//SDI block size
#define rSDIDCON    (*(volatile unsigned *)0x5a00002c)	//SDI data control
#define rSDIDCNT    (*(volatile unsigned *)0x5a000030)	//SDI data remain counter
#define rSDIDSTA    (*(volatile unsigned *)0x5a000034)	//SDI data status
#define rSDIFSTA    (*(volatile unsigned *)0x5a000038)	//SDI FIFO status
#define rSDIIMSK    (*(volatile unsigned *)0x5a00003c)	//SDI interrupt mask. edited for 2440A

#ifdef __BIG_ENDIAN  /* edited for 2440A */
#define rSDIDAT    (*(volatile unsigned *)0x5a00004c)	//SDI data
#define SDIDAT     0x5a00004c  
#else  // Little Endian
#define rSDIDAT    (*(volatile unsigned *)0x5a000040)	//SDI data 
#define SDIDAT     0x5a000040  
#endif   //SD Interface


// Exception vector
#define pISR_RESET		(*(unsigned *)(_ISR_STARTADDRESS+0x0))
#define pISR_UNDEF		(*(unsigned *)(_ISR_STARTADDRESS+0x4))
#define pISR_SWI		(*(unsigned *)(_ISR_STARTADDRESS+0x8))
#define pISR_PABORT		(*(unsigned *)(_ISR_STARTADDRESS+0xc))
#define pISR_DABORT		(*(unsigned *)(_ISR_STARTADDRESS+0x10))
#define pISR_RESERVED	(*(unsigned *)(_ISR_STARTADDRESS+0x14))
#define pISR_IRQ		(*(unsigned *)(_ISR_STARTADDRESS+0x18))
#define pISR_FIQ		(*(unsigned *)(_ISR_STARTADDRESS+0x1c))
// Interrupt vector
#define pISR_EINT0		(*(unsigned *)(_ISR_STARTADDRESS+0x20))
#define pISR_EINT1		(*(unsigned *)(_ISR_STARTADDRESS+0x24))
#define pISR_EINT2		(*(unsigned *)(_ISR_STARTADDRESS+0x28))
#define pISR_EINT3		(*(unsigned *)(_ISR_STARTADDRESS+0x2c))
#define pISR_EINT4_7	(*(unsigned *)(_ISR_STARTADDRESS+0x30))
#define pISR_EINT8_23	(*(unsigned *)(_ISR_STARTADDRESS+0x34))
#define pISR_CAM		(*(unsigned *)(_ISR_STARTADDRESS+0x38))		// Added for 2440.
#define pISR_BAT_FLT	(*(unsigned *)(_ISR_STARTADDRESS+0x3c))
#define pISR_TICK		(*(unsigned *)(_ISR_STARTADDRESS+0x40))
#define pISR_WDT_AC97		(*(unsigned *)(_ISR_STARTADDRESS+0x44))   //Changed to pISR_WDT_AC97 for 2440A 
#define pISR_TIMER0	 	(*(unsigned *)(_ISR_STARTADDRESS+0x48))
#define pISR_TIMER1	 	(*(unsigned *)(_ISR_STARTADDRESS+0x4c))
#define pISR_TIMER2		(*(unsigned *)(_ISR_STARTADDRESS+0x50))
#define pISR_TIMER3		(*(unsigned *)(_ISR_STARTADDRESS+0x54))
#define pISR_TIMER4		(*(unsigned *)(_ISR_STARTADDRESS+0x58))
#define pISR_UART2		(*(unsigned *)(_ISR_STARTADDRESS+0x5c))
#define pISR_LCD		(*(unsigned *)(_ISR_STARTADDRESS+0x60))
#define pISR_DMA0		(*(unsigned *)(_ISR_STARTADDRESS+0x64))
#define pISR_DMA1		(*(unsigned *)(_ISR_STARTADDRESS+0x68))
#define pISR_DMA2		(*(unsigned *)(_ISR_STARTADDRESS+0x6c))
#define pISR_DMA3		(*(unsigned *)(_ISR_STARTADDRESS+0x70))
#define pISR_SDI		(*(unsigned *)(_ISR_STARTADDRESS+0x74))
#define pISR_SPI0		(*(unsigned *)(_ISR_STARTADDRESS+0x78))
#define pISR_UART1		(*(unsigned *)(_ISR_STARTADDRESS+0x7c))
#define pISR_NFCON		(*(unsigned *)(_ISR_STARTADDRESS+0x80))		// Added for 2440.
#define pISR_USBD		(*(unsigned *)(_ISR_STARTADDRESS+0x84))
#define pISR_USBH		(*(unsigned *)(_ISR_STARTADDRESS+0x88))
#define pISR_IIC		(*(unsigned *)(_ISR_STARTADDRESS+0x8c))
#define pISR_UART0		(*(unsigned *)(_ISR_STARTADDRESS+0x90))
#define pISR_SPI1		(*(unsigned *)(_ISR_STARTADDRESS+0x94))
#define pISR_RTC		(*(unsigned *)(_ISR_STARTADDRESS+0x98))
#define pISR_ADC		(*(unsigned *)(_ISR_STARTADDRESS+0x9c))


// PENDING BIT
#define BIT_EINT0		(0x1)
#define BIT_EINT1		(0x1<<1)
#define BIT_EINT2		(0x1<<2)
#define BIT_EINT3		(0x1<<3)
#define BIT_EINT4_7		(0x1<<4)
#define BIT_EINT8_23	(0x1<<5)
#define BIT_CAM			(0x1<<6)		// Added for 2440.
#define BIT_BAT_FLT		(0x1<<7)
#define BIT_TICK		(0x1<<8)
#define BIT_WDT_AC97	(0x1<<9)	// Changed from BIT_WDT to BIT_WDT_AC97 for 2440A  
#define BIT_TIMER0		(0x1<<10)
#define BIT_TIMER1		(0x1<<11)
#define BIT_TIMER2		(0x1<<12)
#define BIT_TIMER3		(0x1<<13)
#define BIT_TIMER4		(0x1<<14)
#define BIT_UART2		(0x1<<15)
#define BIT_LCD			(0x1<<16)
#define BIT_DMA0		(0x1<<17)
#define BIT_DMA1		(0x1<<18)
#define BIT_DMA2		(0x1<<19)
#define BIT_DMA3		(0x1<<20)
#define BIT_SDI			(0x1<<21)
#define BIT_SPI0		(0x1<<22)
#define BIT_UART1		(0x1<<23)
#define BIT_NFCON		(0x1<<24)		// Added for 2440.
#define BIT_USBD		(0x1<<25)
#define BIT_USBH		(0x1<<26)
#define BIT_IIC			(0x1<<27)
#define BIT_UART0		(0x1<<28)
#define BIT_SPI1		(0x1<<29)
#define BIT_RTC			(0x1<<30)
#define BIT_ADC			(0x1<<31)
#define BIT_ALLMSK		(0xffffffff)

#define BIT_SUB_ALLMSK	(0x7fff)			//Changed from 0x7ff to 0x7fff for 2440A 
#define BIT_SUB_AC97	(0x1<<14)		//Added for 2440A 
#define BIT_SUB_WDT	(0x1<<13)		//Added for 2440A 
#define BIT_SUB_CAM_P	(0x1<<12)		// edited for 2440A.
#define BIT_SUB_CAM_C   (0x1<<11)       // edited for 2440A
#define BIT_SUB_ADC		(0x1<<10)
#define BIT_SUB_TC		(0x1<<9)
#define BIT_SUB_ERR2	(0x1<<8)
#define BIT_SUB_TXD2	(0x1<<7)
#define BIT_SUB_RXD2	(0x1<<6)
#define BIT_SUB_ERR1	(0x1<<5)
#define BIT_SUB_TXD1	(0x1<<4)
#define BIT_SUB_RXD1	(0x1<<3)
#define BIT_SUB_ERR0	(0x1<<2)
#define BIT_SUB_TXD0	(0x1<<1)
#define BIT_SUB_RXD0	(0x1<<0)

#define	ClearPending(bit) {\
			rSRCPND = bit;\
			rINTPND = bit;\
			rINTPND;\
		}		
//Wait until rINTPND is changed for the case that the ISR is very short.


#ifdef __cplusplus
}
#endif
#endif  //__2440ADDR_H__
