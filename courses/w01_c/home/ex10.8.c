#include <stdio.h>

void input_ary(int *pa,int cnt);
void output_ary(int *pa,int cnt);

void main(void)
{

	//정수형 변수 선언 
	int pa; 
	scanf("%d", &pa);			//그냥 pa는 오류 
	printf("pa : %d\n",pa);
	printf("&pa : %d\n",&pa);	//*pa 오류  
	//값, 주소; 
	//정수형 변수pa의 메모리 주소 1000일 때
	//메모리 주소에 직접 입력 
	
	//정수형 포인터변수 선언 
	int *pb;
	scanf("%d", &pb);	
	printf("pb : %d\n", pb);	
	printf("&pb : %d\n",&pb);	//*pb 오류 
	//값, 주소; 
	//정수형 포인터변수pb는 주소를 가리키는 변수 
	//pb의 주소에 입력 후 pb, &pb 로 출력 
		  	
	//정수형 포인터배열 10개 선언 
	int *pc[10];
	scanf("%d", &pc);	
	printf("pc : %d\n",pc);
	printf("*pc : %d\n",*pc);
	printf("&pc : %d\n",&pc);
	//scanf 가 pc, &pc 일때 주소/값/주소
	//scanf 가 *pc 일때 주소/???/주소
	
}





//	input_ary(*ary)
void input_ary(int *pa,int cnt)
{
//	printf("입력:");
	
	
}
//
//void output_ary(int *pa,int cnt)
//{
//	
//}
