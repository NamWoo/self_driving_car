#include <stdio.h>

struct student                           // ����ü ����
{
	int num;                             // int�� ���
	double grade;                        // double�� ���
};                                       // �����ݷ� ���

int main(void)
{
	struct student s1;                   // struct student���� ���� ����
	s1.num = 2;                          // s1�� num ����� 2 ����
	s1.grade = 2.7;                      // s1�� grade ����� 2.7 ����

	printf("�й� : %d\n", s1.num);       // num ��� ���
	printf("���� : %.1lf\n", s1.grade);  // grade ��� ���

	return 0;
}