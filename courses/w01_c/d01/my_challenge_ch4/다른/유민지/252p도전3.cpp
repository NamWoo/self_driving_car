#include <stdio.h>

int main(void){
	int arr[6] = {0};
	int i,j;
	
	for(i= 0; i<6;i++){
		printf("�ζ� ��ȣ �Է�: ");
		scanf("%d", &arr[i]);
		for(j=0;j <i ; j++){
			if(arr[i] == arr[j]){
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				i--;
				break;
			}
		}
	} 
	printf("�Էµ� �ζ� ��ȣ: ");
	for(i = 0; i<6; i++) {
		printf("%d ",arr[i]);
	}
	
	
	
	return 0;
}






