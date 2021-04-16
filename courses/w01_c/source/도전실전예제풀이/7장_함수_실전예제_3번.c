#include <stdio.h>

int prime_check(int n);

int main(void)
{
	int num;
	int i;
	int cnt;

	printf("# 양수 입력 : ");
	scanf("%d", &num);

	for (i = 2, cnt = 0; i <= num; i++)
	{
		if (prime_check(i) == 1)
		{
			printf("%5d", i);
			cnt++;
			if ((cnt % 5) == 0)
			{
				printf("\n");
			}
		}
	}

	return 0;
}

int prime_check(int n)
{
	int i;

	for(i = 2; i < n; i++)
	{
		if((n % i) == 0)
		{
			return 0;
		}
	}

	return 1;
}
