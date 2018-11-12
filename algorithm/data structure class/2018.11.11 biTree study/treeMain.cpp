/**
 * 2018-11-11 二叉树的生成和遍历(迭代算法)
 * language: C author: xmmmmmovo
*/
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;//stack所需的命名空间

typedef struct treeNode{
    char nodeCharctar;
    treeNode *left;
    treeNode *right;
}treeNode;
int i = 0;

//前序生成二叉树
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

//前序遍历
void preorder(treeNode *node){
    stack<treeNode *> buffer;//存储遍历节点
    
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

//中序遍历
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

//后序遍历
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

    //输入123##4##5##
    root = createTree();
    preorder(root);
    inorder(root);
    postorder(root);

    system("pause");
    return 0;
}