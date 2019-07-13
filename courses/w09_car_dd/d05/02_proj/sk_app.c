#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

//ioctl
#include <sys/ioctl.h>
#include "ioctl_mydrv.h"

void usersignal(int sig);
int count = 0;

int main(void)
{
    int retn;
    int fd;
    int size;
    pid_t id;

    //ioctl
    ioctl_buf *buf_in,*buf_out;
    size = sizeof(ioctl_buf);
    buf_in = (ioctl_buf *)malloc(size);
    buf_out = (ioctl_buf *)malloc(size);
    //~ioctl

    // char buf[100] = "write...\n";
    char buf[100] = {0};
    (void)signal(SIGUSR1, usersignal);
    //signal 잘 쓰면 정말 잘 동기화 할 수 있다.
    //커널과 응용 어필간의 신호 주고받는게 이 과제 핵심
    //함수호출을 사용하지 않고도 시그널 만으로
    //호출할 수 있는 개념으로 이해, 시스템이 호출
    //시그널 SIGUSR1 : 쓰고자 하는 신호
    //시그널 핸들러 usersignal, 콜백함수
        //리눅스의 3대 핸들러, 인터럽트, 시그널, 타이머
    //핸들러에서 셋팅만 초기화 해주기만 하면 된다.
    //OS가 불러내는 것
    //인터럽트도 같은 개념, 등록되어 있는 함수 실행 같은.
    //kill -l

    id = getpid();
    //현재 프로세스 아이디 리턴
    printf("\n\n\n\n\n\n\n\n");
    printf("\n [APP] = %d", id);
    printf("\n\n\n\n\n\n\n\n\n");

    fd = open("/dev/sk", O_RDWR);
    //이걸 만들어야 장치파일로 등록
    //VFS로 올라가고 어플단에서 보일 수 있다
    //fd : 파일 지시
    printf("fd = %d\n", fd);
    
    if (fd<0) {
        perror("/dev/sk error");
        exit(-1);
    }
    else
        printf("SK has been detected...\n");

    ///
    ioctl(fd,IOCTL_LED_ON_TEST1);
    ioctl(fd,IOCTL_LED_ON_TEST2);
    ioctl(fd,IOCTL_LED_ON_TEST3);
    ioctl(fd,IOCTL_LED_ON_TEST4);
    ioctl(fd,IOCTL_LED_ON_TEST5);
    
    ///

    retn = write(fd, &id, 4);
    //커널단의 xxx_write함수가 호출된다. 이게 동기화!
    //커널과 앱단의 통신, 
    
    retn = read(fd, buf, 20);
    // fd가 가르키는 파일에 buf에서 20byte 읽음

    printf("\ndata : %s\n", buf);

 
    //C언어는 순차언어
    //이거 없으면 그냥 쭉 실행되서 프로세서 종료되어버린다.
    //while 넣고 널문장 넣어도 되는데. 이건 여기서 나올수없는
    //pthread 넣고.. 근데 굳이 프로세스이렇게? 별로
    //pause가 더 좋다. 
    //잠깐 대기상태로 빠져서 신호를 기다린다.
    //신호를 받으면 밑으로 내려온다.
    do
    {
        printf("god BONG JUN\n");
        ioctl(fd,IOCTL_LED_ON_TEST1);
        ioctl(fd,IOCTL_LED_ON_TEST5);
        pause();     
    } while (1);

    ///
    free(buf_in);
    free(buf_out);
    ///
    close(fd);
    
    return 0;
}


//시그널핸들러 신호가 도착하면 이 함수 호출.
//이 usersignal 콜 부분 없어도 열리는.
//이런게 콜백함수다.
void usersignal(int sig)
{
   printf("\n sig...%d\n", count++);
//    pthread...!
//포크.또 쓰레드 만들수 있다.
//부모는 자기일 하고 자식한테 일시킬수도 있고
//esec 리눅스의 6개..
//여기 킬로 다른 프로세서로 나갈 수 있고.

}
