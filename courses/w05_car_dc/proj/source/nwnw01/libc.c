/*
 * =====================================================================
 * NAME: 
 *       libc.c
 *
 * Descriptions : 
 *       C library for S3C2450
 *
 * Developing Environment : 
 *       CodeWarrior 2.0 or Later
 *
 * =====================================================================
 */

#include "2450addr.h"
#include "option.h"
#include "stdarg.h"
#include "my_lib.h"

void *mallocPt=(void*)0x32000000;

void Led_Port_Init(void);

/*
 * =====================================================================
 * Handling MMU Librarues
 * =====================================================================
 *   1) Only the section table is used. 
 *   2) The cachable/non-cachable area can be changed by MMT_DEFAULT value.
 *      The section size is 1MB.
 */

	/* 
	 * void MMU_Init(void)
	 * -----------------------------------------------------------------
	 */
void MMU_Init(void)
{
	unsigned long i,j;
	//========================== IMPORTANT NOTE =========================
	//The current stack and code area can't be re-mapped in this routine.
	//If you want memory map mapped freely, your own sophiscated MMU
	//initialization code is needed.
	//===================================================================

	MMU_DisableDCache();
	MMU_DisableICache();

	//If write-back is used,the DCache should be cleared.
	for(i=0;i<64;i++)
	for(j=0;j<8;j++)
    	    MMU_CleanInvalidateDCacheIndex((i<<26)|(j<<5));
	MMU_InvalidateICache();
       
	MMU_DisableMMU();
	MMU_InvalidateTLB();

	/* MMU_SetMTT(int vaddrStart,int vaddrEnd,int paddrStart,int attr) */
	MMU_SetMTT(0x00000000,0x07f00000,0x30000000,RW_NCNB); //bank0
	MMU_SetMTT(0x08000000,0x0ff00000,0x08000000,RW_NCNB); //bank1
	MMU_SetMTT(0x10000000,0x17f00000,0x10000000,RW_NCNB); //bank2
	MMU_SetMTT(0x18000000,0x1ff00000,0x18000000,RW_NCNB); //bank3
	MMU_SetMTT(0x20000000,0x27f00000,0x20000000,RW_NCNB); //bank4
	MMU_SetMTT(0x28000000,0x2ff00000,0x28000000,RW_NCNB); //bank5
	
	/* 
	 * USER WILL TEST WITH BANK 6
	 * the each attribute value such as RW_CB, RW_NCNB, .... was decleared on libc.h
	 *
	 * 1. Please IMPLEMENT MMU_SetMTT function
	 */
	MMU_SetMTT(0x30000000,0x31f00000,0x30000000,RW_CB);   //bank6-1, TEXT/DATA
	MMU_SetMTT(0x32000000,0x33e00000,0x32000000,RW_CB);  //bank6-2, TEST DATA,LCD FrameBuffer
	MMU_SetMTT(0x33f00000,0x33f00000,0x33f00000,RW_NCNB);   //bank6-3
	MMU_SetMTT(0x34000000,0x37f00000,0x34000000,RW_NCNB);   //bank6-3
	MMU_SetMTT(0x38000000,0x3ff00000,0x38000000,RW_NCNB); //bank7
    
	MMU_SetMTT(0x40000000,0x5af00000,0x40000000,RW_NCNB);//SFR+StepSram    
	MMU_SetMTT(0x5b000000,0xfff00000,0x5b000000,RW_FAULT);//not used

	/* 
	 * 2. Please IMPLEMENT MMU_SetTTBase function : libs.S 
	 */
	MMU_SetTTBase(_MMUTT_STARTADDRESS);
	
	/* DOMAIN1: no_access, DOMAIN0,2~15=client(AP is checked) */
	MMU_SetDomain(0x55555550|DOMAIN1_ATTR|DOMAIN0_ATTR); 

	MMU_SetProcessId(0x0);
	MMU_EnableAlignFault();

	/* 
	 * 3. Please IMPLEMENT MMU_EnableMMU,MMU_EnableICache and MMU_EnableDCache
	 *     : libs.S 
	 */
	MMU_EnableMMU();
	MMU_EnableICache();
	MMU_EnableDCache(); /* IMPORTANT : DCache should be turned on after MMU is turned on. */
}   

	/* 
	 * void MMU_SetMTT(int vaddrStart,int vaddrEnd,int paddrStart,int attr)
	 * -----------------------------------------------------------------
	 * Attribute : RW_CB,RW_CNB,RW_NCNB,RW_FAULT
	 */
