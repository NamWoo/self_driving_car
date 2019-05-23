#include "LibA.h"

void LibFunc( void (*pFunc)(void) )
{
    //...

    // 인자로 받은 함수포인터로 함수를 대신 호출
    // 인자로 넘어올 함수의 구현이 아직 결정되지 않음
    pFunc();
}