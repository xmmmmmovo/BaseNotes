//
// Created by xmmmmmovo on 2019/12/4.
//

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 30

char *msg1 = "Child 1 is sending a message!";
char *msg2 = "Child 2 is sending a message!";

void waiting(int flag) {
    while (flag == 0);
}

int main(void) {

    char inbuf[MSGSIZE];
    int p[2];

    pid_t pid1;                  /*定义子进程的变量*/
    pid_t pid2;

    /*创建管道*/
    if (pipe(p) == -1) {
        perror("pipe call");
        exit(0);
    }
    pid1 = fork();       /*这里定义第一个子进程*/
    if (pid1 < 0)
        printf("Error.NO.1 fock call fail\n");
    else if (pid1 == 0)                 /*当第一个子进程运行时*/
    {
        printf("This is the NO.1 child process\n");
        /*对子进程关闭读端*/
        close(p[0]);
        printf("NO.1 Child process writing msg..\n");
        write(p[1], msg1, MSGSIZE);                 /*向管道写信息*/
        printf("NO.1 Child process finish writing..\n");
    } else {
        pid2 = fork();                /*第二个子进程在判断为父进程后再创建.这样可以避免了在第一进程中再次创建下一级的一个子进程*/
        if (pid2 < 0)
            printf("Error.NO.2 fock call fail\n");
        else if (pid2 == 0)                 /*当第二个子进程运行时*/
        {
            printf("This is the NO.2 child process\n");
            /*对子进程关闭读端*/
            close(p[0]);
            printf("NO.2 Child process writing msg..\n");
            write(p[1], msg2, MSGSIZE);
            printf("NO.2 Child process finish writing..\n");
        } else {
            printf("This is the parent process\n");
            /*对父进程关闭写端*/
            close(p[1]);
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
        }
    }
    printf("Fork end.\n\n");
    // 这里不能return 0返回
    exit(0);
}
