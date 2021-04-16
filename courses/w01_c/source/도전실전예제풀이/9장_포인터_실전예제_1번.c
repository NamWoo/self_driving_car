#include <stdio.h>

void func(int *mp, int *rp);

int main(void)
{
	int mod, rem;

	func(&mod, &rem);
	printf("몫 : %d, 나머지 : %d", mod, rem);

	return 0;
}

void func(int *mp, int *rp)
{
	int num;

	printf("양수 입력 : ");
	scanf("%d", &num);

	*mp = num / 4;
	*rp = num % 4;
}