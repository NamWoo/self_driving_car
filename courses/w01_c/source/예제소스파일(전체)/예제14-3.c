#include <stdio.h>

int main(void)
{
	char animal[5][20];                          // 2���� char �迭 ����
	int i;                                       // �ݺ� ���� ����
	int count;                                   // ���� ���� ������ ����

	count = sizeof(animal) / sizeof(animal[0]);  // ���� �� ���
	for (i = 0; i < count; i++)                  // ���� ����ŭ �ݺ�
	{
		scanf("%s", animal[i]);                  // ���ڿ� �Է�
	}
	for (i = 0; i < count; i++)
	{
		printf("%s, ", animal[i]);               // �Էµ� ���ڿ� ���
	}

	return 0;
}