/*
 * =====================================================================
 * NAME         : Uart.c
 * Descriptions : Uart Test Driver
 * IDE          : GCC-4.1.0
 * Modification : Seonghye, Son (2015.07.10)
 *	 
 * =====================================================================
 */
#include "2450addr.h"
#include "stdarg.h"
#include "option.h"

// Function Declaration
void Uart_Init(int baud);
void Uart_Printf(const char *fmt,...);
void Uart_Send_String(char *pt);
void Uart_Send_Byte(int data);

char Uart_GetChar(void);

extern int vsprintf(char *, const char * , va_list);

void Uart_Init(int baud)
{
	int pclk;
	pclk = PCLK;
	
	// PORT GPIO initial
	rGPHCON &= ~(0xf<<4);
	rGPHCON |= (0xa<<4);	

	
	rUFCON1 = 0x0;
	rUMCON1 = 0x0;
	
	/* Line Control(Normal mode, No parity, One stop bit, 8bit Word length */
	rULCON1 = 0x3;

	/* Transmit & Receive Mode is polling mode  */
	rUCON1  = (1<<2)|(1);

	/* Baud rate 설정  */		
	rUBRDIV1= ((unsigned int)(PCLK/16./baud+0.5)-1 );
}

void Uart_Printf(const char *fmt,...)
{
    va_list ap;
    char string[256];

    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    Uart_Send_String(string);
    va_end(ap);
}

void Uart_Send_String(char *pt)
{
    while((*pt)!='\0')
    {
        Uart_Send_Byte(*pt);
        pt++;
    }
}

void Uart_Send_Byte(int data)
{
    if(data=='\n')
    {
        while(!(rUTRSTAT1 & 0x2));
        WrUTXH1('\r');
    }

    while(!(rUTRSTAT1 & 0x2));	
    WrUTXH1(data);
}

char Uart_GetChar(void)
{
    /* UTRSTAT1의 값을 확인하여 문자열 입력   */	
    while(!(rUTRSTAT1 & 0x1));	
    return RdURXH1();
}

char Uart_Get_Pressed(void)
{
    if(rUTRSTAT1 & 0x1)
    {
        return RdURXH1();
    }
    else return 0;
}

/* 
 * void Uart_TxEmpty(int ch)
 * -----------------------------------------------------------------
 */
void Uart_TxEmpty(int ch)
{
    while(!(rUTRSTAT1 & 0x4)); //Wait until tx shifter is empty.
}

/* 
 * char Uart_GetKey(void)
 * -----------------------------------------------------------------
 */
char Uart_GetKey(void)
{
    if(rUTRSTAT1 & 0x1)    //Receive data ready
        return RdURXH1();
    else
        return 0;
}

/*
 * =====================================================================
 * UART Librarues
 * =====================================================================
 */
/* 
 * int Uart_GetString(char *string, int leng)
 * -----------------------------------------------------------------
 */
int Uart_GetString(char *string, int leng)
{
    char *string2 = string;
    char c;
    while(leng && ((c = Uart_GetChar())!='\r'))
    {
        if(c=='\b')
        {
            if( (int)string2 < (int)string )
            {
                Uart_Printf("\b \b");
                string--;
                leng++;
            }
        }
        else
        {
            *string++ = c;
            leng--;
            Uart_Send_Byte(c);
        }
    }
    if(leng == 0) {
           Uart_Printf("\nThe string is full. Try again.\n");
           return 1;
    }
           
    *string='\0';
    Uart_Send_Byte('\n');
    return 0;
}

// A simple atoi() function
int atoi(char *str)
{
    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit
     
    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;  
        i++;  // Also update index of first digit
    }
     
    // Iterate through all digits and update the result
    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
   
    // Return result with sign
    return sign*res;
}

int strlen(const char *str)
{
        const char *s;

        for (s = str; *s; ++s)
                ;
        return (s - str);
}

/* 
 * int Uart_GetIntNum(void)
 * -----------------------------------------------------------------
 */
int Uart_GetIntNum(void)
{
    char str[30];
    char *string = str;
    int base     = 10;
    int minus    = 0;
    int result   = 0;
    int lastIndex;    
    int i;
    
    while(Uart_GetString(string, 30)) {}
    
    if(string[0]=='-')
    {
        minus = 1;
        string++;
    }
    
    if(string[0]=='0' && (string[1]=='x' || string[1]=='X'))
    {
        base    = 16;
        string += 2;
    }
    
    lastIndex = strlen(string) - 1;
    
    if(lastIndex<0)
        return -1;
    
    if(string[lastIndex]=='h' || string[lastIndex]=='H' )
    {
        base = 16;
        string[lastIndex] = 0;
        lastIndex--;
    }

    if(base==10)
    {
        result = atoi(string);
        result = minus ? (-1*result):result;
    }
    else
    {
        for(i=0;i<=lastIndex;i++)
        {
            if(('A' <= string[i]) && (string[i] <= 'Z'))        // upper case
                    result = (result<<4) + string[i] - 'A' + 10;
            else if(('a' <= string[i]) && (string[i] <= 'z'))   // lower case
                    result = (result<<4) + string[i] - 'a' + 10;
            /*if(isalpha(string[i])
            {
                if(isupper(string[i]))
                    result = (result<<4) + string[i] - 'A' + 10;
                else
                    result = (result<<4) + string[i] - 'a' + 10;
            }*/
            else 
                result = (result<<4) + string[i] - '0';
        }
        result = minus ? (-1*result):result;
    }
    return result;
}