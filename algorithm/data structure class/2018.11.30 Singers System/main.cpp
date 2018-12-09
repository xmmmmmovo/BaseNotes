#include "singer.h" //歌手类
#include "unidirectionalLinkedlist.h" //单向链表类
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime> // 时间和随机数头文件
#include <vector>
#include <string>
#include <fstream> // 文件读写流
#include <iomanip> // io流
#include <windows.h> // win API头文件

int i = 0, j = 0;//循环变量
int chooseFr = 0, chooseSe = 0; // 一级菜单选择 二级菜单选择
bool ifList = false; // 判断当前是否已经有链表
List<Singer> *singerList; // 歌手信息链表

using namespace std; //std命名空间

//设置背景色和字体颜色
void initbkftColor(){ 
    system("color 70");
}

//一级菜单
void menusFr(){
    cout << "/************************************/\n";
    cout << "/********* 1. 录入参赛歌手信息     \n";
    cout << "/********* 2. 显示所有参赛选手信息 \n";
    cout << "/********* 3. 查询参赛歌手信息     \n";
    cout << "/********* 4. 修改评委打分         \n";
    cout << "/********* 5. 查询出场次序         \n";
    cout << "/********* 6. 比赛结果排序         \n";
    cout << "/********* 7. 继续录入参赛歌手信息  \n";
    cout << "/********* 8. 将本次歌手信息存入文件中  \n";
    cout << "/********* 9. 从文件中读取歌手信息  \n";
    cout << "/********* 0. 退出系统             \n";
    cout << "/************************************/\n\n";// 选做, 文件读写, 中午写
    cout << "\b请输入你需要的功能！"; // \b使输出中文不是乱码
    // system("pause");
    cin >> chooseFr;
}

//二级菜单
void menusSe(){
    cout << "/************************************/\n";
    cout << "/********* 1. 歌手编号     \n";
    cout << "/********* 2. 姓名     \n";
    cout << "/********* 3. 歌手平均分     \n";
    cout << "/************************************/\n\n";
    cout << "\b请输入你需要查询的方法！"; // \b使输出中文不是乱码
    // system("pause");
    cin >> chooseSe;
}

void headers(){
    for(i = 0;i < 37;i++){
        cout << "*";
    }

    cout << '\n' << "*   欢迎使用歌手比赛成绩管理系统!   *" << '\n';
    cout << "*   这里随便写你们的小组跟学号啥!   *" << '\n';// 

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
    double *singerGrade;
    // singerList = new List<Singer>();
    cout << "\b请输入歌手编号(0则结束):" << '\n';
    while(scanf("%d", &singerNumber)){ // 输入编号 0结束
        if(singerNumber == 0){
            break;
        }

        cout << "\b请输入歌手姓名:" << '\n';
        cin >> singerName;

        singerGrade = new double[10]; // 每次重新分配空间
        cout << "\b请输入歌手成绩:" << '\n';
        for(i = 0;i < 10;i++){
            cin >> singerGrade[i];
        }

        singerList->insertInBack(Singer(singerNumber, singerName, singerGrade)); // 插入

        cout << "\n" << "\b请输入歌手编号(0则结束):" << "\n";
    }
    ifList = true;
}

void showSinger(Singer singer){
    cout << "\b歌手编号:" << singer.getNumber() 
    << "\n\b歌手姓名:" << singer.getName() << "\n\b歌手成绩:";

    for(i = 0;i < 10;i++){
        cout << singer.getGrade(i) << " ";
    }

    cout << "\n\n";
}

void showAll(){
    singerList->begin();
    // singerList.next();

    while(singerList->next()){
        showSinger(singerList->nowNodeData());
    }
}

// 这里为什么不用模板类而分成三个方法写
// 原因就是不知道singer类中哪个匹配
vector<Singer> searchSingerByNumber(int number){
    Singer singer;
    vector<Singer> ans;
    singerList->begin();
    while(singerList->next()){
        singer = singerList->nowNodeData();
        if(singer.getNumber() == number){
            showSinger(singer);
            ans.emplace_back(singer);
        }
    }

    return ans;
}

vector<Singer> searchSingerByName(string name){
    vector<Singer> ans;
    Singer singer;
    singerList->begin();
    while(singerList->next()){
        singer = singerList->nowNodeData();
        if(singer.getName() == name){
            showSinger(singer);
            ans.emplace_back(singer);
        }
    }

    return ans;
}

vector<Singer> searchSingerByArg(double arg){
    vector<Singer> ans;
    Singer singer;
    singerList->begin();
    while(singerList->next()){
        singer = singerList->nowNodeData();
        if(singer.getArg() == arg){
            showSinger(singer);
            ans.emplace_back(singer);
        }
    }

    return ans;
}

vector<Singer> searchSinger(){
    vector<Singer> ans;
    int number; // 歌手编号
    string name; //歌手姓名
    double arg; // 歌手成绩

    menusSe();
    switch(chooseSe){
        case 1:
            cout << "\b请输入想要查询的歌手编号：" << '\n';
            cin >> number;
            ans = searchSingerByNumber(number);
            break;
        case 2:
            cout << "\b请输入想要查询的歌手姓名：" << '\n';
            cin >> name;
            ans = searchSingerByName(name);
            break;
        case 3:
            cout << "\b请输入想要查询的歌手平均成绩：" << '\n';
            cin >> arg;
            ans = searchSingerByArg(arg);
            break;
    }

    return ans;
}

