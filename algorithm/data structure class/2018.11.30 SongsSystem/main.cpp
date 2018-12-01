#include "singer.h" //������
#include "unidirectionalLinkedlist.h" //����������
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h> // win APIͷ�ļ�

int i = 0, j = 0;//ѭ������
int chooseFr = 0, chooseSe = 0; // һ���˵�ѡ��
bool ifList = false; // �жϵ�ǰ�Ƿ��Ѿ�������
List<Singer> singerList; // ������Ϣ����

using namespace std; //std�����ռ�

//���ñ���ɫ��������ɫ
void initbkftColor(){ 
    system("color 70");
}

//һ���˵�
void menusFr(){
    cout << "/********************************/\n";
    cout << "/********* 1. ¼�����������Ϣ     \n";
    cout << "/********* 2. ��ʾ���в���ѡ����Ϣ \n";
    cout << "/********* 3. ��ѯ����������Ϣ     \n";
    cout << "/********* 4. �޸���ί���         \n";
    cout << "/********* 5. ��ѯ��������         \n";
    cout << "/********* 6. �����������         \n";
    cout << "/********* 7. �˳�ϵͳ             \n";
    cout << "/********************************/\n\n";
    cout << "\b����������Ҫ�Ĺ��ܣ�"; // \bʹ������Ĳ�������
    // system("pause");
    cin >> chooseFr;
}

void headers(){
    for(i = 0;i < 37;i++){
        cout << "*";
    }

    cout << '\n' << "*   ��ӭʹ�ø��ֱ����ɼ�����ϵͳ!   *" << '\n';
    cout << "**" << '\n';// 

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
    double *singerGrade = new double[10];
    while(scanf("%d", &singerNumber)){
        if(singerNumber == 0){
            break;
        }

        cin >> singerName;
        for(i = 0;i < 10;i++){
            cin >> singerGrade[i];
        }

        

        singerList.insertInBack(Singer(singerNumber, singerName, singerGrade)); // ����
    }

    ifList = true;
}

void nullWay(){
    system("cls");
    cout << "\bû�������Ĺ���!\n";
    cout << "\bû�������Ĺ���!\n";
    cout << "\bû�������Ĺ���!\n";
    system("pause");
    getchar(); // ������ַ�����
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
                    cout << "\b�����������! �����Ƿ񸲸�ԭ����?";
                    ch = getchar();
                    if(ch == 'y' || ch == 'Y'){
                        delete &singerList;
                        createList();
                    }else{
                        system("cls");
                        menusFr();
                    }
                }else{
                    system("cls"); // ���۸�ʲô������
                    createList();
                }
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
                return 0; // �˳�����
                break;
            default:
                nullWay(); // ����
                break;
        }
    }

    system("pause");
    return 0;
}