#include <stdio.h>

void print_ary(int *ary);

int main(void)
{
	int ary[6] = {10,30,50,60,80,100};

	print_ary(ary);
}

void print_ary(int *ary)
{
	int i, s;
	s = sizeof(*ary)/sizeof(int);
	printf("sizeof(ary)=%d\n",ary);
	printf("sizeof(*ary)=%d\n",*ary);
	printf("sizeof(ary[0])=%d\n",ary[0]);
	printf("sizeof(s)=%d\n",s);
	printf("sizeof(int)=%d\n",sizeof(int));
	
	for (i=0; i<s; i++)
	{
		printf("%d ", ary[i]);
	}	
}
