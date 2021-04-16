#include <stdio.h>

void rotate(int *pa, int *pb, int *pc);

int main(void)
{
	int a=1, b=2, c=3;
	int i, j, k;
	int flag;
	
	printf("%d %d %d", a, b, c);
	while(1)
	{
		scanf("%c", &flag);
		if(flag != '\n')
			break;
		
		
		rotate(&a,&b,&c);
		printf("%d %d %d", a, b, c);
	}	
	return 0;
}


void rotate(int *pa,int *pb, int *pc){

int temp;

temp = *pa; //a 
*pa = *pb; //b = a 
*pb = *pc; //c = b
*pc = temp; //a = c

}
