#include "singer.h" //������
#include "unidirectionalLinkedlist.h" //����������
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime> // ʱ��������ͷ�ļ�
#include <vector>
#include <string>
#include <fstream> // �ļ���д��
#include <iomanip> // io��
#include <windows.h> // win APIͷ�ļ�

int i = 0, j = 0;//ѭ������
int chooseFr = 0, chooseSe = 0; // һ���˵�ѡ�� �����˵�ѡ��
bool ifList = false; // �жϵ�ǰ�Ƿ��Ѿ�������
List<Singer> *singerList; // ������Ϣ����

using namespace std; //std�����ռ�

//���ñ���ɫ��������ɫ
void initbkftColor(){ 
    system("color 70");
}

//һ���˵�
void menusFr(){
    cout << "/************************************/\n";
    cout << "/********* 1. ¼�����������Ϣ     \n";
    cout << "/********* 2. ��ʾ���в���ѡ����Ϣ \n";
    cout << "/********* 3. ��ѯ����������Ϣ     \n";
    cout << "/********* 4. �޸���ί���         \n";
    cout << "/********* 5. ��ѯ��������         \n";
    cout << "/********* 6. �����������         \n";
    cout << "/********* 7. ����¼�����������Ϣ  \n";
    cout << "/********* 8. �����θ�����Ϣ�����ļ���  \n";
    cout << "/********* 9. ���ļ��ж�ȡ������Ϣ  \n";
    cout << "/********* 0. �˳�ϵͳ             \n";
    cout << "/************************************/\n\n";// ѡ��, �ļ���д, ����д
    cout << "\b����������Ҫ�Ĺ��ܣ�"; // \bʹ������Ĳ�������
    // system("pause");
    cin >> chooseFr;
}

//�����˵�
void menusSe(){
    cout << "/************************************/\n";
    cout << "/********* 1. ���ֱ��     \n";
    cout << "/********* 2. ����     \n";
    cout << "/********* 3. ����ƽ����     \n";
    cout << "/************************************/\n\n";
    cout << "\b����������Ҫ��ѯ�ķ�����"; // \bʹ������Ĳ�������
    // system("pause");
    cin >> chooseSe;
}

void headers(){
    for(i = 0;i < 37;i++){
        cout << "*";
    }

    cout << '\n' << "*   ��ӭʹ�ø��ֱ����ɼ�����ϵͳ!   *" << '\n';
    cout << "*   �������д���ǵ�С���ѧ��ɶ!   *" << '\n';// 

	for(i = 1;i < 38;i++){
        cout << "*";
    }
    cout << '\n';
}

//��ʼ��
void init(){
    initbkftColor();// ��ʼ����ɫ
    headers(); // ��ͷ
    menusFr(); // һ���˵�
}

void createList(){
    int singerNumber;
    string singerName; 
    double *singerGrade;
    // singerList = new List<Singer>();
    cout << "\b��������ֱ��(0�����):" << '\n';
    while(scanf("%d", &singerNumber)){ // ������ 0����
        if(singerNumber == 0){
            break;
        }

        cout << "\b�������������:" << '\n';
        cin >> singerName;

        singerGrade = new double[10]; // ÿ�����·���ռ�
        cout << "\b��������ֳɼ�:" << '\n';
        for(i = 0;i < 10;i++){
            cin >> singerGrade[i];
        }

        singerList->insertInBack(Singer(singerNumber, singerName, singerGrade)); // ����

        cout << "\n" << "\b��������ֱ��(0�����):" << "\n";
    }
    ifList = true;
}

void showSinger(Singer singer){
    cout << "\b���ֱ��:" << singer.getNumber() 
    << "\n\b��������:" << singer.getName() << "\n\b���ֳɼ�:";

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

// ����Ϊʲô����ģ������ֳ���������д
// ԭ����ǲ�֪��singer�����ĸ�ƥ��
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
    int number; // ���ֱ��
    string name; //��������
    double arg; // ���ֳɼ�

    menusSe();
    switch(chooseSe){
        case 1:
            cout << "\b��������Ҫ��ѯ�ĸ��ֱ�ţ�" << '\n';
            cin >> number;
            ans = searchSingerByNumber(number);
            break;
        case 2:
            cout << "\b��������Ҫ��ѯ�ĸ���������" << '\n';
            cin >> name;
            ans = searchSingerByName(name);
            break;
        case 3:
            cout << "\b��������Ҫ��ѯ�ĸ���ƽ���ɼ���" << '\n';
            cin >> arg;
            ans = searchSingerByArg(arg);
            break;
    }

    return ans;
}

