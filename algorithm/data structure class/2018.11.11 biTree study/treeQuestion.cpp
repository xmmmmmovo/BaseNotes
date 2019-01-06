/**
 * 2018-11-11 二叉树课后题目
 * language: C/C++ author: xmmmmmovo
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
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

//前序遍历(非递归)
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
            i++;
        }
    }

    i++;
    printf("\n");
}

//前序遍历(递归)
void preorder2(treeNode *node){
    if(node){
        printf("%c ", node->nodeCharctar);
        preorder2(node->left);
        preorder2(node->right);
    }else{
        i++;
    }
}

//中序遍历
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

//后序搜索(非递归)
stack<treeNode *> postorderSearch(treeNode *node, char searchChar){
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
                if(node->nodeCharctar == searchChar)
                    return buffer;
                node = NULL;
            }else{
                node = buffer.top();
                node = node->right;
                tag.top() = true;
            }
        }
    }

    printf("\n");
    return buffer;
}

stack<treeNode *> reserve(stack<treeNode *> buffer){
    stack <treeNode *> reservenodes;
    while(!buffer.empty()){
        reservenodes.push(buffer.top());
        buffer.pop();
    }
    
    return reservenodes;
}

treeNode *searchFather(treeNode *root, char fr, char se){
    stack<treeNode *> frnodes = reserve(postorderSearch(root, fr));
    stack<treeNode *> senodes = reserve(postorderSearch(root, se));
    treeNode *node;

    while(!(frnodes.empty() || senodes.empty())){
        if(frnodes.top() == senodes.top()){
            node = frnodes.top();
        }
        frnodes.pop();
        senodes.pop();
    }

    return node;
}

int main(int argc, char const *argv[])
{
    treeNode *root, *tempNode;
    char fr, se;
    
    //输入123##4##5##
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
    tempNode = searchFather(root, fr, se);
    if(tempNode){
        printf("%c\n", tempNode->nodeCharctar);
    }else{
        printf("NULL\n");
    }

    system("pause");
    return 0;
}