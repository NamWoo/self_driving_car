#include "2450addr.h"
#include "libc.h"

void Init(void);
void LED_ON_Off(int num);
int Get_Key_byPolling(void);

void TestKeyLogger()
{
    int key;
    Init();

    rGPFDAT &= ~(0x1 << 7); // switch 7 data on
    rGPFDAT &= ~(0x1);      //swtich 0 data on;

    while (1)
    {
        
        key = Get_Key_byPolling();

        Uart_Printf("Key :%x,  LED : %x , KEY : %x, KEY CON : %x\n", key, rGPGDAT , rGPFDAT, rGPFCON);
        LED_ON_Off(key);
    }
}

void Init()
{
    //init led
    rGPGCON |= 0x5500;
    rGPGDAT |= 0xf0;

    //init switch (reserve)
    rGPFCON |= 0xffff;
    rGPFCON &= ~(0x3ff << 4);
    Uart_Printf("Init switch reserve : %x\n",rGPFCON);

    //set  switch 7 output
    rGPFCON &= ~(0x2 << 14);
    Uart_Printf("Init switch 7 to output: %x\n",rGPFCON);

    //set  swtch 0  output
    // rGPFCON &= ~(0xf);
    // rGPFCON &= ~(0xf);
    // rGPFCON |= 0x1;

    // ????? 이거를해야 모든 키가 다 써짐... 뭐지?
    rGPGCON |= 0x1;

    Uart_Printf("Init switch 0 to output : %x\n",rGPFCON);


    
}
void LED_ON_Off(int num)
{
    rGPGDAT |= 0xf0;
    switch (num)
    {
    case 0:
        rGPGDAT &= (0xf0); // ---- idle
        break;
    case 1:
        rGPGDAT &= (0xe0); // ---0 4
        break;
    case 2:
        rGPGDAT &= (0xd0); // --0- 3
        break;
    case 3:
        rGPGDAT &= (0xb0); // -0-- 2
        break;
    case 4:
        rGPGDAT &= (0x70); // 0--- 1
        break;
    case 5:
        rGPGDAT &= (0x30); // 00--
        break;
    }
}

int Get_Key_byPolling(void)
{
    if ((rGPFDAT & 0x7) == 0x3) //4  --> 1110 
        return 1;
    if ((rGPFDAT & 0xf) == 0x7) //3 --> 
        return 2;
    if ((rGPFDAT & 0x1f) == 0xf) //2
        return 3;
    if ((rGPFDAT & 0x3f) == 0x1f) //1
        return 4;
    if ((rGPFDAT & 0x7f) == 0x3f) //5
        return 5;
    return 0;
}
