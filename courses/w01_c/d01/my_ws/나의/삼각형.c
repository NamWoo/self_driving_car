//20150513
//Workshop #1-2
//�ﰢ�� ����ϱ�


#include <stdio.h>

int main(void)

{
	int num,i,j,k;
	
	printf("Input number : ");
	scanf("%d", &num);
	
	if ((num%2) == 0)
	{
		printf("# ¦���� �Է� �Ǿ����ϴ�!");
		return 0;
	}
	else
	{
		for(i=1; i<num+1; i++)
		{
			for(j=0; j<num-i; j++)
			{
			  	printf(" ");
			}
			for(j=1; j<=i; j++)
			{
				printf("*");	
		 	}
			printf("\n");
		}
		printf("\n");
		
		for(i=num; i>=1; i--)
		{
			for(j=0; j<num-i; j++)
			{
			  	printf(" ");
			}
			
			for(j=1; j<=i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
		
		for(i=1; i<num+1; i++)
		{
			if((i%2) != 0)
			{
				k = (num-i) / 2;
				
				for(j=0;j<=k;j++)
				{								
				printf(" ");
				}
				
				for(j=1;j<=i;j++)
				{
				printf("*");	
				}
		    
				for(j=0; j<=k; j++)
				{								
					printf(" ");
				}
				printf("\n");	
			}
		}
	
		for(i=num; i>=1; i--)
		{
			if((i%2) != 0)
			{		
				k = (num-i) / 2;
				for(j=0; j<=k; j++)
				{
				printf(" ");	
				}
				for(j=1; j<=i; j++)
				{							
					printf("*");
				}
			    for(j=0; j<=k; j++)
				{								
					printf(" ");
				}
				printf("\n");	
			}
		}	     	
	}	
	return 0;
}
