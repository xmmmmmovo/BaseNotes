//
// Created by 13256 on 2019/12/4.
//
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
    pid_t pid1;
    pid_t pid2;
    pid1 = fork();    /*这里定义第一个子进程*/
    if (pid1 < 0)
        printf("创建进程1失败了!\n");
    else if (pid1 == 0)
        printf("子进程1fork成功!\n");
    else {
        pid2 = fork();           /*第二个子进程在判断为父进程后再创建.这样可以避免了在第一进程中再次创建下一级的一个子进程*/
        if (pid2 < 0)
            printf("创建进程二失败了!\n");
        else if (pid2 == 0)
            printf("子进程2fork成功!\n");
        else
            printf("这里是父进程\n");
    }
    printf("%d进程结束了!.\n\n", getpid());
    exit(0);
}

