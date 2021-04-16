// 파일 이름을 '예제19-9-average.c'에서 average.c로 바꿔 사용하세요.

extern int cnt;                // main.c의 전역 변수 cnt 공유
extern int tot;                // input.c의 전역 변수 tot 공유

double average(void)
{
	return tot / (double)cnt;  // 입력값의 평균 반환
}
