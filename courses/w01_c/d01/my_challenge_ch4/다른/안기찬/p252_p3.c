#include <stdio.h>

int main(void)
{
	int lotto[6] = {0,0,0,0,0,0};
	int temp; 
	int i=0;
	int j,k;
	
	while (1)
	{
		printf("�ζǹ�ȣ �Է� : ");
		scanf("%d", &temp);
		
		k=0;
		for(j=0; j<6; j++)
		{
			if(temp==lotto[j])
			{
				k++;
			}
		}
		
		if(k>0) 
		{
			printf("���� ��ȣ�� �ֽ��ϴ�!\n");
			i--;
		}
		else
		{
			lotto[i]=temp;
		}
		
		i++;
		if(i==6) break;
	}
	
	printf("�Էµ� �ζǹ�ȣ : ");
	
	for(i=0; i<6; i++)
	{
		printf("%d ", lotto[i]);
	}
	
	return 0;
}
