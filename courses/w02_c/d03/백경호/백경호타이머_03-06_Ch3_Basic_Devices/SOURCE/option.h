//=============================================================================
// File Name : option.h
//=============================================================================
#ifndef __OPTION_H__
#define __OPTION_H__

#define _SDRAM_STARTADDRESS			0x30000000
#define _ISR_STARTADDRESS			0x33ffff00
#define _ISR_ENDADDRESS				(_ISR_STARTADDRESS+0x9c)
// C 변수 메모리 영역은 반드시 ISR_Start 주소 이후 이어야 한다
#define _CMEMORY_STARTADDRESS		(_SDRAM_STARTADDRESS)
#define _MMUTT_STARTADDRESS     0x33ff8000
#define HEAPEND                 0x33ff0000

// Frequency setting

#define	FCLK		534000000	// 534.000MHz (400MHz)
#define	HCLK		(FCLK/4)		// 133.000MHz (100MHz)
#define	PCLK		(FCLK/8)		// 66.0000MHz (50MHz)

// Variable Definition

#define DESC_SEC		(0x2|(1<<4))
#define CB			(3<<2)  //cache_on, write_back
#define CNB			(2<<2)  //cache_on, write_through 
#define NCB			(1<<2)  //cache_off,WR_BUF on
#define NCNB			(0<<2)  //cache_off,WR_BUF off
#define AP_RW			(3<<10) //supervisor=RW, user=RW
#define AP_RO			(2<<10) //supervisor=RW, user=RO

#define DOMAIN_FAULT	(0x0)
#define DOMAIN_CHK		(0x1) 
#define DOMAIN_NOTCHK	(0x3) 
#define DOMAIN0		(0x0<<5)
#define DOMAIN1		(0x1<<5)

#define DOMAIN0_ATTR	(DOMAIN_CHK<<0) 
#define DOMAIN1_ATTR	(DOMAIN_FAULT<<2) 

#define RW_CB			(AP_RW|DOMAIN0|CB|DESC_SEC)
#define RW_CNB			(AP_RW|DOMAIN0|CNB|DESC_SEC)
#define RW_NCNB			(AP_RW|DOMAIN0|NCNB|DESC_SEC)
#define RW_FAULT		(AP_RW|DOMAIN1|NCNB|DESC_SEC)

#define NULL 0

#endif