void MMU_SetMTT(int vaddrStart,int vaddrEnd,int paddrStart,int attr)
{
	unsigned long *pTT;
	int i,nSec;
	
	/* 
	 * 1. Get Translation Table base address on Physical memory
	 *    Translation table held each 1 word translation descriptor for each 1MB section
	 *    The Level 1 translation descript location for each 1M section can be calcurated
	 *    from Translation Table Base address and virtual address 
	 *
	 *    The variable for actual translation descriptor location : pTT
	 *    MMU Translation Table Base Address : _MMUTT_STARTADDRESS
	 *	  Address bit [31:20] specify M byte address
	 */
	pTT=(unsigned long *)_MMUTT_STARTADDRESS+(vaddrStart>>20);
	
	/*
	 * 2. We must configure each 1M section descriptor
	 *    So, we must get a number of section from start virtual address (vaddrStart)
	 *        to end of virtual address (vaddrEnd)
	 *    The number of scetion : nSec
	 */ 
	nSec=(vaddrEnd>>20)-(vaddrStart>>20);
	
	for(i=0;i<=nSec;i++) 
	{
		/*
		 * 3. We must write down physical address and attribute information to 
		 *    each section descriptor
		 *    Section descriptor location : *pTT
		 *    Configuration Value : (physical address information) | (attribute)
		 *        The physical address information was held from address bit 20 (1M byte address)
		 */
		*pTT++ = (((paddrStart>>20)+i)<<20) | attr ;
	}
} 

	/* 
	 * void ChangeRomCacheStatus(int attr)
	 * -----------------------------------------------------------------
	 * Attribute : RW_CB,RW_CNB,RW_NCNB,RW_FAULT
	 */
void ChangeRomCacheStatus(int attr)
{
	int i,j;
	MMU_DisableDCache();
	MMU_DisableICache();

	//If write-back is used,the DCache should be cleared.
	for(i=0;i<64;i++)
    	for(j=0;j<8;j++)
    	    MMU_CleanInvalidateDCacheIndex((i<<26)|(j<<5));

	MMU_InvalidateICache();
	MMU_DisableMMU();
	MMU_InvalidateTLB();
	MMU_SetMTT(0x00000000,0x07f00000,0x00000000,attr);	//bank0
	MMU_SetMTT(0x08000000,0x0ff00000,0x08000000,attr);	//bank1
	MMU_EnableMMU();
	MMU_EnableICache();
	MMU_EnableDCache();
}    
    
/*
 * =====================================================================
 * Memory Management Librarues
 * =====================================================================
 */

	/* 
	 * malloc
	 * -----------------------------------------------------------------
	 */
void * malloc(unsigned nbyte) 
{
    void *returnPt = mallocPt;

    mallocPt = (int *)mallocPt+nbyte/4+((nbyte%4)>0); //To align 4byte

    if( (int)mallocPt > HEAPEND )
    {
        mallocPt = returnPt;
        return NULL;
    }
    return returnPt;
}

	/* 
	 * free
	 * -----------------------------------------------------------------
	 */
void free(void *pt)
{
    mallocPt = pt;
}


/*
 * =====================================================================
 * LED Display Librarues
 * =====================================================================
 */
void Led_Port_Init(void)
{	
	/* 
	 * LED On : Active Low 
	 * Initialize GPGDAT[7:4] : high
	 * Setup GPGCON[15:8] : 01-> GPG7~4 Output mode
	 * GPGUP pull up function disable
	 * 
	 */
	/* YOUR CODE HERE */  
	rGPGDAT |= (0xf<<4);
	
	rGPGCON &= ~(0xff<<8);
	rGPGCON |= (0x55<<8);
	rGPGUDP &= 0xf<<4;
}

void Led_Display(int data)
{
	/* 
 	 * LED On : Active high 
     * LED Off: Active low
	 * GPGDAT[7:4]
	 */
	
	rGPGDAT |= (0xf<<4);

	if(data & 0x01)  rGPGDAT &= ~(0x1<<7);
	if(data & 0x02)  rGPGDAT &= ~(0x1<<6);
	if(data & 0x04)  rGPGDAT &= ~(0x1<<5);
	if(data & 0x08)  rGPGDAT &= ~(0x1<<4);  

}

/*
 * =====================================================================
 * Timer Librarues
 * =====================================================================
 */


	/* 
	 * void start_timer0(void)
	 * -----------------------------------------------------------------
	 *     start time 0 with maximum divide value for calcurate performance
	 */
void start_timer0(void)
{
	rTCFG0 = 0xff;
	rTCNTB0 = 0xffff; /* max of 16 bit value */
	rTCON = 2; /* update CNTB */	
	rTCON = 1; /* start timer 0 */
}

	/* 
	 * void stop_timer0(void)
	 * -----------------------------------------------------------------
	 * 
	 */
void stop_timer0(void)
{
	
	rTCON = 0; /* stop timer 0 */
}

	/* 
	 * void time (void)
	 * -----------------------------------------------------------------
	 * Get current value of timer 0
	 */
int time (void)
{
	return 0xffff - rTCNTO0 ;	
}

/*
 * =====================================================================
 * Memory Debugging
 * =====================================================================
 */
void MemFill(unsigned long ptr, unsigned long pattern, int size)
{
	int i;
	unsigned long *data;
	data = (unsigned long *)ptr;

	for (i=0; i<size;i++)
		*data++ = pattern;
}

void MemDump(unsigned long ptr, int size)
{
	int i;
	unsigned long *data;
	data = (unsigned long *)ptr;

	Uart_Printf("\n");
	Uart_Printf("*** Dump Memory from [0x%08x] to [0x%08x] : \n",ptr, (unsigned long *)ptr+size);
	for (i=0; i<size;i++) {
		if ( !(i%4) )
			Uart_Printf("\n  [0x%08x] : ",data);
		Uart_Printf("0x%08x ",*data++);
	}
	Uart_Printf("\n");
}
