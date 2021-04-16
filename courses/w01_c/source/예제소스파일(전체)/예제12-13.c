#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = "pear";
	char str2[80] = "peach";

	printf("사전에 나중에 나오는 과일 이름 : ");
	if (strcmp(str1, str2) > 0)                  // str1이 str2보다 크면(사전에 나중에 나오면)
		printf("%s\n", str1);                    // str1 출력
	else
		printf("%s\n", str2);                    // 그렇지 않으면 str2 출력

	printf("앞에서 3개의 문자를 비교하면 ");
	if (strncmp(str1, str2, 3) == 0)             // 앞에서 3개의 문자가 같으면 0 반환
		printf("같다.\n");
	else
		printf("다르다.\n");

	return 0;
}