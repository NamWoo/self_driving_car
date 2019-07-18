#include "2450addr.h"
#include "macro.h"

void Exception_Init(void);
void Undef_Handler(void);
void Pabort_Handler(void);
void Dabort_Handler(void);
void SWI_Handler(void);

extern unsigned int  HandleUndef;
extern unsigned int  HandleSWI;
extern unsigned int  HandlePabort;
extern unsigned int  HandleDabort;

void Uart_Printf(const char *fmt,...);

void SWI_Handler(void)
{
	Uart_Printf("SWI exception.\n");
	for(;;);
}

void Undef_Handler(void) 
{
	Uart_Printf("Undefined instruction exception.\n");
	for(;;);
}

void Pabort_Handler(void)
{
	volatile int prefetch_addr=0;
	
	 __asm volatile(
		"mov %[retval],lr\n"
		"sub %[retval],%[retval],#4\n"
		: [retval] "=r" (prefetch_addr) : :
	);	
	Uart_Printf("Pabort exception in address 0x%08x.\n", prefetch_addr);		
	for(;;);
}

void Dabort_Handler(void)
{
	volatile int data_addr=0;

	 __asm volatile(
		"mov %[retval1],lr\n"
		"sub %[retval1],%[retval1],#8\n"
		: [retval1] "=r" (data_addr) : :
	);	
	Uart_Printf("Dabort exception in address 0x%08x.\n", data_addr);				
	for(;;);
}

void Exception_Init(void)
{
	HandleUndef  = (unsigned)Undef_Handler;
	HandleSWI    = (unsigned)SWI_Handler;
	HandlePabort = (unsigned)Pabort_Handler;
	HandleDabort = (unsigned)Dabort_Handler;
	// Disable Interrupt
	rINTMOD1   = 0x0;
	rINTMSK1    = BIT_ALLMSK;		
	rINTMOD2   = 0x0;
	rINTMSK2    = BIT_ALLMSK;		

	// Clear All Previous Pending Bits
	rSRCPND1 = 0xffffffff;
	rSRCPND2 = 0xffffffff;
	rINTPND1 = 0xffffffff;  
}