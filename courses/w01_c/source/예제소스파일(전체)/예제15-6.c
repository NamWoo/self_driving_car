#include <stdio.h>

void print_ary(int(*)[4]);

int main(void)
{
	int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

	print_ary(ary);                    // �迭���� �μ��� �ְ� �Լ� ȣ��

	return 0;
}

void print_ary(int(*pa)[4])            // �Ű������� �迭 ������
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pa[i][j]);   // pa�� 2���� �迭ó�� ���
		}
		printf("\n");
	}
}
