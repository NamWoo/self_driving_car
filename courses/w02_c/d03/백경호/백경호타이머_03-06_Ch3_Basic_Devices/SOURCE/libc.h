/*
 * =====================================================================
 * NAME         : libc.h
 *
 * Descriptions : Definition of S3C2450 Library prototype
 *
 * IDE          : GCC-4.1.0
 *
 * Modification
 *	   
 * =====================================================================
 */
#ifndef __LIBC_H__
#define __LIBC_H__

extern void MemFill(unsigned long ptr, unsigned long pattern, int size);
extern void MemDump(unsigned long ptr, int size);

// Uart 관련 함수 
extern void Uart_Init(int baud);
extern void Uart_Printf(char *fmt,...);
extern void Uart_Send_String(char *pt);
extern void Uart_Send_Byte(int data);
extern char Uart_Get_Char();

// LED 관련 함수 
extern void Led_Init();
extern void Led_Display(int data);

// Timer 관련 함수 
extern void Timer_Init(void);
extern void Timer_Delay(int msec);

#endif