void changeGrade(){
    vector<Singer> ans;
    double changeBe, changeAf;// ����ǰ��
    ans = searchSinger();
    cout << "\b��������Ҫ���ĵĳɼ���\n";
    cin >> changeBe;
    cout << "\b����������Ҫ���ĺ�ĳɼ���\n"; 
    cin >> changeAf;
    
    // foreachѭ��
    for(Singer singer : ans){
        singer.changeGradle(changeBe, changeAf);
    }

}

// ���ɷ��ظ�0-9����
// �����ڲ��ı�ԭ˳�������½�������ݳ�˳��
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
    bool isChanged = true; // �ж��Ƿ���н���
    while(isChanged){
        singerList->begin();
        singerList->next();
        isChanged = false; // �ȶ���Ϊû����
        while(singerList->next()){
            if(singerList->nowNodeData().getArg() < singerList->beforeNodeData().getArg()){
                singerList->swapWithBefore();
                isChanged = true;
            }
        }
    }
}

void sortSingerList(){
    sortList(); // ����������
    showAll();
}

void nullWay(){
    system("cls");
    cout << "\bû�������Ĺ���!\n";
    cout << "\bû�������Ĺ���!\n";
    cout << "\bû�������Ĺ���!\n";
    system("pause");
    getchar(); // ������ַ�����
    system("cls");
    // system("pause");
}

void appendSinger(){
    cout << "\b���ڽ�����Ӳ���\n";
    createList();
}

void writeInFile(){
    string filename;
    cout << "\b�������ļ�����\n";
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
        cout << "\b���ѳɹ��浽�ļ����У�";
    }else{
        cout << "\b�ļ�д��ʧ�ܣ������ԣ�";
    }
    fout.close(); //�ر��ļ�������
}

void readFile(){
    string filename;
    int singerNumber;
    string singerName; 
    double *singerGrade;

    ifstream fin;
    cout << "\b�������ļ�����\n";
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
        cout << "\b�ļ���ȡ��ϣ�";
    }else{
        cout << "\b�ļ���ʧ�ܣ������Ƿ��б��ļ���";
    }

    fin.close();
}

void readFromFile(){
    char ch;
    system("cls");
    if(ifList){
        getchar();
        cout << "\b�����������! �����Ƿ񸲸�ԭ����?";
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
                    cout << "\b�����������! �����Ƿ񸲸�ԭ����?";
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
                    system("cls"); // ���۸�ʲô������
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
                    cout << "\b���ȴ�������";
                over();
                break;
            case 3:
                system("cls");
                if(ifList)
                    searchSinger();
                else
                    cout << "\b���ȴ�������";
                over();
                break;
            case 4:
                system("cls");
                if(ifList)
                    changeGrade();
                else
                    cout << "\b���ȴ�������";
                over();
                break;
            case 5:
                system("cls");
                if(ifList)
                    appearanceList();
                else
                    cout << "\b���ȴ�������";
                over();
                break;
            case 6:
                system("cls");
                if(ifList)
                    sortSingerList();
                else
                    cout << "\b���ȴ�������";
                over();
                break;
            case 7:
                system("cls");
                if(ifList)
                    appendSinger();
                else
                    cout << "\b���ȴ�������";
                over();
                break;
            case 8:
                system("cls");
                if(ifList)
                    writeInFile();
                else
                    cout << "\b���ȴ�������";
                over();
                break;
            case 9:
                readFromFile();
                over();
                break;
            case 0:
                return 0; // �˳�����
                break;
            default:
                nullWay(); // ����
                menusFr();
                break;
        }
    }

    system("pause");
    return 0;
}