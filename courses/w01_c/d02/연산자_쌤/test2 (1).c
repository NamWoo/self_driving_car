/*
 * test2.c
 *
 *  Created on: 2015. 2. 9.
 *      Author: elayer
 */

#include "test.h"

#ifdef TEST2
void printBit(unsigned char);

int main()
{
	int a;
	unsigned char packed = 0;
	printf("성별 입력 (남:0, 여:1): "); OUT;
	scanf("%d", &a);

	packed |= (a & 0x1);

	printf("연구원 연차 입력 : "); OUT;
	scanf("%d", &a);

	packed |= ((a<<1) & 0xe);

	printf("전공 여부 입력 (비전공:0, 전공:1): "); OUT;
	scanf("%d", &a);

	packed |= ((a<<4) & 0x10);

	printBit(packed);

	return 0;
}

void printBit(unsigned char num)
{
    unsigned char mask = 0x01;
    int i=0;
    for(i=7; i>=0 ; i--)
	{
		if((mask << i) & num)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

#endif
