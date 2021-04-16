#include "../lib2450/Uart.h"

void User_Main()
{
    int width, height;
	double area;
	
	width = 3;
	height = 4;
	
	area = 1 / 2 * width * height;
	Uart_Printf("1st] area : %lf \n", area);
	
	/* 제대로된 결과를 얻기 위한 수식 작성 */
	area = (double)1 / 2 * width * height;
	area = 1 / (double)2 * width * height;
	area = (double)1 / (double)2 * width * height;
	area = 1.0 / 2 * width * height;
	area = 1 / 2.0 * width * height;
	area = 1.0 / 2.0 * width * height;
	area = 0.5 * width * height;
	
	Uart_Printf("2nd] area : %lf \n", area);
}