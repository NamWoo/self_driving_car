#include <stdio.h>

void main(void){
	int cnt=0, ch;
		
	while(scanf("%c", &ch) != EOF){
		if (ch=='\n') cnt++;
	}
	printf("����Ű�� ���� Ƚ�� %d", cnt);

}
