#include <stdio.h>

void assign10(void);
void assign20(void);

int a;                                     // ���� ���� ����

int main(void)
{
	printf("�Լ� ȣ�� �� a�� : %d\n", a);  // ���� ���� a ���

	assign10();
	assign20();

	printf("�Լ� ȣ�� �� a�� : %d\n", a);  // ���� ���� a ���

	return 0;
}

void assign10(void)
{
	a = 10;                                // ���� ���� a�� 10 ����
}

void assign20(void)
{
	int a;                                 // ���� ������ ���� �̸��� ���� ���� ����

	a = 20;                                // ���� ���� a�� 20 ����
}