#include <stdio.h>

char *my_token(char *sp);

int main(void)
{
    char str[80];
    char *p;
    
	printf("> 문장 입력 : ");
	gets(str);

    while((p = my_token(str)) != NULL)   // 앞에서 부터 차례로 분리한 단어의 
    {
        printf("%s\n", p);               // 포인터를 반환하여 출력한다.
    }

    return 0;
}

char *my_token(char *sp)
{
    static char *mp = NULL;       // 끊어 낸 단어의 마지막 위치 기억 
	static int end = 0;           // 모든 단어를 처리했는지 상태를 표시, 끝난 경우 1 저장
    char *start;                  // 끊어 낼 단어의 시작 위치 
    char *tp;                     // 임시 포인터 변수 
    
     
    if(sp == NULL) return NULL;   // 전달인자로 NULL이 오면 NULL 반환
	if(end == 1) return NULL;     // 문자열을 모두 단어로 끊은 경우 1 반환
    
    if(mp == NULL) start = sp;    // 최초 호출 
	else start = mp+1;            // 끊어낼 단어의 시작 위치 설정 
    
    tp = start;                   // 포인터 증가를 위한 임시변수 설정
    
    // 공백이 아니거나 문자열이 끝나지 않은 경우 포인터 증가 
    while(*tp != ' ' && *tp != '\0') tp++;   
    
    if(*tp == '\0') end = 1;      // 문자열이 끝났다면 end를 1로 설정
	else *tp = '\0';              // 그렇지 않으면 공백문자에 널문자 설정하고
	mp = tp;                      // 그 위치를 기억       
    
	return start;                 // 끊어 낸 단어의 시작 위치 반환 
}
    
    
    
