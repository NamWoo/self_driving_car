#include <stdio.h>

int main(void)
{
	int ary[5], cnt, max, min, i, cnt_num;
	double sum;
	printf("5명 심사위원의 점수 입력 :");
	scanf("%d%d%d%d%d",&ary[0],&ary[1],&ary[2],&ary[3],&ary[4]);
	cnt = sizeof(ary)/sizeof(ary[0]);
	
	max = ary[0];
	min = ary[0];
	for (i=0;i<cnt-1;i++)
	{
		if (max<ary[i+1])
		{
			max = ary[i+1];
		}
		
		if (min>ary[i+1])
		{
			min = ary[i+1];
		}
	}
	
	printf("유효점수 : ");
	sum=0;
	cnt_num=0;
	for (i=0;i<cnt;i++)
	{
		if((max!=ary[i]) && (min!=ary[i]))
		{
			printf("%d ",ary[i]);
			sum += ary[i];
			cnt_num += 1;
		}
		
	}
	printf("\n");
	printf("평균 : %.1lf", sum/cnt_num);
	
	return 0;
}
