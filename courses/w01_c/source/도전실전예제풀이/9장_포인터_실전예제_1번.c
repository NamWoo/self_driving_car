#include <stdio.h>

void func(int *mp, int *rp);

int main(void)
{
	int mod, rem;

	func(&mod, &rem);
	printf("�� : %d, ������ : %d", mod, rem);

	return 0;
}

void func(int *mp, int *rp)
{
	int num;

	printf("��� �Է� : ");
	scanf("%d", &num);

	*mp = num / 4;
	*rp = num % 4;
}