#include <stdio.h>

int main(void)
{
	int age;
	double height;

	printf("���̿� Ű�� �Է��ϼ��� : ");                       // �Է� �ȳ� �޽��� ���
	scanf("%d %lf", &age, &height);                            // ���̿� Ű�� �Բ� �Է�
	printf("���̴� %d��, Ű�� %.1lfcm�Դϴ�\n", age, height);  // �Է°� ���

	return 0;
}