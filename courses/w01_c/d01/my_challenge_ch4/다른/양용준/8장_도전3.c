#include <stdio.h>

int main(void)
{
	int i=0,j, ary[6], cnt;
	cnt = sizeof(ary)/sizeof(ary[0]);
	int k =1;
	while(k)
	{
		printf("�ζǹ�ȣ �Է� : ");
		scanf("%d",&ary[i]);
		
		for (j=0;j<i;j++)
		{
			if(ary[i]==ary[j])
			{
				printf("���� ��ȣ�� �ֽ��ϴ�.\n");
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
	
	printf("�Էµ� �ζǹ�ȣ : ");
	for (i=0;i<cnt;i++)
	{
		printf("%d ", ary[i]);
	}
}
