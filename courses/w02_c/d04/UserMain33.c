//#include "../lib2450/Uart.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct person_t
{
    char *name;
    int age;    
} Person;


void Normal_Copy_Test(void)
{
	Person src = { NULL, 20 };
    Person dest;
	
    src.name = malloc(4);
    strcpy(src.name, "JSH");
    
    dest = src; // (X)
    strcpy(dest.name, "AAA"); // (X)

    printf("Src[%s], Dest[%s] \n", src.name, dest.name);
}

void Deep_Copy_Test(void)
{
	Person dest, src = { NULL, 20 };
    
    src.name = malloc(4);
    strcpy(src.name, "JSH");
    
    dest.name = malloc(strlen(src.name) + 1);
    strcpy(dest.name, src.name);
    dest.age = src.age;

    strcpy(dest.name, "AAA");
  
    Uart_Printf("Src[%s], Dest[%s] \n",
        src.name, dest.name);
}

//void User_Main(void)
void main(void)
{
    printf("========== Normal_Copy_Test ========== \n");
	Normal_Copy_Test();
	//Src[AAA], Dest[AAA]
	
	printf("\n\n\n========== Deep_Copy_Test ========== \n");
	Deep_Copy_Test();
	//Src[JHS], Dest[AAA]
}
