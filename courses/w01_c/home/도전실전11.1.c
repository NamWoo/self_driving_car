//길이가 가장 긴 단어 찾기
//배열 사용하지 않기
 
#include <stdio.h> 

void main(void){
	int ch, acnt=0, temp=0;
	
	while((ch=getchar()) != EOF){		
		acnt++;
		
		if (ch == '\n'){
			if (temp<acnt) temp = acnt-1;
			acnt=0;
		}	
	}

	printf("가장 긴 단어의 길이 : %d",temp);
	
}

