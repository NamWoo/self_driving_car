#include <stdio.h>

int main(void)
{
	FILE *ifp, *ofp;            // 파일 포인터 선언
	char name[20];              // 이름
	int kor, eng, mat;          // 세 과목 점수
	int tot;                    // 총점
	double avg;                 // 평균
	int res;                    // fscanf 함수의 반환값 저장

	ifp = fopen("a.txt", "r");  // 입력 파일을 읽기 전용으로 개방
	if (ifp == NULL)            // 개방 여부 확인
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");  // 출력 파일을 쓰기 전용으로 개방
	if (ofp == NULL)            // 개방 여부 확인
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s %d %d %d", name, &kor, &eng, &mat); // 데이터 입력
		if (res == EOF)         // 파일의 데이터를 모두 읽으면 EOF 반환
		{
			break;
		}
		tot = kor + eng + mat;                            // 총점 계산
		avg = tot / 3.0;                                  // 평균 계산
		fprintf(ofp, "%s %5d %7.1lf\n", name, tot, avg);  // 이름, 총점, 평균 출력
	}
	fclose(ifp);                                          // 입력 파일 닫기
	fclose(ofp);                                          // 출력 파일 닫기

	return 0;
}