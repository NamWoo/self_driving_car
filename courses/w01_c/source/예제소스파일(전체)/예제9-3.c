#include <stdio.h>

int main(void)
{
	int a = 10, b = 15, tot;   // ���� ����� �ʱ�ȭ
	double avg;                // ����� ������ ����
	int *pa, *pb;              // ������ ���� ����
	int *pt = &tot;            // ������ ����� �ʱ�ȭ
	double *pg = &avg;         // double�� ������ ����� �ʱ�ȭ

	pa = &a;                   // ������ pa�� ���� a�� �ּ� ����
	pb = &b;                   // ������ pb�� ���� b�� �ּ� ����

	*pt = *pa + *pb;           // a���� b���� ���� tot�� ����
	*pg = *pt / 2.0;           // tot���� 2�� ���� ���� avg�� ����

	printf("�� ������ �� : %d, %d\n", *pa, *pb);  // a���� b�� ���
	printf("�� ������ �� : %d\n", *pt);           // tot�� ���
	printf("�� ������ ��� : %.1lf\n", *pg);      // avg�� ���

	return 0;
}