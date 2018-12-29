#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

// 数据结构体
typedef struct DATA
{
    char ch = '1'; // 字符
    int weights = 0; // 权值
}node;

/* 哈夫曼树的结构体 */
typedef struct stHuNode
{
    node data; //存有权值跟字符
    struct stHuNode* lchild = NULL, *rchild = NULL; // 左右孩子节点
}HUNODE;


/*
* 找出权值数组里面,最小的两个权值下标
* 函数请参：HUNODE *pArray[] 存放节点的指针数组
            int n 数组里面的元素个数
            int* p1 存放最小权值的下标
            int* p2 存放第二小权值的下标
*/
int findSmallData(HUNODE *pArray[] ,int n,int* p1, int* p2)
{
    int index = 0;
    int fir_small = 0xffff, sec_small = 0xffff;

    if(pArray == NULL)
    {
        return 1;
    }

    for(index = 0; index < n; index++)
    {
        /* 当前的下标下面是有节点的*/
        if(pArray[index] != NULL)
        {
            if(pArray[index]->data.weights < fir_small)
            {
                sec_small = fir_small;
                fir_small = pArray[index]->data.weights;

                *p2 = *p1;
                *p1 = index;                
            }
            else if(pArray[index]->data.weights < sec_small)
            {
                sec_small = pArray[index]->data.weights;
                *p2 = index;
            }
        }       
    }

    return 0;
}

/*
* 函数功能：构建哈夫曼树
* 函数请参：int* a 权值数组
           int n 这个数组里面有多少个数据
*/
HUNODE* createHuTree(node* a, int n) 
{
    int index = 0;

    int fir_small = 0, sec_small = 0;

    /* 定义一个指针数组,最大是100 */
    HUNODE *pArray[100];
    HUNODE *pNewNode = NULL;


    /* 先创建n个root节点*/
    memset(pArray,0,sizeof(HUNODE)*n);
    for(index = 0; index < n; index++)
    {
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data = a[index];
        pNewNode->lchild = NULL;
        pNewNode->rchild = NULL;

        /* 把这个节点存放在指针数组中去 */
        pArray[index] = pNewNode;
    }

    /* 构建哈夫曼树 */
    for(index = 0; index < n-1; index++)
    {
        /* fir_small 存放最小权值的下标  sec_small存放第二个小的权值下标*/
        findSmallData(pArray,n,&fir_small,&sec_small);

        /* 分配节点内存 */
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data.weights = pArray[fir_small]->data.weights + pArray[sec_small]->data.weights;

        /* 最小的是左孩子，第二小的是右孩子 */
        pNewNode->lchild = pArray[fir_small];
        pNewNode->rchild = pArray[sec_small];

        /* 把新的节点放入到指针数组里面去 */
        pArray[fir_small] = NULL;
        pArray[sec_small] = pNewNode;

    }
    return pNewNode;
}

/* 前序遍历该二叉树 */
void preOrderHuffMan(HUNODE* root)
{
    if(root)
    {
        printf("%c  %d  ", root->data.ch, root->data.weights);
        preOrderHuffMan(root->lchild);
        preOrderHuffMan(root->rchild);
    }
}

FILE *files;

/**
 * 用于保存哈夫曼树
*/
void saveHuffMainTree(HUNODE* root){
    stack<HUNODE *> buffer;//存储遍历节点
    HUNODE *node = root;

    if (files){
        while(!buffer.empty() || node){
            if(node){ // 前序遍历
                fprintf(files, "%c%d", node->data.ch, node->data.weights);
                buffer.push(node);
                node = node->lchild;
            }else{
                fprintf(files, "#");
                node = buffer.top()->rchild;
                buffer.pop();
            }
        }
    } else {
        printf("saveFileError!\n");
    }
}

/**
 * 用于读取哈夫曼树
*/
HUNODE* readHaffmanTree(){
    HUNODE *node;
    char ch;
    int wei;

    fscanf(files, "%c", &ch);
    if(ch == '#'){
        node =  NULL;
    }else{
        node = (HUNODE *)malloc(sizeof(HUNODE));
        node->data.ch = ch;
        fscanf(files, "%d", &wei);
        node->data.weights = wei;
        node->lchild = readHaffmanTree();
        node->rchild = readHaffmanTree();
    }

    return node;
}

int main()
{
    int n = 0, i = 0;
    char filename[] = "data.txt";
    HUNODE* root = NULL;
    if(files = fopen(filename, "r")){
        root = readHaffmanTree();
        preOrderHuffMan(root);
    }else{
        printf("请输入点的个数!\n");
        scanf("%d", &n);
        node *nodes = (node *)malloc(sizeof(node) * n); // 字符数
        for(i = 0;i < n;i++){ // 循环输入节点
            getchar(); // 吃回车符
            scanf("%c %d", &nodes[i].ch, &nodes[i].weights);
        }
        
        /* 构建哈夫曼树 */
        root = createHuTree(nodes,n);

        /* 前序遍历 */
        preOrderHuffMan(root);
        printf("\n");
        files = fopen(filename, "w"); // 存放权值
        saveHuffMainTree(root);
    }

    system("pause");
    return 0;
}
