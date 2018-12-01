#include "singer.h" //歌手类
#include "unidirectionalLinkedlist.h" //单向链表类
#include <iostream>
#include <cstdlib>
#include <windows.h> // win API头文件

int i = 0, j = 0;//循环变量
int chooseFr = 0, chooseSe = 0; // 一级菜单选择
using namespace std; //std命名空间

void initbkftColor(){ 
    system("color 70");
}

//一级菜单
void menusFr(){
    cout << "/********************************/\n";
    cout << "/********* 1. 录入参赛歌手信息     \n";
    cout << "/********* 2. 显示所有参赛选手信息 \n";
    cout << "/********* 3. 查询参赛歌手信息     \n";
    cout << "/********* 4. 修改评委打分         \n";
    cout << "/********* 5. 查询出场次数         \n";
    cout << "/********* 6. 比赛结果排序         \n";
    cout << "/********* 7. 退出系统             \n";
    cout << "/********************************/\n\n";
    cout << "\b请输入你需要的功能！"; // \b使输出中文不是乱码
    // system("pause");
    cin >> chooseFr;
}

void headers(){
    for(i = 0;i < 37;i++){
        cout << "*";
    }

    cout << '\n' << "*   欢迎使用歌手比赛成绩管理系统!   *" << '\n';
    cout << "**" << '\n';// 

	for(i = 1;i < 38;i++){
        cout << "*";
    }
    cout << '\n';
}

//初始化
void init(){
    initbkftColor();// 初始化颜色
    headers(); // 表头
    menusFr(); // 一级菜单
}

void nullWay(){
    system("cls");
    cout << "\b没有这样的功能!\n";
    cout << "\b没有这样的功能!\n";
    cout << "\b没有这样的功能!\n";
    system("pause");
    getchar(); // 解决吃字符问题
    system("cls");
    menusFr();
    // system("pause");
}

int main(int argc, char const *argv[]){
    List<Singer> singerList; // 歌手信息链表
    init();

    while(1){
        switch(chooseFr){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                return 0; // 退出程序
                break;
            default:
                nullWay(); // 其他
                break;
        }
    }

    system("pause");
    return 0;
}