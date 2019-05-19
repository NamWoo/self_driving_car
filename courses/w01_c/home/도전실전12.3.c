#include <stdio.h>
#include <string.h>

void main(void){
	
	char ch[200]={"If you would be loved, looooooove and be lovable."};
	char ne[80];
	int i, j, k, cnt;
	
	printf("문장 입력 : %s", ch);
	
	while(1){
		printf("검색할 문자열 입력 (종료는  end)");
		scanf("%s",ne);
		
		k = strlen(ne);
		
		for (i=0; i< strlen(ch); i++)
			if (strncmp(ne, ch+i, k)==0) cnt++;

		printf("%d\n",cnt);
		
		if (strcmp(ne,"end")==0) break;
		
		printf("%s",ne);
		
		
	}
	
	
	
}
