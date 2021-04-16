#include <stdio.h>

char *my_token(char *sp);

int main(void)
{
    char str[80];
    char *p;
    
	printf("> ���� �Է� : ");
	gets(str);

    while((p = my_token(str)) != NULL)   // �տ��� ���� ���ʷ� �и��� �ܾ��� 
    {
        printf("%s\n", p);               // �����͸� ��ȯ�Ͽ� ����Ѵ�.
    }

    return 0;
}

char *my_token(char *sp)
{
    static char *mp = NULL;       // ���� �� �ܾ��� ������ ��ġ ��� 
	static int end = 0;           // ��� �ܾ ó���ߴ��� ���¸� ǥ��, ���� ��� 1 ����
    char *start;                  // ���� �� �ܾ��� ���� ��ġ 
    char *tp;                     // �ӽ� ������ ���� 
    
     
    if(sp == NULL) return NULL;   // �������ڷ� NULL�� ���� NULL ��ȯ
	if(end == 1) return NULL;     // ���ڿ��� ��� �ܾ�� ���� ��� 1 ��ȯ
    
    if(mp == NULL) start = sp;    // ���� ȣ�� 
	else start = mp+1;            // ��� �ܾ��� ���� ��ġ ���� 
    
    tp = start;                   // ������ ������ ���� �ӽú��� ����
    
    // ������ �ƴϰų� ���ڿ��� ������ ���� ��� ������ ���� 
    while(*tp != ' ' && *tp != '\0') tp++;   
    
    if(*tp == '\0') end = 1;      // ���ڿ��� �����ٸ� end�� 1�� ����
	else *tp = '\0';              // �׷��� ������ ���鹮�ڿ� �ι��� �����ϰ�
	mp = tp;                      // �� ��ġ�� ���       
    
	return start;                 // ���� �� �ܾ��� ���� ��ġ ��ȯ 
}
    
    
    