void changeGrade(){
    vector<Singer> ans;
    double changeBe, changeAf;// 更改前后
    ans = searchSinger();
    cout << "\b请输入需要更改的成绩：\n";
    cin >> changeBe;
    cout << "\b请输入你想要更改后的成绩：\n"; 
    cin >> changeAf;
    
    // foreach循环
    for(Singer singer : ans){
        singer.changeGradle(changeBe, changeAf);
    }

}

// 生成非重复0-9数组
// 可以在不改变原顺序的情况下进行随机演出顺序
vector<int> randVector(int num){
    vector<int> res;
    res.clear();
    res.reserve(num);
    srand((int)time(0));
    for(i = 0;i < num;i++){
        res.emplace_back(i);
    }

    int p1, p2;
    int temp;

    while(--num){
        p1 = num;
        p2 = rand() % num;
        temp = res[p1];
        res[p1] = res[p2];
        res[p2] = temp;
    }

    return res;
}


void appearanceList(){
    vector<int> random = randVector(singerList->getLength());
    for(int ct : random){
        showSinger(singerList->getPosition(ct));
    }
}

void sortList(){    
    if(singerList->getLength() == 1){
        showAll();
        return;
    }
    singerList->begin();
    bool isChanged = true; // 判断是否进行交换
    while(isChanged){
        singerList->begin();
        singerList->next();
        isChanged = false; // 先定义为没交换
        while(singerList->next()){
            if(singerList->nowNodeData().getArg() < singerList->beforeNodeData().getArg()){
                singerList->swapWithBefore();
                isChanged = true;
            }
        }
    }
}

void sortSingerList(){
    sortList(); // 排序主函数
    showAll();
}

void nullWay(){
    system("cls");
    cout << "\b没有这样的功能!\n";
    cout << "\b没有这样的功能!\n";
    cout << "\b没有这样的功能!\n";
    system("pause");
    getchar(); // 解决吃字符问题
    system("cls");
    // system("pause");
}

void appendSinger(){
    cout << "\b现在进行添加操作\n";
    createList();
}

void writeInFile(){
    string filename;
    cout << "\b请输入文件名：\n";
    cin >> filename;
    ofstream fout;
    fout.open(filename + ".txt");
    if(fout){
        singerList->begin();
        while(singerList->next()){
            Singer singer = singerList->nowNodeData();
            fout << singer.getNumber() << " " << singer.getName();
            for(i = 0;i < 10;i++){
                fout << " " << singer.getGrade(i);
            }
            fout << "\n";
        }
        cout << "\b您已成功存到文件当中！";
    }else{
        cout << "\b文件写入失败！请重试！";
    }
    fout.close(); //关闭文件输入流
}

void readFile(){
    string filename;
    int singerNumber;
    string singerName; 
    double *singerGrade;

    ifstream fin;
    cout << "\b请输入文件名：\n";
    cin >> filename;
    fin.open(filename + ".txt");

    if(fin){
        while(fin >> singerNumber){
            fin >> singerName;
            singerGrade = new double[10];
            for(i = 0;i < 10;i++){
                fin >> singerGrade[i];
            }

            singerList->insertInBack(Singer(singerNumber, singerName, singerGrade));
        }
        ifList = true;
        cout << "\b文件读取完毕！";
    }else{
        cout << "\b文件打开失败！请检查是否有本文件！";
    }

    fin.close();
}

void readFromFile(){
    char ch;
    system("cls");
    if(ifList){
        getchar();
        cout << "\b已有链表存在! 请问是否覆盖原链表?";
        ch = getchar();
        if(ch == 'y' || ch == 'Y'){
            delete singerList;
            singerList = new List<Singer>();
            readFile();
        }
    }else{
        singerList = new List<Singer>();
        readFile();
    }
}

void over(){
    system("pause");
    getchar();
    system("cls");
    menusFr();
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
                        singerList = new List<Singer>();
                        createList();
                        over();
                    }else{
                        over();
                    }
                }else{
                    system("cls"); // 无论干什么先清屏
                    singerList = new List<Singer>();
                    createList();
                    over();
                }
                break;
            case 2:
                system("cls");
                if(ifList)
                    showAll();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 3:
                system("cls");
                if(ifList)
                    searchSinger();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 4:
                system("cls");
                if(ifList)
                    changeGrade();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 5:
                system("cls");
                if(ifList)
                    appearanceList();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 6:
                system("cls");
                if(ifList)
                    sortSingerList();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 7:
                system("cls");
                if(ifList)
                    appendSinger();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 8:
                system("cls");
                if(ifList)
                    writeInFile();
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 9:
                readFromFile();
                over();
                break;
            case 0:
                return 0; // 退出程序
                break;
            default:
                nullWay(); // 其他
                menusFr();
                break;
        }
    }

    system("pause");
    return 0;
}