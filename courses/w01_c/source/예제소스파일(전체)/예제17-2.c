#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile                              // �Ż�� ����ü ����
{
	char name[20];                          // �̸��� ������ �迭 ���
	int age;                                // ����
	double height;                          // Ű
	char *intro;                            // �ڱ�Ұ��� ���� ������
};

int main(void)
{
	struct profile yuni;                    // profile ����ü ���� ����

	strcpy(yuni.name, "������");            // name �迭 ����� �̸� ����
	yuni.age = 17;                          // age ����� ���� ����
	yuni.height = 164.5;                    // height ����� Ű ����

	yuni.intro = (char *)malloc(80);        // �ڱ�Ұ��� ������ ���� ���� �Ҵ�
	printf("�ڱ� �Ұ� : ");
	gets(yuni.intro);                       // �Ҵ��� ������ �ڱ�Ұ� �Է�
	 
	printf("�̸� : %s\n", yuni.name);       // �� ����� ������ ���
	printf("���� : %d\n", yuni.age);
	printf("Ű : %.1lf\n", yuni.height);
	printf("�ڱ�Ұ� : %s\n", yuni.intro);
	free(yuni.intro);                       // ���� �Ҵ� ���� ��ȯ

	return 0;
}