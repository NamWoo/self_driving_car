#include <stdio.h> 

void main(void){
	int ch=0, num=0;
	
	printf("�ϳ��� ���� �Է�(0~9) : ");
	ch = getchar();
	
	num = ch - '0' + 1;
//	num = ch + 1;
		
	printf("%c�� 1�� ���� ���� %d �Դϴ�.",ch, num);
}

