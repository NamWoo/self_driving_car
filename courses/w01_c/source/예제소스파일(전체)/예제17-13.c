#include <stdio.h>

struct student
{
	int num;
	double grade;
};

typedef struct student Student;           // Student������ ������
void print_data(Student *ps);             // �Ű������� Student���� ������

int main(void)
{
	Student s1 = {315, 4.2};              // Student���� ���� ����� �ʱ�ȭ

	print_data(&s1);                      // Student�� ������ �ּ� ����

	return 0;
}

void print_data(Student *ps)
{
	printf("�й� : %d\n", ps->num);       // Student �����ͷ� ��� ����
	printf("���� : %.1lf\n", ps->grade);
}