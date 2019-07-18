#include <stdio.h>

void main(void)
{
	char ch;
	int cnt=0;
	
	
	ch = getchar();
	
	while(ch!='\n')
	{
		if ((ch>='a')&&(ch<='z'))
		{
			cnt++;					
		}
		else if (ch==EOF)
		{
			printf("마이너스 입력\n");
			break;
		}				
		ch = getchar();
	}
	printf("%d", cnt);
	
}
