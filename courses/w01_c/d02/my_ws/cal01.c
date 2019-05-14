//20190514
//ws
#include <stdio.h>

int main(void)
{
	int i, year = 2018, year_s=0, mth=5, mth_s=0, ini= 0, j,k,l=0,o;
	int mth_ini1[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int mth_ini2[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int mth_inter[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

// 1년 1월 1일부터 입력년도의 전년도 12월 말까지 총 일수 계산 
	for (i=1; i<year; i++) 
	{		
		if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
		    ini = 366 + ini; 
		else
			ini = 365 + ini; 
	}
	year_s = ini;
	ini = 0;
	
// 입력년도 1월 1일부터 입력 월 1일까지 총 일 수 계산
	for (i=1; i<mth-1; i++)
	{				
		if ((mth % 4 == 0) && ((mth % 100 != 0) || (mth % 400 == 0)))
		    ini = ini + mth_inter[i];
		else
			ini = ini + mth_ini2[i];
	}
	mth_s = ini;
	ini = 0;
	
//	printf("%d", (year_s));
	printf("%d", ((year_s+mth_s+1)%7));
	printf("\n");
	printf("%20d년%8d월\n", year,mth);
	printf("            %20======================        \n");
	printf("-------------------------------------------------------------\n");
	printf("      sun    mon    tue    wed    thu    fri    sat\n");
	printf("-------------------------------------------------------------\n");
	
//	printf("    "); // 
	for (i=0; i<((year_s+mth_s+1)%7); i++)
	{
		printf("\t");
	}
	
	for (i=((year_s+mth_s+1)%7); i<mth_ini2[mth]+1; i++) // 시작점 
	{
//		printf("%d", i);
		if (i%7 == 0)
		{
			printf("\n");
		}
		
		l = 1 + l;
		printf("%8d", l);
//		printf("   ");
//		printf("\n");
	}



//	for (i=7; i<30; i++) 
//	{
//		printf("%d", i);
//		if (i%7 == 0)
//		{
//			printf("\n");
//		}		
////		l += 1;
//	}
//	for (j=2; j<6; j++)
//	{
//		printf(" %d", j);
//	}
//	for (i=1; i<year; i++)
//	{
//		
//		
//
//	}
//	for(i=1; i<inyear; i++)
//	{
//		printf("%6.1lf", ary[i]);
//	}
	return 0;
}



