#include<stdio.h>

void printBit(unsigned char);

int main()
{
    // todo : 필요한 변수 선언
	unsigned char packed = 0;  // 비트를 셋팅할 변수
	int gender, annual, major;
    // todo : 필요한 값을 입력 받고 packed 변수에 비트를 셋팅하는 코드 작성

	printf("성별 입력(남:0, 여:1) : ");
	scanf("%d",&gender);
	printf("연구원 연차 입력 : ");
	scanf("%d",&annual);
	printf("전공 여부 입력 (비전공:0, 전공:1) : ");
	scanf("%d",&major);
	
	packed |= gender;
	//packed = packed | gender;
	//printBit(packed);
	packed |= annual << 1;
	//printBit(packed);
	packed |= major<< 4;
	
	printBit(packed);          // 셋팅한 비트 프린트해보기


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

