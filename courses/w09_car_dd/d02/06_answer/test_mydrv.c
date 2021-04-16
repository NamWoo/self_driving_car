/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct
{
   int age;  //나이 :35
   char name[30];// 이름 : HONG KILDONG
   char address[20]; // 주소 : SUWON CITY
   int  phone_number; // 전화번호 : "01012345678"
   char depart[20]; // 부서 : "ELAYER R&D"
} __attribute__ ((packed)) mydrv_data;

#define MAX_BUFFER sizeof(mydrv_data)

// sprintf(name,"HONG KILDONG" );
int main()
{
  int fd,i;
  mydrv_data *buf_in,*buf_out;
  buf_in = (mydrv_data *)malloc(sizeof(mydrv_data));
  buf_out = (mydrv_data *)malloc(sizeof(mydrv_data));

  fd = open("/dev/mydrv",O_RDWR);
  printf("size=%d\n",sizeof(mydrv_data));
  /////////////////////////////////////////////////////////////////////////////////
  read(fd,buf_in,MAX_BUFFER);
  printf("age = %d\n",buf_in->age);
  printf("name = %s\n",buf_in->name);
  printf("address = %s\n",buf_in->address);
  printf("phone_number = %d\n",buf_in->phone_number);
  printf("depart = %s\n",buf_in->depart);
  /////////////////////////////////////////////////////////////////////////////////
  buf_out->age = 45;
  sprintf(buf_out->name,"KIM CHEOLSU");
  sprintf(buf_out->address,"SEOUL CITY");
  buf_out->phone_number = 16080;
  sprintf(buf_out->depart,"elayer");
  write(fd,buf_out,MAX_BUFFER);
  /////////////////////////////////////////////////////////////////////////////////
  free(buf_in);
  free(buf_out);
  close(fd);
  return (0);
}
