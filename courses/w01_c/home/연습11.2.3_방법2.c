#include <stdio.h>

void main(void){
	int cnt=0, ch;
		
	while(scanf("%c", &ch) != EOF){
		if (ch=='\n') cnt++;
	}
	printf("엔터키를 누른 횟수 %d", cnt);

}
