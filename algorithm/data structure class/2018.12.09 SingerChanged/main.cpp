#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime> // 时间和随机数头文件
#include <vector>
#include <string>
#include <fstream> // 文件读写流
#include <iomanip> // io流
#include <windows.h> // win API头文件

using namespace std; //std命名空间

class Person
{
public:
    string singerName; //stl里面的string存储姓名
};

class Singer: public Person
{
    public:
        Singer();
        Singer(int singerNumber, string singerName, double *singerGrade);
        ~Singer();
        void sortGrade();
        int getNumber();
        string getName();
        double getGrade(int);
        double getArg();
        double getSum();
        void changeGradle(int, double);

    private:
        int singerNumber = 0; //歌手编号
        bool ifSorted = false; // 判断是否已经排序
        double *singerFinGrade;
        double *singerGrade; //用简单的数组存储成绩
        double arg = 0; // 平均数储存(掐头去尾)
        double sum = 0; // 成绩总和
        void caculateArg();
        int sort(int lo, int hi); // 次排序
};

Singer::Singer(){
    singerNumber = 0;
}

//构造函数
Singer::Singer(int singerNumber, string singerName, double *singerGrade){
    int i = 0;
    this->singerNumber = singerNumber;
    this->singerName = singerName;
    this->singerGrade = singerGrade;
    singerFinGrade = new double[10];
    for(i = 0;i < 10;i++){
        singerFinGrade[i] = singerGrade[i];
    }
    caculateArg();
}

//析构函数
Singer::~Singer(){
    // delete singerGrade; // 防止内存泄漏
}

int Singer::getNumber(){ // getter方法
    return singerNumber;
}

string Singer::getName(){ // getter方法
    return singerName;
}

double Singer::getGrade(int i){ // getter方法
    return singerFinGrade[i];
}

double Singer::getArg(){ // getter方法
    return arg;
}

void Singer::caculateArg(){
    int i = 0;
    if(ifSorted){
        for(i = 1;i < 9;i++){
            sum += singerGrade[i];
        }
        arg = sum/8;
    }else{
        sortGrade();
        caculateArg();
    }

}

int Singer::sort(int lo, int hi){
    int last = lo;
    double temp;

    while(++lo <= hi){
        if(singerGrade[lo - 1] > singerGrade[lo]){
            last = lo;

            temp = singerGrade[lo - 1];
            singerGrade[lo - 1] = singerGrade[lo];
            singerGrade[lo] = temp;
        }
    }

    return last;
}

// 成绩内排序 从小到大(小数据所以用了冒泡)
void Singer::sortGrade(){
    int lo = 0, hi = 9;
    while(lo < (hi = sort(lo, hi))); // 排序本体

    ifSorted = true;
}

void Singer::changeGradle(int pos, double num){
    double temp = singerFinGrade[pos - 1];
    singerFinGrade[pos - 1] = num;
    for(int i = 0;i < 10;i++){
        if(singerFinGrade[pos - 1] == singerGrade[i]){
            singerGrade[i] = num;
        }
    }
}

class List: public Singer
{
public:
    List();
    ~List();
    void begin();//迭代器返回头结点
    void end();//迭代器返回尾节点
    bool next(); // 后移迭代器
    Singer nowNodeData(); // 获取迭代器data
    Singer nextNodeData(); // 获取下一迭代器data
    Singer beforeNodeData(); // 获取上一个的节点
    Singer getPosition(int); // 获取某节点数值
    void swapWithBefore();
    int getLength(); // 返回长度
    void insertInFort(Singer);//头结点后插入
    void insertInBack(Singer);//尾节点插入

private:
    typedef struct nodeList{
        Singer data;
        nodeList *succ = NULL;//后继 如果定义成private会造成析构函数无法运行
    } node;
    node *iterator;//迭代器 每次插入后迭代器指针指向插入位置
    node *beforeIterator;
    node *header;//头结点
    node *trailer;//尾结点
    int count = 0;

    void printError();
};

//构造单向链表
List::List()
{
    header = new node();
    trailer = header;
    iterator = header;
    beforeIterator = NULL;
}

//同理 释放内存 防止内存泄漏
List::~List()
{
    node *temp;
    while(header->succ){
        temp = header;
        header = header->succ;
        delete temp;
    }
    delete header;
}

void List::begin(){
    iterator = header;
    beforeIterator = NULL;
}

void List::end(){
    iterator = trailer;
    beforeIterator = NULL; // 尾部也先判断成null
}

bool List::next(){
    beforeIterator = iterator;
    iterator = iterator->succ;
    return iterator ? true:false;
}

Singer List::nowNodeData(){
    return iterator->data;
}

Singer List::nextNodeData(){
    return iterator->succ->data;
}

Singer List::beforeNodeData(){
    return beforeIterator->data;
}

Singer List::getPosition(int pos){
    int length = 0;
    if(pos > count){ // 判断是否越界
        printError(); // 可能出现野指针问题 暂不知道解决方案
    }else{
        begin();
        iterator = iterator->succ;
        while(iterator){
            if(length == pos)
                return iterator->data;
            iterator = iterator->succ;
            length ++;
        }
    }
}

void List::swapWithBefore(){
    Singer temp;
    temp = iterator->data;
    iterator->data = beforeIterator->data;
    beforeIterator->data = temp;
}

int List::getLength(){
    return count;
}

void List::insertInFort(Singer data){
    node *insertNode = new node();
    insertNode->data = data;
    insertNode->succ = header->succ;

    header->succ = insertNode;
    iterator = insertNode;
    count++;
}

void List::insertInBack(Singer data){
    node *insertNode = new node();
    insertNode->data = data;

    trailer->succ = insertNode;
    trailer = insertNode;
    iterator = insertNode;
    count++;
}

void List::printError(){
    cout << "can'Singer find num or point\n";
}

int i = 0, j = 0;//循环变量
int chooseFr = -1, chooseSe = -1; // 一级菜单选择 二级菜单选择
bool ifList = false; // 判断当前是否已经有链表
List *singerList; // 歌手信息链表

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
    cout << "/********* 0. 退出     \n";
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
        ifList = true;
    }
    // ifList = true;
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
        case 0:
            break;
    }

    return ans;
}

void changeGrade(){
    vector<Singer> ans;
    int changeBe = 0;
    double changeAf = 0;// 更改前后
    ans = searchSinger();
    if(!ans.empty()){
        cout << "\b请输入需要更改的成绩的评委编号：\n";
        cin >> changeBe;
        cout << "\b请输入你想要更改后的成绩：\n"; 
        cin >> changeAf;
        
        // foreach循环
        for(Singer singer : ans){
            singer.changeGradle(changeBe, changeAf);
        }
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
            singerList = new List();
            readFile();
        }
    }else{
        singerList = new List();
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
                        singerList = new List();
                        createList();
                        over();
                    }else{
                        over();
                    }
                }else{
                    system("cls"); // 无论干什么先清屏
                    singerList = new List();
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
                if(ifList){
                    while(chooseSe){
                        system("cls");
                        searchSinger();
                        system("pause");
                    }
                    chooseSe = -1;   
                }
                else
                    cout << "\b请先创建链表！";
                over();
                break;
            case 4:
                system("cls");
                if(ifList){
                    while(chooseSe){
                        system("cls");
                        changeGrade();
                        system("pause");
                    }
                    chooseSe = -1;                    
                }
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