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
			printf("���̳ʽ� �Է�\n");
			break;
		}				
		ch = getchar();
	}
	printf("%d", cnt);
	
}
