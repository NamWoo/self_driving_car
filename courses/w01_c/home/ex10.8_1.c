#include <stdio.h>

void input_ary(double *pa, int size);
double find_max(double *pa, int size);

void main(void)
{	
	double ary[5];
	double max;
	int size = sizeof(ary)/sizeof(double);
	int i;
	printf("%d\n", size);
//	float *pa[10]=[10,20,30,40,50];	

	input_ary(ary, size);
	
	max = find_max(ary, size);

	
//	printf("%f", ary[0]);
//	printf("%f",find_max());
	return 0;
}


void input_ary(double *pa,int size)
{
	int i;
	
	for (i=0; i<size; i++)
	{		
		scanf("%lf", pa + i);
	}
	

}

double find_max(double *pa,int size)
{	
	int i;
	for (i=0; i<size; i++)
	{
		printf("a %lf\n", pa[i]);
	}
	
}
