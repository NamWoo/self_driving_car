
void printBit(unsigned char);

int main()
{
    // todo : �ʿ��� ���� ����
    int s, year, major ; 
	unsigned char packed = 0;  // ��Ʈ�� ������ ����

    // todo : �ʿ��� ���� �Է� �ް� packed ������ ��Ʈ�� �����ϴ� �ڵ� �ۼ�
	printf("���� �Է� <��:0, ��:1> : ");
	scanf("%d",&s);
	printf("������ ���� �Է� : ");
	scanf("%d",&year);
	printf("���� ���� �Է� <������:0, ����:1> : ");
	scanf("%d",&major);
	
	packed |= major << 4;
	packed |= year << 1;
	packed |= s;

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

