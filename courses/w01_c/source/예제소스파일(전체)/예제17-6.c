#include <stdio.h>

struct children
{
	unsigned int son : 2;                  // �Ƶ� ���� ������ ���
	unsigned int daughter : 2;             // �� ���� ������ ���
	unsigned int pet : 3;                  // �ֿϵ��� ���� ������ ���
};

int main(void)
{
	struct children my = {1, 2, 3};        // ��Ʈ �ʵ� ����ü ���� �ʱ�ȭ
	int sum;

	printf("struct children�� ũ�� : %d����Ʈ\n", sizeof(my));
	sum = my.son + my.daughter + my.pet;   // ����� �� ���
	printf("�ڽ� �� : %d\n", sum);

	return 0;
}