#include <stdio.h>

int main(void)
{
	char ary[10];
	int ch;
	int weight = 1;
	int tot = 0;
	int i = 0;
	
	while((ch = getchar()) != '\n')
	{
		ary[i++] = ch;
	}
	
	while(i > 0)
	{
		tot += ((ary[--i] - '0') * weight);
		weight *= 10;
	}

	printf("%d\n", tot + 9);

	return 0;
}
