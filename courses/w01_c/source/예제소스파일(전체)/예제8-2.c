#include <stdio.h>

int main(void)
{
	int ary1[5] = {1, 2, 3, 4, 5};               // int�� �迭 �ʱ�ȭ
	int ary2[5] = {1, 2, 3};                     // �ʱ갪�� ���� ���
	int ary3[] = {1, 2, 3};                      // �迭 ��� ������ ������ ���
	double ary4[5] = {1.0, 2.1, 3.2, 4.3, 5.4};  // double�� �迭 �ʱ�ȭ
	char ary5[5] = {'a', 'p', 'p', 'l', 'e'};    // char�� �迭 �ʱ�ȭ

	ary1[0] = 10;
	ary1[1] = 20;
	ary1[2] = 30;
	ary1[3] = 40;
	ary1[4] = 50;

	return 0;
}