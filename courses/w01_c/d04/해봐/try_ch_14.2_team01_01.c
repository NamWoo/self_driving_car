#include<stdio.h>

void main(void)
{
	int i,j, si=0, sj=0, cnt=0;
	
	int pi=5, pj=4;
	
	for (i=1; i<pi+2; i++)
	{
		printf("За%d ",i);		
		
		for (j=1; j<pj+2; j++)
		{
			printf("ї­%d ",j);
			cnt+=j;	
//			printf("\n%d", cnt);
		}
		si += cnt;
		printf("\n%d", si);
		printf("\n");
		
	}
//	printf("%d",cnt);
	return 0;
}

