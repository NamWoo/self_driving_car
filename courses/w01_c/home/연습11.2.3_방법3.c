#include <stdio.h>

void main(void){
	int cnt=0, ch;
		
	while((ch = getchar()) != EOF){
		if (ch=='\n') cnt++;
	}
	printf("����Ű�� ���� Ƚ�� %d", cnt);

}
