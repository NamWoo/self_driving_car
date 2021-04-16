#include <stdio.h>

int main(void)
{
	FILE *fp;                                   // 파일 포인터
	int age;                                    // 나이 저장 변수
	char name[20];                              // 이름 저장 배열

	fp = fopen("a.txt", "r");                   // 파일 개방
	fscanf(fp, "%d", &age);                     // 나이 입력
	fgets(name, sizeof(name), fp);              // 이름 입력
	printf("나이 : %d, 이름 : %s", age, name);  // 입력 데이터 출력
	fclose(fp);                                 // 파일 닫음

	return 0;
}