#include <stdio.h>

void print_line(void);        // �Լ� ����

int main(void)
{
	print_line();             // �Լ� ȣ��
	printf("�й� �̸� ���� ����\n");
	print_line();             // �Լ� ȣ��
	
	return 0;
}

void print_line(void)
{
	int i;

	for (i = 0; i < 50; i++)  // 50�� �ݺ��Ͽ� '-' ���
	{
		printf("-");
	}

	printf("\n");
}