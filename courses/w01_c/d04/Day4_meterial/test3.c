3.3
/*
 * test3.c
 *
 *  Created on: 2015. 2. 9.
 *      Author: elayer
 */
#include "test.h"

#ifdef TEST3
#define MAX 100
int my_strcmp( char*str1,  char*str2){

   while ( *str1 == *str2) {
		if ( *str1 =='\0' ) {
			return 0;
		}
		str1++; str2++;
	}
	return *str1 - *str2;
}

int main(void) {
	char str1[MAX], str2[MAX];
	int comp = 0;

	printf("첫 번째 비교할 문자열 입력 : "); OUT;
	gets(str1);
	printf("두 번째 비교할 문자열 입력 : "); OUT;
	gets(str2);
	comp = my_strcmp(str1, str2);
	if ( comp > 0 ) {
		printf("%s가 더 큽니다.", str1);
	} else if (comp < 0) {
		printf("%s가 더 큽니다.", str2);
	} else {
		printf("두 문자열이 같습니다.");
	}
	return 0;
}
#endif
