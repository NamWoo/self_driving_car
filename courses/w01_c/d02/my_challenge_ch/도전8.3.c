//20190514
//도전실전예제 도전3 로또프로그램

#include <stdio.h>

int main(void)
{
	int ary[6];
	int inp, flag, i, c = 0;

	c = 0;
	while(c < 6)
	{
		printf("로또번호 입력 : ");
		scanf("%d", &inp);
		flag = 0;
		for(i=0; i<c; i++)
		{
			if(inp == ary[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
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
		printf("%3d", ary[i]);
	}

	return 0;
}
