#include <stdio.h>

int main(void)
{
	int ary[5]={0,0,0,0,0};
	int temp;
	int i, j;
	int sum=0;
	double ave;
	
	printf("5명 심사위원의 점수 입력 : ");
	
	for(i=0; i<5; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if (ary[i] > ary[j])
			{
			temp = ary[j];
			ary[j]=ary[i];
			ary[i] = temp;
			}	
		}
	}
	
	printf("유효점수 : ");
	
	for(i=1; i<4; i++)
	{
		printf("%d ", ary[i]);
	}
	
	printf("\n평균 : ");
	
	for(i=1; i<4; i++)
	{
		sum += ary[i];
	}
	
	ave = sum / 3.0;
	
	printf("%.1lf",ave);
	
	return 0;
}
