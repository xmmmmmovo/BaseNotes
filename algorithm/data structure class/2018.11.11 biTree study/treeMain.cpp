/**
 * 2018-11-11 �����������ɺͱ���(�����㷨)
 * language: C author: xmmmmmovo
*/
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;//stack����������ռ�

typedef struct treeNode{
    char nodeCharctar;
    treeNode *left;
    treeNode *right;
}treeNode;
int i = 0;

//ǰ�����ɶ�����
treeNode *createTree(){
    treeNode *node;
    char ch;

    if((ch = getchar()) == '#'){
        node =  NULL;
    }else{
        node = (treeNode *)malloc(sizeof(treeNode));
        node->nodeCharctar = ch;
        node->left = createTree();
        node->right = createTree();
    }

    return node;
}

//ǰ�����
void preorder(treeNode *node){
    stack<treeNode *> buffer;//�洢�����ڵ�
    
    while(!buffer.empty() || node){
        if(node){
            printf("%c ", node->nodeCharctar);
            buffer.push(node);
            node = node->left;
        }else if(!buffer.empty()){
            node = buffer.top()->right;
            buffer.pop();
        }
    }

    printf("\n");
}

//�������
void inorder(treeNode *node){
    stack<treeNode *> buffer;
    
    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            node = node->left;
        }else{
            node = buffer.top();
            buffer.pop();
            printf("%c ", node->nodeCharctar);
            node = node->right;
        }
    }

    printf("\n");
}

//�������
void postorder(treeNode *node){
    stack<treeNode *> buffer;
    stack<bool> tag;

    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            tag.push(false);
            node = node->left;
        }else{
            if(tag.top()){
                tag.pop();
                node = buffer.top();
                buffer.pop();
                printf("%c ", node->nodeCharctar);
                node = NULL;
            }else{
                node = buffer.top();
                node = node->right;
                tag.top() = true;
            }
        }
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    treeNode *root;

    //����123##4##5##
    root = createTree();
    preorder(root);
    inorder(root);
    postorder(root);

    system("pause");
    return 0;
}