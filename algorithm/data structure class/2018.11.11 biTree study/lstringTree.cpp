/**
 * �����߶�����
 * language��C++ author��xmmmmmovo
 * �ο���https://www.cnblogs.com/rocketfan/archive/2009/08/30/1556784.html
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>

using namespace std;

typedef struct treeNode
{
    char data;
    bool ltag = false, rtag = false;//��ʾ���ҽڵ��Ƿ����
    struct treeNode *left = NULL, *right = NULL;
}treenode;

//ǰ��������
treenode *createTree(){
    treenode *node;
    char ch;

    if((ch = getchar()) == '#'){
        node =  NULL;
    }else{
        node = new treenode();//����ռ�
        node->data = ch;
        node->left = createTree();
        node->right = createTree();
    }

    return node;
}

//����������(�ǵݹ��㷨)
void inthreading(treenode *node){
    stack<treenode *> buffer;
    treenode *prev = NULL;//��¼ǰ���ڵ�
    
    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            node = node->left;
        }else{
            node = buffer.top();
            if(!node->left){//�����޽ڵ� ���д���
                node->ltag = true;
                node->left = prev;
            }
            if(prev && !prev->right){//���ж��Ƿ��ǵ�һ���ڵ���ҽڵ� Ȼ���ж��Ƿ���
                prev->rtag = true;
                prev->right = node;
            }
            prev = node;
            buffer.pop();
            node = node->right;
        }
    }
}

//������������߶�����
void inthrtree(treenode *node){
    while(node){
        while(!node->ltag){//��������������½ڵ�
            node = node->left;
        }
        printf("%c ", node->data);
        while(node->rtag){
            node = node->right;
            printf("%c ", node->data);
        }
        node = node->right;
    }
}

int main(int argc, char const *argv[])
{
    treenode *root;
    
    //��������123##4##5##
    root = createTree();
    inthreading(root);
    inthrtree(root);

    system("pause");
    return 0;
}