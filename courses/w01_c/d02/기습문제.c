#include <stdio.h>

int get_pos(void);                 // 함수 선언

int main(void)
{
	int i;

	for(i=0;i<=11;i++)
	{
//		printf("%d\n",i%2);
		if(i%2) continue;
			
		printf("%d",i);
	}

	return 0;
}


