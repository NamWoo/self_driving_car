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
    //signal �� ���� ���� �� ����ȭ �� �� �ִ�.
    //Ŀ�ΰ� ���� ���ʰ��� ��ȣ �ְ�޴°� �� ���� �ٽ�
    //�Լ�ȣ���� ������� �ʰ� �ñ׳� ������
    //ȣ���� �� �ִ� �������� ����, �ý����� ȣ��
    //�ñ׳� SIGUSR1 : ������ �ϴ� ��ȣ
    //�ñ׳� �ڵ鷯 usersignal, �ݹ��Լ�
        //�������� 3�� �ڵ鷯, ���ͷ�Ʈ, �ñ׳�, Ÿ�̸�
    //�ڵ鷯���� ���ø� �ʱ�ȭ ���ֱ⸸ �ϸ� �ȴ�.
    //OS�� �ҷ����� ��
    //���ͷ�Ʈ�� ���� ����, ��ϵǾ� �ִ� �Լ� ���� ����.
    //kill -l

    id = getpid();
    //���� ���μ��� ���̵� ����
    printf("\n\n\n\n\n\n\n\n");
    printf("\n [APP] = %d", id);
    printf("\n\n\n\n\n\n\n\n\n");

    fd = open("/dev/sk", O_RDWR);
    //�̰� ������ ��ġ���Ϸ� ���
    //VFS�� �ö󰡰� ���ôܿ��� ���� �� �ִ�
    //fd : ���� ����
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
    //Ŀ�δ��� xxx_write�Լ��� ȣ��ȴ�. �̰� ����ȭ!
    //Ŀ�ΰ� �۴��� ���, 
    
    retn = read(fd, buf, 20);
    // fd�� ����Ű�� ���Ͽ� buf���� 20byte ����

    printf("\ndata : %s\n", buf);

 
    //C���� �������
    //�̰� ������ �׳� �� ����Ǽ� ���μ��� ����Ǿ������.
    //while �ְ� �ι��� �־ �Ǵµ�. �̰� ���⼭ ���ü�����
    //pthread �ְ�.. �ٵ� ���� ���μ����̷���? ����
    //pause�� �� ����. 
    //��� �����·� ������ ��ȣ�� ��ٸ���.
    //��ȣ�� ������ ������ �����´�.
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


//�ñ׳��ڵ鷯 ��ȣ�� �����ϸ� �� �Լ� ȣ��.
//�� usersignal �� �κ� ��� ������.
//�̷��� �ݹ��Լ���.
void usersignal(int sig)
{
   printf("\n sig...%d\n", count++);
//    pthread...!
//��ũ.�� ������ ����� �ִ�.
//�θ�� �ڱ��� �ϰ� �ڽ����� �Ͻ�ų���� �ְ�
//esec �������� 6��..
//���� ų�� �ٸ� ���μ����� ���� �� �ְ�.

}
