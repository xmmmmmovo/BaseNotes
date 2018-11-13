/**
 * 2018-11-11 �������κ���Ŀ
 * language: C author: xmmmmmovo
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
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

//ǰ�����(�ǵݹ�)
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
            i++;
        }
    }

    i++;
    printf("\n");
}

//ǰ�����(�ݹ�)
void preorder2(treeNode *node){
    if(node){
        printf("%c ", node->nodeCharctar);
        preorder2(node->left);
        preorder2(node->right);
    }else{
        i++;
    }
}

//�������
char inorder(treeNode *node){
    stack<treeNode *> buffer;
    char endchar;
    
    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            node = node->left;
        }else{
            node = buffer.top();
            buffer.pop();
            printf("%c ", node->nodeCharctar);
            endchar = node->nodeCharctar;
            node = node->right;
        }
    }

    printf("\n");
    return endchar;
}

treeNode *searchFather(treeNode *node, char fr, char se){
    stack<treeNode *> buffer;//�洢�����ڵ�

    //�ڵ�
    treeNode *frNode;
    treeNode *seNode;
    
    while(!buffer.empty() || node){
        if(node){
            buffer.push(node);
            node = node->left;
        }else if(!buffer.empty()){
            node = buffer.top()->right;
            buffer.pop();
        }
    }

    return node;
}

int main(int argc, char const *argv[])
{
    treeNode *root;
    char fr, se;
    
    //����123##4##5##
    root = createTree();
    getchar();
    preorder(root);
    printf("%d\n", i/2);
    i = 0;
    preorder2(root);
    printf("\n%d\n", i/2);
    printf("%c\n", inorder(root));
    fr = getchar();
    getchar();
    se = getchar();
    printf("%c\n", searchFather(root, fr, se)->nodeCharctar);

    system("pause");
    return 0;
}