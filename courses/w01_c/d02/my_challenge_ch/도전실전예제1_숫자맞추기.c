#include <stdio.h>

int main(void)
{
	int ans = 15;
	int num, c = 0;

	while(1)
	{
		printf("숫자 입력 (1부터 30까지) : ");
		scanf("%d", &num);
		c++;
		if(num == ans)
		{
			printf("정답입니다!\n");
			break;
		}
		else if(num < ans)
		{
			printf("%d보다 큽니다!\n", num);
		}
		else if(num > ans)
		{
			printf("%d보다 작습니다!\n", num);
		}
	}
	printf("시도한 횟수는 %d회 입니다.\n", c);

	return 0;
}
