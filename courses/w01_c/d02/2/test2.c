
void printBit(unsigned char);

int main()
{
    // todo : �ʿ��� ���� ����
	unsigned char packed = 0;  // ��Ʈ�� ������ ����

    // todo : �ʿ��� ���� �Է� �ް� packed ������ ��Ʈ�� �����ϴ� �ڵ� �ۼ�

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

