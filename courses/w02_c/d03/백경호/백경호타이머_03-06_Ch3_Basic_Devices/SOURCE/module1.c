#include "libc.h"

void Func()
{
    static int num;
    num++;
    Uart_Printf("%d\n",num);
}