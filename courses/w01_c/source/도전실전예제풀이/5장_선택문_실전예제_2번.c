#include <stdio.h>

int main(void)
{
	int rich = 150;
	double grade = 4.1;
	double pay;

	if(rich < 100)
	{
		pay = 100 * 0.6;
	}
	else if(grade >= 4.0)
	{
		pay = 100 * 0.8;
	}

	printf("���� �б� ������ ��ϱ��� %.0lf�����Դϴ�.\n", pay);

	return 0;
}