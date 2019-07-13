#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
// #include <sys/ioctl.h>
// #include "ioctl_mydrv.h"

typedef struct
{
   int age;  //나이 :35
   char name[30];// 이름 : HONG KILDONG
   char address[20]; // 주소 : SUWON CITY
   int  phone_number; // 전화번호 : "01012345678"
   char depart[20]; // 부서 : "ELAYER R&D"
} __attribute__ ((packed)) mydrv_data;

#define MAX_BUFFER sizeof(mydrv_data)


int main()
{
  int fd,i,size,retn;
    mydrv_data *buf_in,*buf_out;
  buf_in = (mydrv_data *)malloc(sizeof(mydrv_data));
  buf_out = (mydrv_data *)malloc(sizeof(mydrv_data));
//   ioctl_buf *buf_in,*buf_out;
//   buf_in = (ioctl_buf *)malloc(size);
//   buf_out = (ioctl_buf *)malloc(size);

//   size = sizeof(ioctl_buf);

    // char buf[100] = {0};

  fd = open("/dev/hell", O_RDWR);
    printf("fd = %d\n", fd);
    printf("size=%d\n",sizeof(mydrv_data));

    if (fd<0) {
        perror("/dev/hell error");
        exit(-1);
    }
    else
    printf("hell has been detected...\n");

// retn = read(fd, buf, 20); // fd가 가르키는 파일에 buf에서 20byte 

  read(fd,buf_in,MAX_BUFFER);
  printf("age = %d\n",buf_in->age);
  printf("name = %s\n",buf_in->name);
  printf("address = %s\n",buf_in->address);
  printf("phone_number = %d\n",buf_in->phone_number);
  printf("depart = %s\n",buf_in->depart);


//   ioctl(fd,IOCTL_LED_ON_TEST1);
//   ioctl(fd,IOCTL_LED_ON_TEST2);
//   ioctl(fd,IOCTL_LED_ON_TEST3);
//   ioctl(fd,IOCTL_LED_ON_TEST4);
//   ioctl(fd,IOCTL_LED_ON_TEST5);

  

//   ioctl(fd, IOCTL_MYDRV_READ, buf_in );
//   printf("buf_in = %s\n",buf_in->data);
  
//   for(i = 0;i < size;i++)
//      buf_out->data[i] = 'a' + i;
//   ioctl(fd, IOCTL_MYDRV_WRITE, buf_out );
  
//   for(i = 0;i < size;i++)
//      buf_out->data[i] = 'z' - i;
//   ioctl(fd, IOCTL_MYDRV_WRITE_READ, buf_out );
//   printf("buf_in = %s\n",buf_out->data);
    
  free(buf_in);
  free(buf_out);
    // printf("\nnw data : %s\n", buf);

  close(fd);
  return 0;
}
