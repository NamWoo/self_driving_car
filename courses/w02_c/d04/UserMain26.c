//#include "../lib2450/Uart.h"

#include <stdio.h>
// &arr을 넘겨도 arr(&arr[0])이 들어와서 정상적으로 동작함
void To_Lower(char *str)
{
    char c;

    while( c = *str )
    {
        if( 65 <= c && c <= 90 || 
		     97 <= c && c <= 122 )
        {
            *str  |=  1<<5;
        }

        str++;
    }
}

void main()
{
    char arr[] = "TIME FLIES LIKE AN ARROW";

	
    To_Lower( &arr ); // warning

	
	// 정확히는 &arr이 아니라 arr을 인자로 전달해야한다
    printf("%s \n", &arr); // warning
}
