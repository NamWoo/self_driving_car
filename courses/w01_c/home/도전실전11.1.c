//���̰� ���� �� �ܾ� ã��
//�迭 ������� �ʱ�
 
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

	printf("���� �� �ܾ��� ���� : %d",temp);
	
}

