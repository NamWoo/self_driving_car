/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "ioctl_mydrv.h"

int main()
{
  int fd,i,size;
  ioctl_buf *buf_in,*buf_out;
  
  size = sizeof(ioctl_buf);
  buf_in = (ioctl_buf *)malloc(size);
  buf_out = (ioctl_buf *)malloc(size);
  
  fd = open("/dev/mydrv",O_RDWR);
 
  ioctl(fd,IOCTL_LED_ON_TEST1);
  ioctl(fd,IOCTL_LED_ON_TEST2);
  ioctl(fd,IOCTL_LED_ON_TEST3);
  ioctl(fd,IOCTL_LED_ON_TEST4);
  ioctl(fd,IOCTL_LED_ON_TEST5);

  

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
  close(fd);
  return (0);
}
