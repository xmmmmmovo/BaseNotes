#include "singer.h" //������
#include "unidirectionalLinkedlist.h" //����������
#include <iostream>
#include <cstdlib>
#include <windows.h> // win APIͷ�ļ�

int i = 0, j = 0;//ѭ������
int chooseFr = 0, chooseSe = 0; // һ���˵�ѡ��
using namespace std; //std�����ռ�

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
    List<Singer> singerList; // ������Ϣ����
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