#include <stdio.h>

int main(void)
{
	int a = 20, b = 10;

	if (a > 10)          // a가 10보다 크면 9~16행 실행, 작거나 같으면 18행으로 이동
	{
		if (b >= 0)      // b가 0 이상이면 b에 1 대입하고 18행으로 이동
		{
			b = 1;
		}
		else
		{
			b = -1;      // b가 0보다 작으면 b에 -1 대입하고 18행으로 이동
		}
	}

	printf("a : %d, b : %d\n", a, b);

	return 0;
}