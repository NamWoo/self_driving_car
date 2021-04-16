#include <stdio.h>

int main(void)
{
	int i;
	double ary[5] = {1.0, 2.1, 3.2, 4.3, 5.4};
	
	for(i=4; i>=0; i--)
	{
		printf("%6.1lf", ary[i]);
	}
	return 0;

}
