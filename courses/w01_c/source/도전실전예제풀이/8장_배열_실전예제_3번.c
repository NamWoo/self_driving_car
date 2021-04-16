// 8장 배열 도전 실전 예제 3번

#include <stdio.h>

int main(void)
{
	int lotto[6];
	int num;
	int cnt = 0;
	int i;
	int dup;

	cnt = 0;
	while(cnt < 6)
	{
		printf("로또번호 입력 : ");
		scanf("%d", &num);
		dup = 0;
		for(i=0; i<cnt; i++)
		{
			if(num == lotto[i])
			{
				dup = 1;
				break;
			}
		}
		if(dup == 0)
		{
			lotto[cnt] = num;
			cnt++;
		}
		else
		{
			printf("같은 번호가 있습니다!\n");
		}
	}

	printf("입력된 로또번호 : ");
	for(i=0; i<6; i++)
	{
		printf("%5d", lotto[i]);
	}

	return 0;
}