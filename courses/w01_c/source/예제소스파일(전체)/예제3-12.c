#include <stdio.h>

int main(void)
{
	char grade;              // ������ �Է��� ����
	char name[20];           // �̸��� �Է��� �迭

	printf("���� �Է� : ");
	scanf("%c", &grade);     // grade ������ ���� ���� �Է�
	printf("�̸� �Է� : ");
	scanf("%s", name);       // name �迭�� �̸� ���ڿ� �Է�, &�� ������� ����
	printf("%s�� ������ %c�Դϴ�.\n", name, grade);

	return 0;
}