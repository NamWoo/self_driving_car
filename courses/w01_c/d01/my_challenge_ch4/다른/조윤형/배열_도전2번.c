#include <stdio.h>

int main()
{
	int num[6];
	int temp,i,j,count=0;
	
	for(i=0;i<6;i++){
		printf("�ζǹ�ȣ �Է� : ");
		scanf("%d",&temp);
		for(j=0;j<count;j++){
			if(num[j]==temp){
				printf("���� ��ȣ�� �ֽ��ϴ�!\n"); 
				i--;
				break;
			}
		}
		if(j == count){
			num[i] = temp;
			count++;
		}
	}
	
	printf("�Էµ� �ζǹ�ȣ : ");
	for(i=0;i<6;i++)
	{
		printf(" %d",num[i]);
	}
	return 0;
}
