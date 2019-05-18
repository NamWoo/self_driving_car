//길이가 가장 긴 단어 찾기
//배열 사용하지 않기
 
#include <stdio.h> 

int input_word(char *word);

void main(void){
	char *word;
	int cnt;

	cnt = input_word(word);
	printf("%d",cnt);
	
}


int input_word(char *word){
	int cnt=0, i, res;
	
	while(1){
		res = gets(&word);
		if (res = -1) break;

		prints()
		
		printf("%s", word);

				
//		for (i=0; i=='\n'; i++){
//			printf("%c", word[i]);
////			
//		}
		
		 
	}
		
	
	return cnt;
}
