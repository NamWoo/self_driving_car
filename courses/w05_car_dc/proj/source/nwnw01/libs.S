/*
 * =====================================================================
 * NAME: 
 *       libs.S
 *
 * Descriptions : 
 *       Libraries for Assembler
 *
 * Developing Environment : 
 *       CodeWarrior 2.0 or Later
 *
 * =====================================================================
 */

/* Interrupt, FIQ/IRQ disable */

	.equ	NOINT, 0xc0

/*
 * =====================================================================
 * The Function for Testing
 * =====================================================================
 */
 
	/* 
	 * void HOW_TO_RETURN(void);
	 * -----------------------------------------------------------------
	 */
	.globl  HOW_TO_RETURN
HOW_TO_RETURN:
	/* IMPLEMENT HERE : return ? */	
	mov pc, lr
	/* IGNORE this branch instruction */
	b	.
 

 	/* 
	 * int CONDITIONAL_EXECUTE(int a, int b);
	 * -----------------------------------------------------------------
	 *    r0=a, r1=b
	 *    The return value is result (r0)
	 */
	.globl  CONDITIONAL_EXECUTE
CONDITIONAL_EXECUTE:
	/* IMPLEMENT HERE
	 * use CMP and MOV instruction only : 4 line
	 * result must be stored to r0 as follow ATPCS
	 */
	cmp	r0, r1
	movlt r0, #1
	movgt r0, #2
	moveq r0, #3
	 
 	mov pc, lr	/* return */
 	
	/* 
	 * int DATA_PROCESS1(int a, int b, int c);
	 * -----------------------------------------------------------------
	 *    r0=a, r1=b, r2=c
	 *    The return value is result (r0)
	 */
	 .globl	DATA_PROCESS1
DATA_PROCESS1:
	/*
	 * IMPLEMENT function for calcurate result=(a+b)- c in this location
	 * use R3 Destination Register(Rd)
	 * use ADD, SUB and MOV instruction : 3 line
	 */
	 add r3, r0, r1
	 sub r3, r3, r2
	 mov r0, r3
	
	 mov pc, lr	/* return */

	/* 
	 * unsigned long DATA_PROCESS2(unsigned long a, unsigned long b);
	 * -----------------------------------------------------------------
	 *    r0=a, r1=b
	 *    The return value is result (r0)
	 */
	 .globl	DATA_PROCESS2
DATA_PROCESS2:	 
	/*
	 * IMPLEMENT function for calcurate result=(a<<2) | (b&15) in this location
	 * use R2 Destination Register(Rd)
	 * use AND, ORR and MOV instruction : 3 line
	 */
	 and r3, r1, #15
	 orr r3, r3, r0, lsl #2
	 mov r0, r3
	 
	 mov pc, lr	/* return */	
 
	/* 
	 * int SUM_OF_DEC(int start, int end);
	 * -----------------------------------------------------------------
	 *    r0=start, r1=end
	 *    The return value is SUM (r0)
	 */
	.globl  SUM_OF_DEC
SUM_OF_DEC:
	/* IMPLEMENT HERE  */
	mov	r3, #0x0	/*; initialize sum */
sum_loop:
	add	r3, r3, r0	/*; add total to r3 */
	add	r0, r0, #1	/*; increase 1 */
	cmp	r0, r1		/*; compare start and end */
	ble	sum_loop	/*; compare */

	mov	r0, r3		/*; copy to argument */

	mov pc, lr	/* return */
	
	/* 
	 * void GRT_COM_MES(int a, int b);
	 * -----------------------------------------------------------------
	 * 	r0=30, r1=18
	 * 	The return value is MES
	 */
	.globl GRT_COM_MES	
GRT_COM_MES:
	/* IMPLEMENT HERE :  */
gcm_loop:
 	cmp	r0, r1			/* compare 'a' and 'b' */
 	subgt 	r0, r0, r1	/* if (a>b) a=a-b (if a==b do nothing) */
 	sublt 	r1, r1, r0	/* if (b>a) b=b-a (if a==b do nothing) */
 	bne	gcm_loop		/* if (a!=b) then return to GCM_LOOP */

	mov pc, lr 	 	/* return */
	
	/* 
	 * void MEMCPY_SINGLE(unsigned long dst, unsigned long src, int size);
	 * -------------------------------------------------------------------
	 *    r0=dst, r1=src, r2=size
	 */
	.globl  MEMCPY_SINGLE
