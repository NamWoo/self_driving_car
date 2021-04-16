/* Assembly for GNU */
/* ROM, SDRAM 및 GCS 신호 초기화 설정 */
/* Global 변수영역 초기화 */
/* Stack 초기화 */

#include "2450addr.inc"

	.equ _ISR_STARTADDRESS,		0x33ffff00

	/* The location of stacks
	 * stack layout design
	 * 사용자 임의로 목적에 맞게 재설계 되어야 한다
	 * 현재 설계는 ZI-LIMIT을 스택의 제일 위로 본다
	 */
	
	.equ	STACK_BASE_ADDR, 0x33ff8000
	.equ	SVCStack,		(STACK_BASE_ADDR - 0x3800)
	.equ	UserStack,		(STACK_BASE_ADDR - 0x2800)
	.equ	UndefStack,	(STACK_BASE_ADDR - 0x2400)
	.equ	AbortStack,	(STACK_BASE_ADDR - 0x2000)
	.equ	IRQStack,		(STACK_BASE_ADDR - 0x1000)
	.equ	FIQStack,		(STACK_BASE_ADDR - 0x0)

	/* Exception 처리를 위하여 각 모드의 스택을 설정하여야 한다
	 * 우선 각 모드의 스택을 설정하기 위하여는 모드 강제 전환이 필요하다
	 * 이는 SVC모드부터 시작하여 각 모드로 CPSR을 수정하여 전환한다
	 */
	.equ	Mode_USR,		0x10
	.equ	Mode_FIQ,		0x11
	.equ	Mode_IRQ,		0x12
	.equ	Mode_SVC,		0x13
	.equ	Mode_ABT,		0x17
	.equ	Mode_UND,	0x1b
	.equ	Mode_SYS,		0x1f
	.equ	Mode_MASK,	0x1f
	
	.equ	I_Bit,			0x80	/* when I bit is set, IRQ is disabled */
	.equ	F_Bit,			0x40	/* when F bit is set, FIQ is disabled */
	.equ	NOINT,			0xc0
	
	/* CONFIG_CLK_534_133_66	*/
	.equ	Startup_MDIV,			267
	.equ	Startup_PDIV,			3
	.equ	Startup_SDIV,			1
	.equ	Startup_EPLLSTOP,		0
	.equ	Startup_ARMCLKdiv,	0
	.equ	Startup_PREdiv,		0x1
	.equ	Startup_HCLKdiv,		0x1
	.equ	Startup_PCLKdiv,		1
	
	.equ	CLK_DIV_VAL,	((Startup_ARMCLKdiv<<9)|(Startup_PREdiv<<4)|(Startup_PCLKdiv<<2)|(Startup_HCLKdiv)|(1<<3))
	.equ	MPLL_VAL,	((Startup_EPLLSTOP<<24)|(Startup_MDIV<<14)|(Startup_PDIV<<5)|(Startup_SDIV))
	.equ	EPLL_VAL,	(32<<16)|(1<<8)|(2<<0)
	
	
	/* macro 정의 */
	.macro HANDLER, HandlerLabel, HandleLabel
