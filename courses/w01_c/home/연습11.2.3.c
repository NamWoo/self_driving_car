#include <stdio.h>

void main(void){
	int cnt=0, ch;
		
	while(1){
		ch = getchar();
		if (ch=='\n') cnt++;
		else if (ch==EOF) break;
	}
	printf("����Ű�� ���� Ƚ�� %d", cnt);

}
