#include <stdio.h>
 
void snale_matrix(){
    int matrix[5][5];
    int num=1;
    int delta=1;
    int limit=5;
    int i=0,j=-1;
 
    int p,q;
 
    while(1){
 
        //���η� �̵��ϸ鼭 �ϳ��� �Ҵ�
        for(p=0; p<limit; p++){
            j=j+delta;
            matrix[i][j]=num;
            num++;
        }
 
        //Ƚ�� ���̰�
        limit--;
 
        if(limit<0) break;
 
        //���η� �̵��ϸ鼭 �ϳ��� �Ҵ�
        for(p=0; p<limit; p++){
            i=i+delta;
            matrix[i][j]=num;
            num++;
        }
 
        //�̵������� ������ �ٲ�
        delta=-delta;
    }
 
    //2���� �迭 ���
    for(p=0; p<5; p++){
        for(q=0; q<5; q++){
            printf("%d\t",matrix[p][q]);
            Sleep(300);
        }
        printf("\n");
    }
 
}
 
int main(void){
    snale_matrix();
    return 0;
}


//��ó: https://milvus.tistory.com/59 [Milvus Migrans]
