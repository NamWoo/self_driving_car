// 8장 배열 도전 실전 예제 3번

#include <stdio.h>

int main(void)
{
	int ary[6];
	int inp;
	int c = 0;
	int i;
	int dup;

	c = 0;
	while(c < 6)
	{
		printf("로또번호 입력 : ");
		scanf("%d", &inp);
		dup = 0;
		for(i=0; i<c; i++)
		{
			if(inp == ary[i])
			{
				dup = 1;
				break;
			}
		}
		if(dup == 0)
		{
			ary[c] = inp;
			c++;
		}
		else
		{
			printf("같은 번호가 있습니다!\n");
		}
	}

	printf("입력된 로또번호 : ");
	for(i=0; i<6; i++)
	{
		printf("%5d", ary[i]);
	}

	return 0;
}