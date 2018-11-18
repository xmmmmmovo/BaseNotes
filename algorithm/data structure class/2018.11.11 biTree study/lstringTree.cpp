/**
 * �����߶�����
 * language��C++ author��xmmmmmovo
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
    treenode *tempnode = NULL;
    
    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            node->ltag = node->left?false:true;//�����ڵ��������false
            node->rtag = node->right?false:true;//����ҽڵ��������false
            tempnode = node->left;
            if(prev){
                if(prev->rtag){
                    prev->right = node;//
                }
                if(node->ltag){
                    node->left = prev;
                }
            }
            prev = node;
            node = tempnode;
        }else{
            node = buffer.top();
            buffer.pop();//������buffer�����ϸ��ڵ�
            node = node->right;
        }
    }
}

//������������߶�����
treenode *insuccnode(treenode *node){
    treenode *noderight = NULL;//�洢�����ҽڵ㴩��
    if(node->rtag){//���������ҽڵ�
        return node->right;//�������������ҽڵ� ��ֹ��ѭ��
    }else{
        noderight = node->right;
        while(!noderight->ltag){
            noderight = noderight->left;
        }//��������Ѱ
        return node;
    }
}

void inthrtree(treenode *node){
    while(!node->ltag){
        node = node->left;
    }//���ҳ������µĽڵ�(��һ���ڵ�)
    do{
        printf("%c ", node->data);
        node = insuccnode(node);//Ѱ����һ���ڵ�
    }while(node);
}

int main(int argc, char const *argv[])
{
    treenode *root;
    
    //����123##4##5##
    root = createTree();
    inthreading(root);
    inthrtree(root);

    system("pause");
    return 0;
}
