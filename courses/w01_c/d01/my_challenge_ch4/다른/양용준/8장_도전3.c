#include <stdio.h>

int main(void)
{
	int i=0,j, ary[6], cnt;
	cnt = sizeof(ary)/sizeof(ary[0]);
	int k =1;
	while(k)
	{
		printf("로또번호 입력 : ");
		scanf("%d",&ary[i]);
		
		for (j=0;j<i;j++)
		{
			if(ary[i]==ary[j])
			{
				printf("같은 번호가 있습니다.\n");
				i=i-1;
				break;
			}
		}
		i+=1;
		if (cnt<=i)
		{
			k=0;
		}
	
	}
	
	printf("입력된 로또번호 : ");
	for (i=0;i<cnt;i++)
	{
		printf("%d ", ary[i]);
	}
}
