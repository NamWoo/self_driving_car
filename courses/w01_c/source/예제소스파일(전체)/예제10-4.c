#include <stdio.h>

int main(void)
{
	int ary[3] = {10, 20, 30};
	int *pa = ary;
	int i;

	printf("�迭�� �� : ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", *pa);  // pa�� ����Ű�� �迭 ��� ���
		pa++;                // ���� �迭 ��Ҹ� ����Ű���� pa�� ����
	}

	return 0;
}