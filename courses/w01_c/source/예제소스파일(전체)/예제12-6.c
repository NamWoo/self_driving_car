#include <stdio.h>

int main(void)
{
	int age;                  // ���̸� ������ ����
	char name[20];            // �̸��� ������ �迭

	printf("���� �Է� : ");
	scanf("%d", &age);        // ���� �Է�
	printf("�̸� �Է� : ");
	gets(name);               // �̸� �Է�
	printf("���� : %d, �̸� : %s\n", age, name);

	return 0;
}