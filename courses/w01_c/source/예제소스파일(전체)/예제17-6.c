#include <stdio.h>

struct children
{
	unsigned int son : 2;                  // 아들 수를 저장할 멤버
	unsigned int daughter : 2;             // 딸 수를 저장할 멤버
	unsigned int pet : 3;                  // 애완동물 수를 저장할 멤버
};

int main(void)
{
	struct children my = {1, 2, 3};        // 비트 필드 구조체 변수 초기화
	int sum;

	printf("struct children의 크기 : %d바이트\n", sizeof(my));
	sum = my.son + my.daughter + my.pet;   // 멤버의 합 계산
	printf("자식 수 : %d\n", sum);

	return 0;
}