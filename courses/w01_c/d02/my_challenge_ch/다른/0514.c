#include <stdio.h>

int main(){
int key = 15;
int answer =0;
int count=0;

while(1){

	printf("���� �Է�(1���� 30����): ");
	scanf("%d", &answer);
 	
 	if(answer>key){
		count++;	 
 		printf("%d���� �۽��ϴ�!\n",answer);
	}
	else if(answer<key){
		count++;
		printf("%d���� Ů�ϴ�!\n", answer);
	}
	else if(answer == key){
		count++;
		printf("�����Դϴ�!\n�õ��� Ƚ���� %dȸ �Դϴ�.\n",count);
		break;
	}	
}



	return 0;
}
