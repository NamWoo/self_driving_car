#include <stdio.h>
#include <string.h>

void init_intro(char (*intro)[80], char **pint);
int input_intro(char (*intro)[80]);
void sort_intro(char **pint, int cnt);
void print_intro(int mode, void *vp, int cnt);

int main(void)
{
	char intro[10][80]; // 10�� 80�� 
	char *pint[10]; // 10�ุ �ֳĸ� sort ���ڿ��� �� �ղ��� �װ͸� �ʿ��ϴϱ� 
	int i,cnt;
	
	init_intro(intro, pint);
	cnt = input_intro(intro);
	sort_intro(pint, cnt);
//	for(i=0;i<cnt;i++)
//		printf("%s", pint[i]);
//	print_intro(0, pint, cnt);
//	print_intro(1, pint, cnt);
	return 0;	
}

//2���� �迭�� ������ �迭 ���� 
void init_intro(char (*intro)[80], char **pint){
	int i;
	for (i=0; i<10; i++)
		pint[i] = intro[i];
//	pint=intro;
//	�ɸ����� �迭�����͸� �������ּҿ� �־�� �ϴµ� �װ� �ȵȴ�
}

//�λ縻 �Է� �� �Էµ� �λ縻 ���� ��ȯ 
int input_intro(char (*intro)[80])
{	
	int i, cnt=0;
	char temp[80];
	
//	astro[0]={"asfasfasf"};
//	inaagtro[1]={"asfasfasf"};
//	intro = {astro, inaagtro,,../}
//	intro =getsintro = 
	while(1)
	{				
		if(cnt == 10)
		{
			printf("�λ縻 10�� �Ϸ�\n");
			break;
		}
		printf("�λ縻 �Է� : ");
		gets(intro[cnt]);
		
		if(strcmp(intro[cnt], "end") ==0 )
		{
			break;
		}
		
		strcpy(intro[cnt], temp);
		
		cnt++;
	}
//	char *ptr_ary[]={"heh afn vnav","19jnb 0jd i","-fhdfn dj dh ah"};	
//	cnt = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
//	printf("%d",cnt);
	return cnt; 
}

//�Էµ� �λ縻 ���������� ���� 
void sort_intro(char **pint, int cnt)
{	
	int i,j;	
//	for(i=0;i<cnt;i++)
//		for(j=0;j<cnt;j++)
}

void print_intro(int mode, void *vp, int cnt)
{
	int i;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	char (*temp)[80] = vp; // !!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	char **temp = vp; // !!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//	printf("%s", vp);

	if(mode == 0)
	{
		printf("# �Է¼����� ���...\n");
		for(i=0; i<cnt; i++)		
		{
			printf("%s\n", temp[i]);
		}
		
//			temp[i] = *(char *)vp[i];
//			printf("%s\n", temp[i]);
//			printf("%s\n", (char**)stringg[i]);
//			printf("%s\n", stringg[i]);
	}
	else if (mode == 1)
	{
		printf("# �Է¼����� ���...\n");
		for(i=0; i<cnt; i++)		
		{
			printf("%s\n", temp[i]);
		}		
	}
	
//		puts(vp[i]);
}



