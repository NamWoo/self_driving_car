#include <stdio.h>

int main(void){
	int a=8;
	int *aa;
	double b;
	char c;
	aa = a;
	
//	*aa = a;
	
//	printf("d%d \t±×³É\n", a);
//	printf("%d\n", &a);
//	printf("%u\n", &a);
//	printf("%x\n", &a);	
//	printf("%p\n", &a);	
	printf("\n");
	printf("%d\n", &aa);
	printf("%u\n", &aa);
	printf("%x\n", &aa);	
	printf("%p\n", &aa);	
	printf("%d\n", aa);
	printf("%u\n", aa);
	printf("%x\n", aa);	
	printf("%p\n", aa);
}
