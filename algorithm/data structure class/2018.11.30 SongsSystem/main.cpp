#include "singer.h" //歌手类
#include "unidirectionalLinkedlist.h" //单向链表类
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h> // win API头文件

int i = 0, j = 0;//循环变量
int chooseFr = 0, chooseSe = 0; // 一级菜单选择
bool ifList = false; // 判断当前是否已经有链表
List<Singer> *singerList; // 歌手信息链表

using namespace std; //std命名空间

//设置背景色和字体颜色
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

void menusSe(){
    
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

void createList(){
    int singerNumber;
    string singerName; 
    double *singerGrade = new double[10];
    singerList = new List<Singer>();
    cout << "\b请输入歌手编号(0则结束):" << '\n';
    while(scanf("%d", &singerNumber)){ // 输入编号 0结束
        if(singerNumber == 0){
            break;
        }

        cout << "\b请输入歌手姓名:" << '\n';
        cin >> singerName;

        cout << "\b请输入歌手成绩:" << '\n';
        for(i = 0;i < 10;i++){
            cin >> singerGrade[i];
        }

        singerList->insertInBack(Singer(singerNumber, singerName, singerGrade)); // 插入

        cout << "\b请输入歌手编号(0则结束):" << '\n';
    }

    system("cls");
    menusFr();
    ifList = true;
}

void showAll(){
    Singer singer;
    singerList->begin();
    // singerList.next();

    while(singerList->next()){
        singer = singerList->nowNodeData();
        cout << "\b歌手编号:" << singer.getNumber() 
        << "\n\b歌手姓名:" << singer.getName() << "\n\b歌手成绩:";

        for(i = 0;i < 10;i++){
            cout << singer.getGrade(i) << " ";
        }

        cout << "\n\n";
    }
}

void searchSinger(){

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
    char ch;
    init();

    while(1){
        switch(chooseFr){
            case 1:
                if(ifList){
                    getchar();
                    system("cls");
                    cout << "\b已有链表存在! 请问是否覆盖原链表?";
                    ch = getchar();
                    if(ch == 'y' || ch == 'Y'){
                        delete singerList;
                        createList();
                    }else{
                        system("cls");
                        menusFr();
                    }
                }else{
                    system("cls"); // 无论干什么先清屏
                    createList();
                }
                break;
            case 2:
                system("cls");
                showAll();
                system("pause");
                getchar();
                system("cls");
                menusFr();
                break;
            case 3:
                system("cls");
                searchSinger();
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