#include <stdio.h>

int main(){
int key = 15;
int answer =0;
int count=0;

while(1){

	printf("숫자 입력(1부터 30까지): ");
	scanf("%d", &answer);
 	
 	if(answer>key){
		count++;	 
 		printf("%d보다 작습니다!\n",answer);
	}
	else if(answer<key){
		count++;
		printf("%d보다 큽니다!\n", answer);
	}
	else if(answer == key){
		count++;
		printf("정답입니다!\n시도한 횟수는 %d회 입니다.\n",count);
		break;
	}	
}



	return 0;
}
