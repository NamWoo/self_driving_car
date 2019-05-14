#include <stdio.h>

int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);

int main() {

    int kor;
    int eng;
    int mat;
    int total_score;
    double avg;

    printf("세 과목의 점수 입력 (국 영 수): ");
    scanf("%d %d %d", &kor, &eng, &mat);

    total_score = total(kor, eng, mat);
    avg = average(total_score);


    print_title();

    printf(" %d    %d     %d     %d    %lf", kor, eng, mat, total_score, avg);
    printf("\n");

    return 0;

}

int total(int kor, int eng, int mat) {

    return kor + eng + mat;
}

double average(int tot) {
    return (double) tot / 3;
}

void print_title(void) {
    printf("=====< 성 적 표 >=====");
    printf("\n");

    printf("------------------------------------");
    printf("\n");
    printf(" 국어    영어    수학    총점    평균");
    printf("\n");
    printf("------------------------------------");
    printf("\n");
}
