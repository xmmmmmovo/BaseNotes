#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

// ���ݽṹ��
typedef struct DATA
{
    char ch = '1'; // �ַ�
    int weights = 0; // Ȩֵ
}node;

/* ���������Ľṹ�� */
typedef struct stHuNode
{
    node data; //����Ȩֵ���ַ�
    struct stHuNode* lchild = NULL, *rchild = NULL; // ���Һ��ӽڵ�
}HUNODE;


/*
* �ҳ�Ȩֵ��������,��С������Ȩֵ�±�
* ������Σ�HUNODE *pArray[] ��Žڵ��ָ������
            int n ���������Ԫ�ظ���
            int* p1 �����СȨֵ���±�
            int* p2 ��ŵڶ�СȨֵ���±�
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
        /* ��ǰ���±��������нڵ��*/
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
* �������ܣ�������������
* ������Σ�int* a Ȩֵ����
           int n ������������ж��ٸ�����
*/
HUNODE* createHuTree(node* a, int n) 
{
    int index = 0;

    int fir_small = 0, sec_small = 0;

    /* ����һ��ָ������,�����100 */
    HUNODE *pArray[100];
    HUNODE *pNewNode = NULL;


    /* �ȴ���n��root�ڵ�*/
    memset(pArray,0,sizeof(HUNODE)*n);
    for(index = 0; index < n; index++)
    {
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data = a[index];
        pNewNode->lchild = NULL;
        pNewNode->rchild = NULL;

        /* ������ڵ�����ָ��������ȥ */
        pArray[index] = pNewNode;
    }

    /* ������������ */
    for(index = 0; index < n-1; index++)
    {
        /* fir_small �����СȨֵ���±�  sec_small��ŵڶ���С��Ȩֵ�±�*/
        findSmallData(pArray,n,&fir_small,&sec_small);

        /* ����ڵ��ڴ� */
        pNewNode = (HUNODE*)malloc(sizeof(HUNODE));
        memset(pNewNode,0,sizeof(HUNODE));

        pNewNode->data.weights = pArray[fir_small]->data.weights + pArray[sec_small]->data.weights;

        /* ��С�������ӣ��ڶ�С�����Һ��� */
        pNewNode->lchild = pArray[fir_small];
        pNewNode->rchild = pArray[sec_small];

        /* ���µĽڵ���뵽ָ����������ȥ */
        pArray[fir_small] = NULL;
        pArray[sec_small] = pNewNode;

    }
    return pNewNode;
}

/* ǰ������ö����� */
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
 * ���ڱ����������
*/
void saveHuffMainTree(HUNODE* root){
    stack<HUNODE *> buffer;//�洢�����ڵ�
    HUNODE *node = root;

    if (files){
        while(!buffer.empty() || node){
            if(node){ // ǰ�����
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
 * ���ڶ�ȡ��������
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
        printf("�������ĸ���!\n");
        scanf("%d", &n);
        node *nodes = (node *)malloc(sizeof(node) * n); // �ַ���
        for(i = 0;i < n;i++){ // ѭ������ڵ�
            getchar(); // �Իس���
            scanf("%c %d", &nodes[i].ch, &nodes[i].weights);
        }
        
        /* ������������ */
        root = createHuTree(nodes,n);

        /* ǰ����� */
        preOrderHuffMan(root);
        printf("\n");
        files = fopen(filename, "w"); // ���Ȩֵ
        saveHuffMainTree(root);
    }

    system("pause");
    return 0;
}
