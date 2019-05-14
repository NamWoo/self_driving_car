#include <stdio.h>
#include <string.h>                // string.h 헤더 파일 포함

int main(void)
{
	char fruit[20] = "strawberry"; // strawberry 초기화

	printf("%s\n", fruit);         // strawberry 출력
	strcpy(fruit, "banana");       // fruit에 banana 복사
	printf("%s\n", fruit);         // banana 출력

	return 0;
}