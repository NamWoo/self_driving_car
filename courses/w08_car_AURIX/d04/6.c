/*****************************************************
 *
 * myproject.c
 *
 * Description : Hello World in C, ANSI-style
 *
 */

typedef int (*FN)(int, int);
typedef int ARR[2][3];
typedef int (*ID)[3];

int main(void)
{

	ID var;
	ARR var1 = {{1,2,3},{4,5,6}};
	int tmp;

	//var1 : int [2][3]
	//tmp = var1(1,2);
	//var1();  이렇게 하면 호출이 되지 않는다. 이걸 호출할 수 있게 할 수 있다. 어떻게? 이렇게
	tmp = ((FN)var1)(1,2);
	//형변환 하면 안된다. 메모리 용도를 선언했을때 아닌 용도로 할 수 있게 하기 때문에. 원래 배열인데 함수로 형변환.
	//함수로 형변환시키니까 배여리니까 명령어 없으니까.


//	tmp = ((int (*)(int, int))var1)(1, 2);
//	((void (*)(void))var1))();

}
