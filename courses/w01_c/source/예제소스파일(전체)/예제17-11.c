#include <stdio.h>

union student                            // ����ü ����
{
	int num;                             // �й��� ������ ���
	double grade;                        // ������ ������ ���
};

int main(void)
{
	union student s1 = {315};            // ����ü ������ ����� �ʱ�ȭ

	printf("�й� : %d\n", s1.num);       // �й� ��� ���
	s1.grade = 4.4;                      // ���� ����� �� ����
	printf("���� : %.1lf\n", s1.grade);
	printf("�й� : %d\n", s1.num);       // �й� �ٽ� ���

	return 0;
}