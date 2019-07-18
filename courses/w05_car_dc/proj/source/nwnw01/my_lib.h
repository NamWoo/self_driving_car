//=============================================================================
// File Name : my_lib.h
//=============================================================================


// UART.c
extern char Uart_GetKey(void);
extern char Uart_GetChar(void);
extern void Uart_Init(int baud);
extern void Uart_Printf(char *fmt,...);
extern void Uart_Send_Byte(int data);
extern void Uart_Send_String(char *pt);

// timer.c
void Timer_Init(void);
void Timer_Delay(int msec);

// iic.c
__attribute__ ((interrupt ("IRQ"))) void IIC_Int(void);
void IIC_open( unsigned int);
void IIC_close( void);
void IIC_Write( unsigned char, char *, unsigned int);
void IIC_Wait( void);
unsigned char IIC_Status( void);

// iis.c
__attribute__ ((interrupt ("IRQ"))) void DMA2_Done(void);
void IIS_Port_Init(void);
void IIS_Port_Return(void);
void WriteCodecModule( char CodecIICID, char Addr, char Data);
void InitWM8960(int mode);
void Select_PCLK(void);
void Play_Iis_speak(void);
void Play_Iis_Bypass(void);
void IIS_PlayWave_DMA2(unsigned char *start_addr, unsigned int play_size);


//Libraries on the libc.c
void MMU_Init(void);
void ChangeRomCacheStatus(int attr);
void MMU_SetMTT(int vaddrStart,int vaddrEnd,int paddrStart,int attr);

void *malloc(unsigned nbyte); 
void free(void *pt);

int  Uart_GetIntNum(void);
void Uart_Printf(char *fmt,...);

void MemFill(unsigned long ptr, unsigned long pattern, int size);
void MemDump(unsigned long ptr, int size);

// Libraries on the libs.s

int SET_IF(void);
void WR_IF(int cpsrValue);
void CLR_IF(void);

void MMU_EnableICache(void);
void MMU_DisableICache(void);
void MMU_EnableDCache(void);
void MMU_DisableDCache(void);
void MMU_EnableAlignFault(void);
void MMU_DisableAlignFault(void);
void MMU_EnableMMU(void);
void MMU_DisableMMU(void);
void MMU_SetTTBase(unsigned long base);
void MMU_SetDomain(unsigned long domain);

void MMU_SetFastBusMode(void);          //GCLK=HCLK
void MMU_SetAsyncBusMode(void);         //GCLK=FCLK @(FCLK>=HCLK)

void MMU_InvalidateIDCache(void);
void MMU_InvalidateICache(void);
void MMU_InvalidateICacheMVA(unsigned long mva);
void MMU_PrefetchICacheMVA(unsigned long mva);
void MMU_InvalidateDCache(void);
void MMU_InvalidateDCacheMVA(unsigned long mva);
void MMU_CleanDCacheMVA(unsigned long mva);
void MMU_CleanInvalidateDCacheMVA(unsigned long mva);
void MMU_CleanDCacheIndex(unsigned long index);
void MMU_CleanInvalidateDCacheIndex(unsigned long index); 
void MMU_WaitForInterrupt(void);
        
void MMU_InvalidateTLB(void);
void MMU_InvalidateITLB(void);
void MMU_InvalidateITLBMVA(unsigned long mva);
void MMU_InvalidateDTLB(void);
void MMU_InvalidateDTLBMVA(unsigned long mva);

void MMU_SetDCacheLockdownBase(unsigned long base);
void MMU_SetICacheLockdownBase(unsigned long base);

void MMU_SetDTLBLockdown(unsigned long baseVictim);
void MMU_SetITLBLockdown(unsigned long baseVictim);

void MMU_SetProcessId(unsigned long pid);
