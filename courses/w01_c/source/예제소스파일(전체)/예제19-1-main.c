// ���� �̸��� '����19-1-main.c'���� main.c�� �ٲ� ����ϼ���.

#include <stdio.h>     // �ý��� ��� ������ ���� ����
#include "student.h"   // ����� ���� ��� ������ ���� ����

int main(void)
{
	Student a = { 315, "ȫ�浿" };                   // ����ü ���� ����� �ʱ�ȭ

	printf("�й� : %d, �̸� : %s\n", a.num, a.name); // ����ü ��� ���

	return 0;
}
