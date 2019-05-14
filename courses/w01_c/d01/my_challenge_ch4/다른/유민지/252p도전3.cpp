#include <stdio.h>

int main(void){
	int arr[6] = {0};
	int i,j;
	
	for(i= 0; i<6;i++){
		printf("로또 번호 입력: ");
		scanf("%d", &arr[i]);
		for(j=0;j <i ; j++){
			if(arr[i] == arr[j]){
				printf("같은 번호가 있습니다!\n");
				i--;
				break;
			}
		}
	} 
	printf("입력된 로또 번호: ");
	for(i = 0; i<6; i++) {
		printf("%d ",arr[i]);
	}
	
	
	
	return 0;
}






