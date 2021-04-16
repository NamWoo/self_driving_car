#include <stdio.h> 

int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const char *wname[7] = { "��","��","ȭ","��","��","��","��" };
const char *bars[2] = //���ڷ��̼� �� 
{
    "=====================================================\n",
    "-----------------------------------------------------\n"
};
int DrawMonth(int month, int start);//�� ���(��(0~11), ���ۿ���:0~6), ��ȯ���� ���� �� ���ۿ��� 

int main(void)
{
    int year, start;
    int i = 0;
    printf("�� ��: ");
    scanf_s("%d", &year);//�⵵ �Է�

    printf("1�� 1���� �� ��° ����(�Ͽ����� 0): ");
    scanf_s("%d", &start);//1�� 1���� ���� �Է�

    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))//���� �Ǵ� 
    {
        days[1] = 29;//2������ �� ���� 29�� ���� 
    }

    printf("[ %d�� ]\n", year);

    for (i = 0; i<12; i++)
    {
        start = DrawMonth(i, start);
    }
    return 0;
}

int DrawMonth(int month, int start)
{
    int i = 0;
    printf(" << %d ��>>\n", month + 1);//�� ���
    printf(bars[0]);//���ڷ��̼� �� ���
    for (i = 0; i<7; i++)//���� ���
    {
        printf("%7s", wname[i]);//���� 7�� ����
    }
    printf("\n");
    printf(bars[1]);//���ڷ��̼� �� ���
    for (i = 0; i<start; i++)//ù �� �����ϱ��� ���� ���
    {
        printf("%7s", " ");//���� 7�� ����
    }
    for (i = 0; i<days[month]; i++)//�� ���
    {
        printf("%7d", i + 1);//���� 7�� ����
        start++;
        if (start == 7)//������ 7�̸�
        {
            start = 0;//0���� ����
            printf("\n");//���� ���
        }
    }
    printf("\n");//���� ���
    printf(bars[0]);//���ڷ��̼�
    return start;//���� �� ���� ���� ��ȯ
}
