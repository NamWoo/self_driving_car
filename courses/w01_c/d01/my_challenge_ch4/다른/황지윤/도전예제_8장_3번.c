// 8�� ������������ 3��

#include <stdio.h>
int main(void)
{
	int lotto[6];
	int i,j;
	for(i=0;i<6;i++){
		printf("�ζǹ�ȣ �Է� : ");	
		scanf("%d", &lotto[i]);
			for(j=0;j<i;j++){
						if(lotto[i]==lotto[j]){
							printf("���� ��ȣ�� �ֽ��ϴ�!\n");
							i--;
							break;
						}
			}
	}
	printf("�Էµ� �ζǹ�ȣ :");
	for(i=0;i<6;i++){
	printf("%6d", lotto[i]);		
	}
	
	return 0;
}
