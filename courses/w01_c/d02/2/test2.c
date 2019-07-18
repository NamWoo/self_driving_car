
void printBit(unsigned char);

int main()
{
    // todo : 필요한 변수 선언
	unsigned char packed = 0;  // 비트를 셋팅할 변수

    // todo : 필요한 값을 입력 받고 packed 변수에 비트를 셋팅하는 코드 작성

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

