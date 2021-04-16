: copy_to_user()/copy_from_user() 사용
 응용프로그램이 보내준
아래 구조체 형식의 데이터를 드라이버가 받아서 출력시키고 
드라이버는 같은 구조체 형식으로 또 다른 데이터를 응용프로그램에게
보내주고 응용프로그램이 출력시키는 코드를 구현하세요

/*  구조체 포맷  */
typedef struct
{
   int age;  //나이 :35
   char name[30];// 이름 : HONG KILDONG
   char address[20]; // 주소 : SUWON CITY
   int  phone_number; // 전화번호 : 1234
   char depart[20]; // 부서 : mds
} __attribute__ ((packed)) mydrv_data;

//   sprintf(k_buf->name,"HONG KILDONG");


