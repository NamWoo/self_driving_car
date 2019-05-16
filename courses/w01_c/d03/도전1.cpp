#include <stdio.h>

void rotate(int *pa,int *pb, int *pc){

int r;

r=*pa;
*pa=*pb;
*pb=*pc;
*pc=r;

}

int main(){

	int a=1,b=2,c=3;
	char flag;
	
	printf("%d:%d:%d",a,b,c);
	while(1){
	
	scanf("%c",&flag);
	if(flag!=10)
		break;
	rotate(&a,&b,&c);
	printf("%d:%d:%d",a,b,c);

	}
	
	return 0;
}
