#include <stdio.h>

int sum(int, int);                 // �Լ� ����

int main(void)
{
	int(*fp)(int, int);            // �Լ� ������ ����
	int res;                       // ��ȯ���� ������ ����

	fp = sum;                      // �Լ����� �Լ� �����Ϳ� ����
	res = fp(10, 20);              // �Լ� �����ͷ� �Լ� ȣ��
	printf("result : %d\n", res);  // ��ȯ�� ���

	return 0;
}

int sum(int a, int b)
{
	return (a + b);
}