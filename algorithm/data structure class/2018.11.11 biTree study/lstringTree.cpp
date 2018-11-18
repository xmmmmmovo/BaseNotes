/**
 * 中序穿线二叉树
 * language：C++ author：xmmmmmovo
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
    treenode *tempnode = NULL;
    
    while(node || !buffer.empty()){
        if(node){
            buffer.push(node);
            node->ltag = node->left?false:true;//如果左节点存在则存放false
            node->rtag = node->right?false:true;//如果右节点存在则存放false
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
            buffer.pop();//现在是buffer顶是上个节点
            node = node->right;
        }
    }
}

//中序遍历中序穿线二叉树
treenode *insuccnode(treenode *node){
    treenode *noderight = NULL;//存储测试右节点穿线
    if(node->rtag){//表明有无右节点
        return node->right;//返回子树最后的右节点 防止死循环
    }else{
        noderight = node->right;
        while(!noderight->ltag){
            noderight = noderight->left;
        }//左子树搜寻
        return node;
    }
}

void inthrtree(treenode *node){
    while(!node->ltag){
        node = node->left;
    }//先找出最左下的节点(第一个节点)
    do{
        printf("%c ", node->data);
        node = insuccnode(node);//寻找下一个节点
    }while(node);
}

int main(int argc, char const *argv[])
{
    treenode *root;
    
    //输入123##4##5##
    root = createTree();
    inthreading(root);
    inthrtree(root);

    system("pause");
    return 0;
}