MEMCPY_SINGLE:
	stmfd sp!, {r4-r5, lr} 	/* push */
	/* IMPLEMENT HERE */
copy_loop_single:
	ldr r3, [r1], #4		/* load source data */
	str	r3, [r0], #4		/* store data to destination */
	subs r2, r2, #1			/* decrease size */
	bne	copy_loop_single

	ldmfd sp!, {r4-r5, pc}	/* pop */

	/* 
	 * void MEMCPY_MULTIPLE(unsigned long dst, unsigned long src, int size);
	 * ---------------------------------------------------------------------
	 *    r0=dst, r1=src, r2=size
	 * Comments
	 *      1. COPY 3 WORD at one time only, 3x4=12
	 *      2. Use LDMIA and STMIA
	 */
	.globl  MEMCPY_MULTIPLE
MEMCPY_MULTIPLE:
	stmfd sp!, {r4-r5, lr} 	/* push */
	/* IMPLEMENT HERE */
copy_loop_multiple:
	ldmia r1!, {r3-r5}
	stmia r0!, {r3-r5}
	subs r2, r2, #3		/* decrease size */
	bne copy_loop_multiple

	ldmfd sp!, {r4-r5, pc}	/* pop */
	
	/* 
	 * void MEMCPY(unsigned long dst, unsigned long src, int size);
	 * ------------------------------------------------------------
	 *    r0=dst, r1=src, r2=size (byte count)
	 * Comments
	 *      1. COPY 3 WORD at one time only, 3x4=12
	 *      2. Use LDMIA and STMIA for over than 3 word
	 *      3. Use LDR/STR for single word, halfword and byte access
	 */
	.globl  MEMCPY
MEMCPY:
	stmfd sp!, {r4-r5, lr} 	/* push */
	/* IMPLEMENT HERE */
copy_loop_multi_word:
	ldmia r1!, {r3-r5}
	stmia r0!, {r3-r5}
	sub r2, r2, #12			/* decrease 3 word(12byte)size */
	cmp r2, #12
	bge	copy_loop_multi_word
	
copy_loop_single_word:
	ldr r3, [r1], #4	/* load source data */
	str	r3, [r0], #4	/* store data to destination */
	sub r2, r2, #4		/* decrease size */
	cmp r2, #4
	bge	copy_loop_single_word
	
copy_loop_single_byte:
	ldrb r3, [r1], #1	/* load source data */
	strb r3, [r0], #1	/* store data to destination */
	subs r2, r2, #1		/* decrease size */
	bne	copy_loop_single_byte

	ldmfd sp!, {r4-r5, pc}	/* pop */

/*
 * =====================================================================
 * CPSR I,F bit
 * =====================================================================
 */
	/* 
	 * int SET_IF(void);
	 * -----------------------------------------------------------------
	 *     The return value is current CPSR.
	 */
	.globl  SET_IF
SET_IF:
	/* This function works only if the processor is in previliged mode. */
	mrs  r0,cpsr
	mov  r1,r0
	orr  r1,r1,#NOINT
	msr  cpsr_cxsf,r1             
	mov	 pc,lr

	/* 
	 * void WR_IF(int cpsrValue);
	 * -----------------------------------------------------------------
	 */
	.globl WR_IF
WR_IF: 
	/* This function works only if the processor is in previliged mode. */
	msr  cpsr_cxsf,r0             
	mov	 pc,lr

	/* 
	 * void CLR_IF(void);
	 * -----------------------------------------------------------------
	 */
	.globl  CLR_IF
CLR_IF:
	/* This function works only if the processor is in previliged mode. */
	mrs  r0,cpsr
	bic  r0,r0,#NOINT
	msr  cpsr_cxsf,r0             
	mov	 pc,lr

