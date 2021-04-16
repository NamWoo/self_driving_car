#include <stdio.h>
int main(void)
{
    int res;
    char ch;

    while(1)
    {
        res = scanf("%c", &ch);
        if(res==-1) break; // 반환값이 -1 이면 반복 종료
        printf("%d ", ch); // 입력된 문자의 아스키 코드값 출력

    
    }

    return 0;



}
