#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile                 // �Ż�� ����ü ����
{
	int age;                   // ����
	double height;             // Ű
};

struct student
{
	struct profile pf;         // profile ����ü�� ����� ���
	int id;                    // �й��� ������ ���
	double grade;              // ������ ������ ���
};

int main(void)
{
	struct student yuni;                     // student ����ü ���� ����

	yuni.pf.age = 17;                        // age ����� ���� ����
	yuni.pf.height = 164.5;                  // height ����� Ű ����
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("���� : %d\n", yuni.pf.age);      // pf ����� age ��� ���
	printf("Ű : %.1lf\n", yuni.pf.height);  // pf ����� height ��� ���
	printf("�й� : %d\n", yuni.id);          // id ��� ���
	printf("���� : %.1lf\n", yuni.grade);    // grade ��� ���

	return 0;
}
