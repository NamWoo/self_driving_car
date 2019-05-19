#include <stdio.h> 

void main(void){
	int ch=0, num=0;
	
	printf("하나의 숫자 입력(0~9) : ");
	ch = getchar();
	
	num = ch - '0' + 1;
//	num = ch + 1;
		
	printf("%c에 1을 더한 값은 %d 입니다.",ch, num);
}

