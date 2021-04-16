#include <stdio.h>

struct score                             // 구조체 선언
{
	int kor;                             // 국어 점수를 저장할 멤버
	int eng;                             // 영어 점수
	int mat;                             // 수학 점수
};

int main(void)
{
	struct score yuni = {90, 80, 70};    // 구조체 변수 선언과 초기화
	struct score *ps = &yuni;            // 구조체 포인터에 주소 저장

	printf("국어 : %d\n", (*ps).kor);    // 구조체 포인터로 멤버 접근
	printf("영어 : %d\n", ps->eng);      // -> 연산자 사용
	printf("수학 : %d\n", ps->mat);

	return 0;
}