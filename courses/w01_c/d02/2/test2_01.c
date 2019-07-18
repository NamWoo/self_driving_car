
void printBit(unsigned char);

int main()
{
    // todo : 필요한 변수 선언
	unsigned char packed = 0;  // 비트를 셋팅할 변수
	int work_year;
	int major;
	char gender;
	
	gender = 1;
	work_year = 3;
	major = 0;
	
	printf("성별 입력 (남:M, 여:W): ")
	scanf("%c", &gender);
	printf("성연구원 연차 입력 : ")
	printf("성별 입력 (남:M, 여:W): ")
	
연구원 연차 입력 : 4
전공 여부 입력 (비전공:0, 전공:1): 1

	packed |= ((gender == 'M') ? 0 : 1) ;
	packed |= work_year << 1;
	packed |= major << 4;
	
	
	

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

