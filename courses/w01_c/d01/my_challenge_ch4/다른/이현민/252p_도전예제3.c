#include<stdio.h>
#include <stdbool.h>

int main(void)
{
	int num, i, cnt = 0;
	int arr[7];
	bool isSame = false;
	
	while(1){
		printf("�ζǹ�ȣ �Է�: ");
		scanf("%d", &num);
			
		if(cnt > 0){
			for(i = 0; i < cnt; i++){
				if(arr[i] == num){
					printf("���� ��ȣ�� �ֽ��ϴ�! \n");
					isSame = true;
					break;
				}
			}	
		} 
		
		if(isSame){
			isSame = false;
			continue;
		}else{
			arr[cnt++] = num;	
			
		}
		
		if(cnt == 6){
			break;
		}
	}
	
	printf("�Էµ� �ζ� ��ȣ :   ");
	for(i = 0; i < cnt; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
