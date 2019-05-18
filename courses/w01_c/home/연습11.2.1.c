#include <stdio.h>

void main(void)
{
	int ch;
	int cnt= 0;
	
	ch = getchar();
	while(ch != '\n')
	{
		if ((ch>='a')&&(ch<='z')) cnt++;
		ch = getchar();		
	}
	printf("소문자의 갯수%d\n", cnt);
	

	
}
