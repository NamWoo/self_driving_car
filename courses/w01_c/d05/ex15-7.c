//예제 15-7

#include <stdio.h>

int sum(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void)
{
	int(*fp)(int, int);
	int res;

	fp = sum;
	res = fp(10,20);
	
	fp = sub;
	res = fp(10,20);	
	
	fp = mul;
	res = fp(10,20);	
	
	fp = div;
	res = fp(10,20);

	return 0;
}

int sum(int a, int b)
{
	int temp;
	temp = (a+b);
	printf("result : %d\n",temp);
	return temp;
}

int sub(int a, int b)
{
	int temp;
	temp = (a-b);
	printf("result : %d\n",temp);
	return temp;
}
int mul(int a, int b)
{
	int temp;
	temp = (a*b);
	printf("result : %d\n",temp);
	return temp;
}
int div(int a, int b)
{
	int temp;
	temp = (a%b);
	printf("result : %d\n",temp);
	return temp;
}
