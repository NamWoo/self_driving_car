#include <stdio.h>
int main(void)
{
    int res;
    char ch;

    while(1)
    {
        res = scanf("%c", &ch);
        if(res==-1) break; // ��ȯ���� -1 �̸� �ݺ� ����
        printf("%d ", ch); // �Էµ� ������ �ƽ�Ű �ڵ尪 ���

    
    }

    return 0;



}
