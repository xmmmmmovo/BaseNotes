/**
 * 中序穿线二叉树
 * language：C++ author：xmmmmmovo
 * 参考：https://www.cnblogs.com/rocketfan/archive/2009/08/30/1556784.html
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>

using namespace std;

typedef struct treeNode
{
    char data;
    bool ltag = false, rtag = false;//提示左右节点是否存在
    struct treeNode *left = NULL, *right = NULL;
}treenode;

//前序生成树
treenode *createTree(){
    treenode *node;
    char ch;

    if((ch = getchar()) == '#'){
        node =  NULL;
    }else{
        node = new treenode();//分配空间
        node->data = ch;
        node->left = createTree();
        node->right = createTree();
    }

    return node;
}

//中序线索化(非递归算法)
void inthreading(treenode *node){
    stack<treenode *> buffer;
    treenode *prev = NULL;//记录前驱节点
    
    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            node = node->left;
        }else{
            node = buffer.top();
            if(!node->left){//左若无节点 进行穿线
                node->ltag = true;
                node->left = prev;
            }
            if(prev && !prev->right){//先判断是否是第一个节点的右节点 然后判断是否穿线
                prev->rtag = true;
                prev->right = node;
            }
            prev = node;
            buffer.pop();
            node = node->right;
        }
    }
}

//中序遍历中序穿线二叉树
void inthrtree(treenode *node){
    while(node){
        while(!node->ltag){//深度搜索到最左下节点
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
    
    //测试数据123##4##5##
    root = createTree();
    inthreading(root);
    inthrtree(root);

    system("pause");
    return 0;
}