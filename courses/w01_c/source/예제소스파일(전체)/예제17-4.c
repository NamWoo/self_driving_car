#include <stdio.h>

struct student           // �л� ����ü ����
{
	int id;              // �й�
	char name[20];       // �̸�
	double grade;        // ����
};

int main(void)
{
	struct student s1 = {315, "ȫ�浿", 2.4},     // ����ü ���� ����� �ʱ�ȭ
		           s2 = {316, "�̼���", 3.7},
		           s3 = {317, "�������", 4.4};

	struct student max;                           // �ְ� ������ ������ ����ü ����

	max = s1;                                     // s1�� �ְ� �������� ����
	if (s2.grade > max.grade) max = s2;           // s2�� �� ������ max�� ����
	if (s3.grade > max.grade) max = s3;           // s3�� �� ������ max�� ����

	printf("�й� : %d\n", max.id);                // �ְ� ���� �л��� �й� ���
	printf("�̸� : %s\n", max.name);              // �ְ� ���� �л��� �̸� ���
	printf("���� : %.1lf\n", max.grade);          // �ְ� ���� �л��� ���� ���

	return 0;
}