\HandlerLabel:
	sub		sp,sp,#4		/* decrement sp(to store jump address) */
	stmfd	sp!,{r0}			/* PUSH the work register to stack(lr doesn`t push because */ 
						   	/* it return to original address) */
	ldr		r0,=\HandleLabel	/* load the address of HandleXXX to r0 */
	ldr		r0,[r0]         		/* load the contents(service routine start address) of HandleXXX */
	str		r0,[sp,#4]      	/* store the contents(ISR) of HandleXXX to stack */
	ldmfd	sp!,{r0,pc}     	/* POP the work register and pc(jump to ISR) */
	.endm

	.text
	.globl _start
_start:

	/* ResetHandler가 처음부터 나오는 것이 아니라 
	 * vector 주소 영역에는 reset vector가 존재해야 한다
	 * exception이 발생하면 ARM은 하드웨어적으로 다음 주소로 분기된다
	 */
	b	ResetHandler
	b	HandlerUndef			/* handler for Undefined mode */
	b	HandlerSWI			/* handler for SWI interrupt */
	b	HandlerPabort			/* handler for PAbort */
	b	HandlerDabort			/* handler for DAbort */
	b	.						/* reserved */
	b	HandlerIRQ				/* handler for IRQ interrupt */
	b	HandlerFIQ				/* handler for FIQ interrupt */

	.ltorg
HANDLER HandlerFIQ, HandleFIQ
HANDLER HandlerIRQ, HandleIRQ
HANDLER HandlerUndef, HandleUndef
HANDLER HandlerSWI, HandleSWI
HANDLER HandlerDabort, HandleDabort
HANDLER HandlerPabort, HandlePabort

	/* Reset Handler의 시작 */
	.globl ResetHandler
ResetHandler:
	ldr	r0,=WTCON		/* watch dog disable  */
	ldr	r1,=0x0         
	str	r1,[r0]

	ldr	r0,=INTMSK1
	ldr	r1,=0xffffffff		/* all interrupt disable */
	str	r1,[r0]
	ldr	r0,=INTMSK2
	ldr	r1,=0xffffffff
	str	r1,[r0]

	ldr	r0,=INTSUBMSK
	ldr	r1,=0x7fff			/* all sub interrupt disable */
	str	r1,[r0]

	/* Set clock PLL */	
	ldr	r0,=CLKDIV0CON	/* Configure Clock Divide 	for FCLK:HCLK:PCLK  */
	ldr	r1,=CLK_DIV_VAL
	str	r1,[r0]
	
	ldr	r0,=LOCKCON0		/* Set MPLL LockTime*/
	ldr	r1,=0xe10
	str	r1,[r0]

	ldr	r0,=MPLLCON		/* Configure MPLL */
	ldr	r1,=MPLL_VAL   	/* 532MHz @ 12MHz */
	str	r1,[r0]
	
	ldr	r0,=LOCKCON1		/*Set EPLL LockTime*/
	ldr	r1, =0x1780
	str	r1, [r0]
	
	ldr	r0,=EPLLCON		/*Set EPLL*/
	ldr	r1, =EPLL_VAL		
	str	r1, [r0]
	
	ldr	r0,=CLKSRCCON	/* set CLKSRC to fit MPLL and USB */
	ldr	r1, [r0]
	orr	r1, r1, #0x50
	str	r1, [r0]
	
	/* Set memory control registers */
       ldr	r0,=SMRDATA
	ldr	r1,=BANKCFG	/* BANKCFG Address (Start Address) */
	add	r2, r0, #20		/* End address of SMRDATA => total registers = 20/4 = 5개 */
0:
	ldr	r3, [r0], #4   	/* post increment */
	str	r3, [r1], #4  	/* post increment */
	cmp	r2, r0
	bne	0b

	/* C언어의 변수 영역을 설정하기 위한 루틴
	 * 기본적인 메모리 설정이 완료되고 수행하여야 한다
	 * stack의 생성
	 * 기본적으로 C언어 프로그램에서 사용하는 스택이 생성되어야
	 * 함수호출과 지역변수의 사용이 가능하다
	 */

	/* Initialize stacks */
	bl	InitStacks
	
	/* Copy and paste RW data zero initialized data */
	ldr	r0, =rodata_end_addr 	/* text_end_addr Get pointer to ROM data */
	ldr	r1, =data_start_addr 	/* bss_end_addr and RAM copy */
	ldr	r3, =data_end_addr  	/* bss_start_addr  */
	mov r2, r0, lsr #12
 	mov r4, r1, lsr #12

	/* Zero init base => top of initialised data */
	cmp	r2, r4      		/* Check that they are different */
	beq	2f
1:       
	cmp	r1, r3      		/* Copy init data */
	ldrcc	r2, [r0], #4    /* --> LDRCC r2, [r0] + ADD r0, r0, #4 */         
	strcc	r2, [r1], #4    /* --> STRCC r2, [r1] + ADD r1, r1, #4 */
	bcc	1b
2:       
	mov	r2, #0 
       ldr r1,=bss_end_addr 
       ldr r3,=bss_start_addr
3:       
	cmp	r3, r1      /* Zero init */
	strcc	r2, [r3], #4
	bcc	3b
	
	/* 여기서 IRQ가 발생할때 위에서 만든 
	 * IsrIRQ 루틴으로 분기하기 위한 ISR_VECTOR 설정을 한다 
	 */
	/* Setup IRQ handler */
	ldr	r0,=HandleIRQ  
	ldr	r1,=IsrIRQ			
	str	r1,[r0]

	/* 컴파일러의 startup 루틴을 호출하거나 혹은 임의의 Main을 호출
	 * b Main하면 C 함수에서 돌아오지 않음을 가정하는 것이며
	 * bl 하면 되돌아 올수도 있음을 가정한다.
	 * 따라서 되록아 온 후 할 일이 없으면 b %B0 하면 무한 루프가 형성된다.
	 * 이때, 절대로 임베디드 시스템은 프로그램 종료가 없어야 하므로
	 * bl main한 후 돌아와서 무한루프를 형성하지 않는 일을 없도록 주의해야 한다
	 */
	
	bl Exception_Init

	bl	Main	
	b	.

	/* IRQ Handler 생성
	 * IRQ는 발생 소스가 다양하기 때문에 해당 C루틴의 주소를 획득하여야 한다
	 */
	.globl IsrIRQ
IsrIRQ: 
        sub     sp,sp,#4       //reserved for PC
        stmfd   sp!,{r8-r9}   
 
 // check  INTOFFSET1
 chk_off1:
        ldr     r9,=INTOFFSET1
        ldr     r9,[r9]
        cmp r9,#0
 	 beq   chk_off2
        ldr     r8,=HandleEINT0
        add     r8,r8,r9,lsl #2
        b end_off

 // check  INTOFFSET2
 chk_off2:
        ldr     r9,=INTOFFSET2
        ldr     r9,[r9]
        cmp r9,#0
 	 beq   abt_return
        ldr     r8,=Handle2D
        add     r8,r8,r9,lsl #2

end_off: // generic interrupt
        ldr     r8,[r8]
        str     r8,[sp,#8]
        ldmfd   sp!,{r8-r9,pc} 

abt_return: // no interrupt
	 sub lr,lr,#4
        str   lr,[sp,#8]
        ldmfd   sp!,{r8-r9,pc}^

	/* function initializing stacks */
InitStacks:
	/* Don't use DRAM,such as stmfd,ldmfd......
	 * SVCstack is initialized before
	 * Under toolkit ver 2.5, 'msr cpsr,r1' can be used instead of 'msr cpsr_cxsf,r1'
	 */
	mrs	 r0,cpsr
	bic	r0,r0,#Mode_MASK
	orr	r1,r0,#Mode_UND|NOINT
	msr	 cpsr_cxsf,r1		/* UndefMode */
	ldr	sp,=UndefStack
	
	orr	r1,r0,#Mode_ABT|NOINT
	msr	 cpsr_cxsf,r1		/* AbortMode */
	ldr	sp,=AbortStack

	orr	r1,r0,#Mode_IRQ|NOINT
	msr	 cpsr_cxsf,r1		/* IRQMode */
	ldr	sp,=IRQStack
    
	orr	r1,r0,#Mode_FIQ|NOINT
	msr	 cpsr_cxsf,r1		/* FIQMode */
	ldr	sp,=FIQStack

	orr	r1,r0,#Mode_SYS|NOINT
	msr	 cpsr_cxsf,r1		/* SystemMode */
	ldr	sp,=UserStack
	
	bic	r0,r0,#I_Bit
	orr	r1,r0,#Mode_SVC
	msr cpsr_cxsf,r1		/* SVCMode interrupt enable */
	ldr	sp,=SVCStack
	
	/* USER mode has not be initialized. */
	
	mov pc,lr 
	/* The LR register won't be valid if the current mode is not SVC mode. */

	.globl _sbrk
_sbrk:
	nop
	mov pc,lr

	/* MEMORY 설정을 위한 Table
	 * 구동하고자 하는 시스템에 따라 설정은 달라진다
	 */
	
;	.pool
;	.align 2
	.ltorg
SMRDATA:
	.word	0x0004920d
	.word	0x04000040
	.word	0x00570039
	.word	0x80000030
	.word	0x00000313	

	/* C에서 처리할 Exception과 Interrupt 함수 주소를 저장할 위치
	 * startup은 이 주소에서 함수주소를 획득하여 분기한다.
	 */

	.ltorg

	.align 4
	.section int_vect, "w"

	//0x33ffff00
	.globl HandleReset
	.globl HandleUndef
	.globl HandleSWI
	.globl HandlePabort
	.globl HandleDabort
	.globl HandleReserved
	.globl HandleIRQ
	.globl HandleFIQ
HandleReset:		.long   (_ISR_STARTADDRESS + 0x0)
HandleUndef:		.long   (_ISR_STARTADDRESS + 0x4)
HandleSWI:			.long   (_ISR_STARTADDRESS + 0x8)
HandlePabort:		.long   (_ISR_STARTADDRESS + 0xc)
HandleDabort:		.long   (_ISR_STARTADDRESS + 0x10)
HandleReserved:	.long   (_ISR_STARTADDRESS + 0x14)
HandleIRQ:			.long   (_ISR_STARTADDRESS + 0x18)
HandleFIQ:			.long   (_ISR_STARTADDRESS + 0x1c)

	//0x33ffff20
	.globl HandleEINT0
	.globl HandleEINT1
	.globl HandleEINT2
	.globl HandleEINT3
HandleEINT0:		.long	(_ISR_STARTADDRESS + 0x20)
HandleEINT1:		.long	(_ISR_STARTADDRESS + 0x24)
HandleEINT2:		.long	(_ISR_STARTADDRESS + 0x28)
HandleEINT3:		.long	(_ISR_STARTADDRESS + 0x2c)

	//0x33ffff30
	.globl HandleEINT4_7
	.globl HandleEINT8_23
	.globl HandleCAM
	.globl HandleBATFLT
HandleEINT4_7:	.long	(_ISR_STARTADDRESS + 0x30)
HandleEINT8_23:	.long	(_ISR_STARTADDRESS + 0x34)
HandleCAM:		.long	(_ISR_STARTADDRESS + 0x38)
HandleBATFLT:		.long	(_ISR_STARTADDRESS + 0x3c)

	//0x33ffff40
	.globl HandleTICK
	.globl HandleWDT
	.globl HandleTIMER0
	.globl HandleTIMER1
HandleTICK:		.long	(_ISR_STARTADDRESS + 0x40)
HandleWDT:		.long	(_ISR_STARTADDRESS + 0x44)
HandleTIMER0:		.long	(_ISR_STARTADDRESS + 0x48)
HandleTIMER1:		.long	(_ISR_STARTADDRESS + 0x4c)

	//0x33ffff50
	.globl HandleTIMER2
	.globl HandleTIMER3
	.globl HandleTIMER4
	.globl HandleUART2
HandleTIMER2:		.long	(_ISR_STARTADDRESS + 0x50)
HandleTIMER3:		.long	(_ISR_STARTADDRESS + 0x54)
HandleTIMER4:		.long	(_ISR_STARTADDRESS + 0x58)
HandleUART2:		.long	(_ISR_STARTADDRESS + 0x5c)

	//0x33ffff60
	.globl HandleLCD
	.globl HandleDMA
	.globl HandleUART3
	.globl HandleCFCON
HandleLCD:		.long	(_ISR_STARTADDRESS + 0x60)
HandleDMA:		.long	(_ISR_STARTADDRESS + 0x64)
HandleUART3:		.long	(_ISR_STARTADDRESS + 0x68)
HandleCFCON:		.long	(_ISR_STARTADDRESS + 0x6c)

	//0x33ffff70
	.globl HandleSDI1
	.globl HandleSDI0
	.globl HandleSPI0
	.globl HandleUART1
HandleSDI1:		.long	(_ISR_STARTADDRESS + 0x70)
HandleSDI0:		.long	(_ISR_STARTADDRESS + 0x74)
HandleSPI0:		.long	(_ISR_STARTADDRESS + 0x78)
HandleUART1:		.long	(_ISR_STARTADDRESS + 0x7c)

	//0x33ffff80
	.globl HandleNFCON
	.globl HandleUSBD
	.globl HandleUSBH
	.globl HandleIIC
HandleNFCON:		.long	(_ISR_STARTADDRESS + 0x80)
HandleUSBD:		.long	(_ISR_STARTADDRESS + 0x84)
HandleUSBH:		.long	(_ISR_STARTADDRESS + 0x88)
HandleIIC:			.long	(_ISR_STARTADDRESS + 0x8c)

	//0x33ffff90
	.globl HandleUART0
	.globl HandleSPI1
	.globl HandleRTC
	.globl HandleADC
HandleUART0:		.long	(_ISR_STARTADDRESS + 0x90)
HandleSPI1:		.long	(_ISR_STARTADDRESS + 0x94)
HandleRTC:		.long	(_ISR_STARTADDRESS + 0x98)
HandleADC:		.long	(_ISR_STARTADDRESS + 0x9c)

	//0x33ffffA0
	.globl Handle2D
	.globl HandleIIC1
	.globl HandleRSV1
	.globl HandleRSV2
Handle2D:			.long	(_ISR_STARTADDRESS + 0xA0)
HandleIIC1:			.long	(_ISR_STARTADDRESS + 0xA4)
HandleRSV1:		.long	(_ISR_STARTADDRESS + 0xA8)
HandleRSV2:		.long	(_ISR_STARTADDRESS + 0xAc)

	//0x33ffffB0
	.globl HandlePCM0
	.globl HandlePCM1
	.globl HandleI2S0
	.globl HandleI2S1
HandlePCM0:		.long	(_ISR_STARTADDRESS + 0xB0)
HandlePCM1:		.long	(_ISR_STARTADDRESS + 0xB4)
HandleI2S0:		.long	(_ISR_STARTADDRESS + 0xB8)
HandleI2S1:		.long	(_ISR_STARTADDRESS + 0xBc)
