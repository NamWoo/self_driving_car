//
// Created by Kevin You on 2019-05-14.
//


#include <stdio.h>

int main() {

    // Score Program

    int score[5];
    int cnt = sizeof(score) / sizeof(score[0]);
    int max = 0;
    int min = 100;
    int sum = 0;

    for(int i = 0; i < cnt; i++) {

        printf("5명 심사위원의 점수 입력 %d: ", i+1);
        scanf("%d", &score[i]);

        if (score[i] > max) {
            max = score[i];
        } else if (score[i] < min) {
            min = score[i];
        }
    }

    printf("\n");
    // printf("%u", *score);

    for(int i = 0; i < 5; i++) {
        if(score[i] == max) {
            max = -1;
            continue;
        } else if(score[i] == min) {
            min = -1;
            continue;
        }
        sum += score[i];
        printf("유효 점수: %d \n", score[i]);
    }

    printf("평균: %d", sum / 3);

    return 0;

}


