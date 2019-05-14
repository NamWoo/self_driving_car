#include <stdio.h>

int main(void)
{
	int lotto[6] = {0,0,0,0,0,0};
	int temp; 
	int i=0;
	int j,k;
	
	while (1)
	{
		printf("로또번호 입력 : ");
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
			printf("같은 번호가 있습니다!\n");
			i--;
		}
		else
		{
			lotto[i]=temp;
		}
		
		i++;
		if(i==6) break;
	}
	
	printf("입력된 로또번호 : ");
	
	for(i=0; i<6; i++)
	{
		printf("%d ", lotto[i]);
	}
	
	return 0;
}
