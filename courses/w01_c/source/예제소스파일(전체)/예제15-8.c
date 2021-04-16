#include <stdio.h>

void func(int(*fp)(int, int));       // �Լ� �����͸� �Ű������� ���� �Լ�
int sum(int a, int b);               // �� ������ ���ϴ� �Լ�
int mul(int a, int b);               // �� ������ ���ϴ� �Լ�
int max(int a, int b);               // �� ���� �߿� ū ���� ���ϴ� �Լ�

int main(void)
{
	int sel;                         // ���õ� �޴� ��ȣ�� ������ ����

	printf("1. �� ������ ��\n");     // �޴� ���
	printf("2. �� ������ ��\n");
	printf("3. �� ���� �߿��� ū �� ���\n");
	printf("���ϴ� �۾��� �����ϼ��� : ");
	scanf("%d", &sel);               // �޴� ��ȣ �Է�

	switch (sel)
	{
	case 1: func(sum); break;        // 1�̸� func�� ���� ��� �߰�
	case 2: func(mul); break;        // 2�̸� func�� ���� ��� �߰�
	case 3: func(max); break;        // 3�̸� func�� ū �� ���ϴ� ��� �߰�
	}

	return 0;
}

void func(int(*fp)(int, int))
{
	int a, b;                        // �� ������ ������ ����
	int res;                         // �Լ��� ��ȯ���� ������ ����

	printf("�� �������� �Է��ϼ��� : ");
	scanf("%d %d", &a, &b);          // �� ���� �Է�
	res = fp(a, b);                  // �Լ� �����ͷ� ����Ű�� �Լ��� ȣ��
	printf("������� : %d\n", res);  // ��ȯ�� ���
}

int sum(int a, int b)                // ���� �Լ�
{
	return (a + b);
}

int mul(int a, int b)                // ���� �Լ�
{
	return (a * b);
}

int max(int a, int b)                // ū ���� ���ϴ� �Լ�
{
	if (a > b) return a;
	else return b;
}