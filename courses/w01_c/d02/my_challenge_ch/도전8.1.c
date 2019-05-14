//20190514
//도전실전예제 도전1 

#include <stdio.h>

int main(void)
{
	int i, s, b, v=0;
	float c;
	int inp[5];

	printf("5명 심사위원의 점수 입력 : ");
	for (i = 0; i < 5; i++)         
	{
		scanf("%d", &inp[i]);
	}
//	int inp[5] = {9,7,4,8,5};
//	scanf("%d %d %d\n", &inp[i]);
	s = inp[0];	
	b = inp[0];
	for (i=1; i<5; i++)	
	{			
		if( s < (inp[i])) // 최대 
		{
			s = inp[i];
		}
		
		if( b > (inp[i])) // 최소 
		{
			b = inp[i];
		}	
	}


	// 유효점수 구하기 
	printf("유효점수 :\t");	
	for (i=0; i<5; i++)	
	{	
		if ((s != inp[i])&&(b != inp[i]))
		{			
			printf("%d\t",inp[i]);
			v = v + inp[i];
		}
	}
	c = v/3.0;
	printf("\n평균 : %.1f", c);

	return 0;

}
