#include <stdio.h>

int main(void)
{
	int ary[3];
	int i;

	*(ary + 0) = 10;                // ary[0] = 10
	*(ary + 1) = *(ary + 0) + 10;   // ary[1] = ary[0] + 10

	printf("�� ��° �迭 ��ҿ� Ű���� �Է� : ");
	scanf("%d", ary + 2);           // &ary[2]

	for (i = 0; i < 3; i++)         // ��� �迭 ��� ���
	{
		printf("%5d", *(ary + i));  // ary[i]
	}

	return 0;
}