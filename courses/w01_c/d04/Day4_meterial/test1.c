#include "test.h"

#ifdef TEST1
void swap(char*str1, char*str2) {
	char temp[MAX];

	strncpy(temp, str1, strlen(str1)+1);
	strncpy(str1, str2, strlen(str2)+1);
	strncpy(str2, temp, strlen(temp)+1);
}

int main(void) {
	char str1[MAX], str2[MAX];

	printf("1번 문자열을 입력하세요 : "); OUT;
	gets(str1);
	printf("2번 문자열을 입력하세요 : "); OUT;
	gets(str2);

	printf("swap 전 : %s - %s\n", str1, str2);
	swap(str1, str2);
	printf("swap 후 : %s - %s\n", str1, str2);
	return 0;
}
#endif
