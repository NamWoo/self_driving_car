#include <stdio.h>

void main(void)
{
	char ch1[80], ch2[80], ch3[80], temp[80];
	
	printf("세 단어 입력 : ");
	scanf("%s%s%s", ch1, ch2, ch3);
	
	if ( strcmp(ch1, ch2) > 0 ){		// ch1 ch2 알파벳순 정렬 
		strcpy(temp, ch1);
		strcpy(ch1, ch2);
		strcpy(ch2, temp);
	}
	
	if ( strcmp(ch1, ch3) > 0 ){		// ch1 ch3 알파벳순 정렬 
		strcpy(temp, ch1);
		strcpy(ch1, ch3);
		strcpy(ch3, temp);
	}
	
	if ( strcmp(ch2, ch3) > 0 ){		// ch2 ch3 알파벳순 정렬 
		strcpy(temp, ch2);
		strcpy(ch2, ch3);
		strcpy(ch3, temp);
	}

	printf("%s, ",ch1);
	printf("%s, ",ch2);
	printf("%s",ch3);
}
