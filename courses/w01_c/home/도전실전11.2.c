#include <stdio.h> 

void main(void){
	int ch;
	
	while((ch=getchar()) != '\n'){
				
		if ((ch>='a')&&(ch<='z')){
			printf("%c", ch-32);
		}		
		else if ((ch>='A')&&(ch<='Z'))
			printf("%c", ch+32);
		else 
			printf("%c",ch);
	}
}

