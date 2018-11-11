/**
 * 2018-11-11 二叉树的生成和遍历(非递归算法)
 * language: C author: xmmmmmovo
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>

typedef struct treeNode{
    char nodeCharctar;
    treeNode *left;
    treeNode *right;    
}treeNode;
char charctar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

treeNode *createTree(){
    treeNode *root;

    return root;
}

int main(int argc, char const *argv[])
{
    treeNode *root;

    root = createTree();

    system("pause");
    return 0;
}