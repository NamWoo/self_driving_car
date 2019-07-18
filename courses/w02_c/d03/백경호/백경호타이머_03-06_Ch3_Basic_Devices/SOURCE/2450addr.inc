/*====================================================================
 * File Name : 2450addr.inc
 *====================================================================
 */

/*=================
 * Memory control
 *=================
 */
	.equ	BANKCFG,  	0x48000000      /*DRAM configuration*/
	.equ	BANKCON1,	0x48000004      /*DRAM control*/
	.equ	BANKCON2,	0x48000008      /*DRAM timing control*/
	.equ	BANKCON3,	0x4800000c      /*DRAM (E)MRS*/
	.equ	REFRESH,	0x48000010      /*DRAM refresh control*/
	.equ	TIMEOUT,	0x48000014      /*Write Buffer Time out control*/

/*	=================
 *   WATCH DOG TIMER
 *  ================= 
 */
	.equ 	WTCON, 		0x53000000      /*Watch-dog timer mode*/
	.equ 	WTDAT, 		0x53000004      /*Watch-dog timer data*/
	.equ 	WTCNT, 		0x53000008      /*Watch-dog timer count*/
	
/*	;==========================
//	; CLOCK & POWER MANAGEMENT
//	;========================== */
	.equ	LOCKCON0,	0x4c000000	/* MPLL lock time counter*/
	.equ	LOCKCON1,	0x4c000004	/* EPLL lock time counter*/
	.equ	OSCSET,		0x4c000008
	.equ	MPLLCON,	0x4c000010	/*MPLL Control*/
	.equ	EPLLCON,	0x4c000018	/*EPLL Control*/
	.equ	CLKSRCCON,	0x4c000020
	.equ	CLKDIV0CON,	0x4c000024	/*Clock divider control*/
	.equ	CLKDIV1CON,	0x4c000028
	.equ	HCLKCON,	0x4c000030
	.equ	PCLKCON,	0x4c000034
	.equ	SCLKCON,	0x4c000038

	
/*	;=================
//	; INTERRUPT
//	;================= */
	.equ	SRCPND1,   	0x4a000000    /*Interrupt request status*/
	.equ	INTMOD1,   	0x4a000004    /*Interrupt mode control*/
	.equ	INTMSK1,   	0x4a000008    /*Interrupt mask control*/  
	.equ	INTPND1,   	0x4a000010	  /*Interrupt request status*/
	.equ	INTOFFSET1,	0x4a000014    /*Interruot request source offset*/
	.equ	SUSSRCPND,	0x4a000018    /*Sub source pending*/
	.equ	INTSUBMSK,	0x4a00001c    /*Interrupt sub mask*/
	.equ	PRIORITY_MODE1, 	0x4a000030    /*IRQ priority mode    */
	.equ	PRIORITY_UPDATE1, 	0x4a000034    /*IRQ priority update    */
	.equ	SRCPND2,   	0x4a000040    /*Interrupt request status*/
	.equ	INTMOD2,   	0x4a000044    /*Interrupt mode control*/
	.equ	INTMSK2,   	0x4a000048    /*Interrupt mask control*/
	.equ	INTPND2,   	0x4a000050	  /*Interrupt request status*/
	.equ	INTOFFSET2,	0x4a000054    /*Interruot request source offset*/
	.equ	PRIORITY_MODE2, 	0x4a000070    /*IRQ priority mode    */
	.equ	PRIORITY_UPDATE2, 	0x4a000074    /*IRQ priority update    */


/*=================
  I/O PORT for LED
  =================*/
	.equ 	GPBCON,  	0x56000010     /*Port B control*/
	.equ 	GPBDAT,  	0x56000014     /*Port B data*/
	.equ 	GPECON,  	0x56000040     /*Port E control*/
	.equ 	GPEDAT,  	0x56000044     /*Port E data*/
	.equ 	GPEUDP,   	0x56000048     /*Pull-up control E*/
	.equ 	GPFCON,  	0x56000050     /*Port F control*/
	.equ 	GPFDAT,  	0x56000054     /*Port F data*/
	.equ 	GPFUDP,   	0x56000058     /*Pull-up control F*/
	.equ 	GPGCON,  	0x56000060     /*Port G control*/
	.equ 	GPGDAT,  	0x56000064     /*Port G data*/
	.equ 	GPGUDP,   	0x56000068     /*Pull-up control G*/
	.equ 	GPHCON,  	0x56000070     /*Port H control*/
	.equ 	GPHDAT,  	0x56000074     /*Port H data*/
	.equ 	GPHUDP,   	0x56000078     /*Pull-up control H*/

	/* Miscellaneous register*/
	.equ	MISCCR,  	0x56000080     /*Miscellaneous control*/
	.equ	DCKCON,  	0x56000084     /*DCLK0/1 control*/
	.equ	EXTINT0, 	0x56000088     /*External interrupt control register 0*/
	.equ	EXTINT1, 	0x5600008c     /*External interrupt control register 1*/
	.equ	EXTINT2, 	0x56000090     /*External interrupt control register 2*/
	.equ	EINTFLT0,	0x56000094     /*Reserved*/
	.equ	EINTFLT1,	0x56000098     /*Reserved*/
	.equ	EINTFLT2,	0x5600009c     /*External interrupt filter control register 2*/
	.equ	EINTFLT3,	0x560000a0     /*External interrupt filter control register 3*/
	.equ	EINTMASK,	0x560000a4     /*External interrupt mask*/
	.equ	EINTPEND,	0x560000a8     /*External interrupt pending*/
	.equ	GSTATUS0,	0x560000ac     /*External pin status*/
	.equ	GSTATUS1,	0x560000b0     /*Chip ID(0x32440000)*/
	.equ	GSTATUS2,	0x560000b4     /*Reset type*/
	.equ	GSTATUS3,	0x560000b8     /*Saved data0(32-bit) before entering POWER_OFF mode*/
	.equ	GSTATUS4,	0x560000bc     /*Saved data1(32-bit) before entering POWER_OFF mode*/

