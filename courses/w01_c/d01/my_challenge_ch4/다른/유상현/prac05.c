//
// Created by Kevin You on 2019-05-14.
//


#include <stdio.h>

int main() {

    int lotto[6];
    int cnt = sizeof(lotto) / sizeof(lotto[0]);
    int pre = 0;
    int retry = 0;

    for(int i = 0; i < cnt; i++) {

        printf("로또 번호 입력: ");
        scanf("%d", &pre);

        for (int k = 0; k < cnt; k++) {
            if (lotto[k] == pre) {
                printf("같은 번호가 있습니다!\n");
                retry = 1;
                break;
            }
        }

        if (retry) {
            i--;
            retry = 0;
            continue;
        }

        lotto[i] = pre;

    }

    printf("입력된 로또번호: \n");

    for(int i = 0; i < cnt; i++) {
        printf(" %d ", lotto[i]);
    }

    return 0;

}
