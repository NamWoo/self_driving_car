#include <stdio.h>

int main()
{
	int num[6];
	int temp,i,j,count=0;
	
	for(i=0;i<6;i++){
		printf("로또번호 입력 : ");
		scanf("%d",&temp);
		for(j=0;j<count;j++){
			if(num[j]==temp){
				printf("같은 번호가 있습니다!\n"); 
				i--;
				break;
			}
		}
		if(j == count){
			num[i] = temp;
			count++;
		}
	}
	
	printf("입력된 로또번호 : ");
	for(i=0;i<6;i++)
	{
		printf(" %d",num[i]);
	}
	return 0;
}