/*
 * =====================================================================
 * MMU Cache/TLB/etc on/off functions
 * =====================================================================
 */
 	.equ	R1_I,  0x1000
 	.equ	R1_C,  0x4
 	.equ	R1_A,  0x2
 	.equ	R1_M,  0x1
 	.equ	R1_iA, 0x80000000
 	.equ	R1_nF, 0x40000000

	/* 
	 * void MMU_EnableICache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_EnableICache
MMU_EnableICache:
	/* IMPLEMENT HERE */      
	mrc  p15,0,r0,c1,c0,0
	orr  r0,r0,#R1_I
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_DisableICache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_DisableICache
MMU_DisableICache:
	mrc  p15,0,r0,c1,c0,0
	bic  r0,r0,#R1_I
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_EnableDCache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_EnableDCache
MMU_EnableDCache:
	/* IMPLEMENT HERE */
	mrc  p15,0,r0,c1,c0,0
	orr  r0,r0,#R1_C
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_DisableDCache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_DisableDCache
MMU_DisableDCache:
	mrc  p15,0,r0,c1,c0,0
	bic  r0,r0,#R1_C
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_EnableAlignFault(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_EnableAlignFault 
MMU_EnableAlignFault:
	mrc  p15,0,r0,c1,c0,0
	orr  r0,r0,#R1_A
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_DisableAlignFault(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_DisableAlignFault
MMU_DisableAlignFault:
	mrc  p15,0,r0,c1,c0,0
	bic  r0,r0,#R1_A
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_EnableMMU(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_EnableMMU
MMU_EnableMMU:
	/* IMPLEMENT HERE */
	mrc  p15,0,r0,c1,c0,0
	orr  r0,r0,#R1_M
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_DisableMMU(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_DisableMMU
MMU_DisableMMU:
	mrc  p15,0,r0,c1,c0,0
	bic  r0,r0,#R1_M
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_SetFastBusMode(void)
	 * -----------------------------------------------------------------
	 * 	FCLK:HCLK= 1:1
	 */
	.globl MMU_SetFastBusMode
MMU_SetFastBusMode:
	mrc  p15,0,r0,c1,c0,0
	bic  r0,r0,#R1_iA
	bic  r0,r0,#R1_nF
/*	bic  r0,r0,#R1_iA:OR:R1_nF */
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

	/* 
	 * void MMU_SetAsyncBusMode(void) 
	 * -----------------------------------------------------------------
	 * 	FCLK:HCLK= 1:2
	 */
	.globl MMU_SetAsyncBusMode
MMU_SetAsyncBusMode:
	mrc  p15,0,r0,c1,c0,0
/*	orr  r0,r0,#R1_nF:OR:R1_iA */
	orr  r0,r0,#R1_nF
	orr  r0,r0,#R1_iA
	mcr  p15,0,r0,c1,c0,0
	mov	 pc,lr

/*
 * =====================================================================
 * Set TTBase
 * =====================================================================
 */
	/* 
	 * void MMU_SetTTBase(int base)
	 * -----------------------------------------------------------------
	 *    r0=TTBase
	 */
	.globl MMU_SetTTBase
MMU_SetTTBase:
	/* IMPLEMENT HERE */
	mcr  p15,0,r0,c2,c0,0
	mov	 pc,lr

/*
 * =====================================================================
 * Set Domain
 * =====================================================================
 */
	/* 
	 * void MMU_SetDomain(int domain)
	 * -----------------------------------------------------------------
	 *    r0=domain
	 */
	.globl MMU_SetDomain
MMU_SetDomain:
	mcr  p15,0,r0,c3,c0,0
	mov	 pc,lr

/*
 * =====================================================================
 * ICache/DCache functions
 * =====================================================================
 */
	/* 
	 * void MMU_InvalidateIDCache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_InvalidateIDCache
MMU_InvalidateIDCache:
	mcr  p15,0,r0,c7,c7,0
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateICache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_InvalidateICache
MMU_InvalidateICache:
	mcr  p15,0,r0,c7,c5,0
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateICacheMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *    r0=mva
	 */
	.globl MMU_InvalidateICacheMVA
MMU_InvalidateICacheMVA:
	mcr  p15,0,r0,c7,c5,1
	mov	 pc,lr
        
	/* 
	 * void MMU_PrefetchICacheMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *     r0=mva
	 */
	.globl MMU_PrefetchICacheMVA
MMU_PrefetchICacheMVA:
	mcr  p15,0,r0,c7,c13,1
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateDCache(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_InvalidateDCache
MMU_InvalidateDCache:
	mcr  p15,0,r0,c7,c6,0
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateDCacheMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *     r0=mva
	 */
	.globl MMU_InvalidateDCacheMVA
MMU_InvalidateDCacheMVA:
	mcr  p15,0,r0,c7,c6,1
	mov	 pc,lr

	/* 
	 * void MMU_CleanDCacheMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *     r0=mva
	 */
	.globl MMU_CleanDCacheMVA
MMU_CleanDCacheMVA:
	mcr  p15,0,r0,c7,c10,1
	mov	 pc,lr

	/* 
	 * void MMU_CleanInvalidateDCacheMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *     r0=mva
	 */
	.globl MMU_CleanInvalidateDCacheMVA
MMU_CleanInvalidateDCacheMVA:
	mcr  p15,0,r0,c7,c14,1
	mov	 pc,lr

	/* 
	 * void MMU_CleanDCacheIndex(unsigned long index)
	 * -----------------------------------------------------------------
	 *     r0=index 
	 */
	.globl MMU_CleanDCacheIndex
MMU_CleanDCacheIndex:
	mcr  p15,0,r0,c7,c10,2
	mov	 pc,lr

	/* 
	 * void MMU_CleanInvalidateDCacheIndex(unsigned long index) 
	 * -----------------------------------------------------------------
	 *     r0=index 
	 */
	.globl MMU_CleanInvalidateDCacheIndex
MMU_CleanInvalidateDCacheIndex:  
	mcr  p15,0,r0,c7,c14,2
	mov	 pc,lr

	/* 
	 * void MMU_WaitForInterrupt(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_WaitForInterrupt 
MMU_WaitForInterrupt:
	mcr  p15,0,r0,c7,c0,4
	mov	 pc,lr

/*
 * =====================================================================
 * TLB functions
 * =====================================================================
 */
	/* 
	 * void MMU_InvalidateTLB(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_InvalidateTLB
MMU_InvalidateTLB:
	mcr  p15,0,r0,c8,c7,0
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateITLB(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_InvalidateITLB
MMU_InvalidateITLB:
	mcr  p15,0,r0,c8,c5,0
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateITLBMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *     r0=mva 
	 */
	.globl MMU_InvalidateITLBMVA
MMU_InvalidateITLBMVA:
	mcr  p15,0,r0,c8,c5,1
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateDTLB(void)
	 * -----------------------------------------------------------------
	 */
	.globl MMU_InvalidateDTLB
MMU_InvalidateDTLB:
	mcr p15,0,r0,c8,c6,0
	mov	 pc,lr

	/* 
	 * void MMU_InvalidateDTLBMVA(unsigned long mva)
	 * -----------------------------------------------------------------
	 *     r0=mva 
	 */
	.globl MMU_InvalidateDTLBMVA 
MMU_InvalidateDTLBMVA:
	mcr p15,0,r0,c8,c6,1
	mov	 pc,lr

/*
 * =====================================================================
 * Cache lock down
 * =====================================================================
 */
	/* 
	 * void MMU_SetDCacheLockdownBase(unsigned long base)
	 * -----------------------------------------------------------------
	 *     r0=victim & lockdown base
	 */
	.globl MMU_SetDCacheLockdownBase 
MMU_SetDCacheLockdownBase:
	mcr  p15,0,r0,c9,c0,0
	mov	 pc,lr
        
	/* 
	 * void MMU_SetICacheLockdownBase(unsigned long base)
	 * -----------------------------------------------------------------
	 *     r0=victim & lockdown base
	 */
	.globl MMU_SetICacheLockdownBase
MMU_SetICacheLockdownBase:
	mcr  p15,0,r0,c9,c0,1
	mov	 pc,lr

/*
 * =====================================================================
 * TLB lock down
 * =====================================================================
 */
	/* 
	 * void MMU_SetDTLBLockdown(unsigned long baseVictim)
	 * -----------------------------------------------------------------
	 *     r0=baseVictim
	 */
	.globl MMU_SetDTLBLockdown
MMU_SetDTLBLockdown:
	mcr  p15,0,r0,c10,c0,0
	mov	 pc,lr
        
	/* 
	 * void MMU_SetITLBLockdown(unsigned long baseVictim)
	 * -----------------------------------------------------------------
	 *     r0=baseVictim
	 */
	.globl MMU_SetITLBLockdown
MMU_SetITLBLockdown:
	mcr  p15,0,r0,c10,c0,1
	mov	 pc,lr

/*
 * =====================================================================
 * Process ID
 * =====================================================================
 */
	/* 
	 * void MMU_SetProcessId(unsigned long pid)
	 * -----------------------------------------------------------------
	 *     r0=pid
	 */
	.globl MMU_SetProcessId
MMU_SetProcessId:
	mcr  p15,0,r0,c13,c0,0
	mov	 pc,lr
        

