
void printBit(unsigned char);

int main()
{
    // todo : �ʿ��� ���� ����
	unsigned char packed = 0;  // ��Ʈ�� ������ ����
	int work_year;
	int major;
	char gender;
	
	gender = 1;
	work_year = 3;
	major = 0;
	
	printf("���� �Է� (��:M, ��:W): ")
	scanf("%c", &gender);
	printf("�������� ���� �Է� : ")
	printf("���� �Է� (��:M, ��:W): ")
	
������ ���� �Է� : 4
���� ���� �Է� (������:0, ����:1): 1

	packed |= ((gender == 'M') ? 0 : 1) ;
	packed |= work_year << 1;
	packed |= major << 4;
	
	
	

	printBit(packed);          // ������ ��Ʈ ����Ʈ�غ���


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

