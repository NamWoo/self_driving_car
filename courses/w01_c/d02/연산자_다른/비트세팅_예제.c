#include<stdio.h>

void printBit(unsigned char);

int main()
{
    // todo : �ʿ��� ���� ����
	unsigned char packed = 0;  // ��Ʈ�� ������ ����
	int gender, annual, major;
    // todo : �ʿ��� ���� �Է� �ް� packed ������ ��Ʈ�� �����ϴ� �ڵ� �ۼ�

	printf("���� �Է�(��:0, ��:1) : ");
	scanf("%d",&gender);
	printf("������ ���� �Է� : ");
	scanf("%d",&annual);
	printf("���� ���� �Է� (������:0, ����:1) : ");
	scanf("%d",&major);
	
	packed |= gender;
	//packed = packed | gender;
	//printBit(packed);
	packed |= annual << 1;
	//printBit(packed);
	packed |= major<< 4;
	
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

