#include <stdio.h>

int add(int x, int y);   // add �Լ� ����

int main(void)           // main �Լ� ����
{
	int a = 10, b = 20;
	int res;

	res = add(a, b);     // add �Լ� ȣ��
	printf("result : %d\n", res);

	return 0;
}                        // main �Լ��� ��

int add(int x, int y)    // add �Լ� ���� ����
{
	int temp;            // �� ������ ���� ��� ������ ����

	temp = x + y;        // x�� y�� ���� temp�� ����

	return temp;         // temp�� ���� ��ȯ
}                        // add �Լ��� ��