#include <stdio.h>
#include <string.h>

void main(void){
	
	char ch[200]={"If you would be loved, looooooove and be lovable."};
	char ne[80];
	int i, j, k, cnt;
	
	printf("���� �Է� : %s", ch);
	
	while(1){
		printf("�˻��� ���ڿ� �Է� (�����  end)");
		scanf("%s",ne);
		
		k = strlen(ne);
		
		for (i=0; i< strlen(ch); i++)
			if (strncmp(ne, ch+i, k)==0) cnt++;

		printf("%d\n",cnt);
		
		if (strcmp(ne,"end")==0) break;
		
		printf("%s",ne);
		
		
	}
	
	
	
}
