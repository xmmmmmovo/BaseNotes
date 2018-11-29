/**
 * ͼ�����ɺͱ���
 * */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//#define m 20
typedef struct node{     //�߽��
      int adjvex; //���              
      struct node *next; //ָ�����һ���ڵ�
}edgenode;
typedef struct vnode{       //ͷ��� 
      char vertex;   
      edgenode *firstedge; 
}vertexnode;
typedef struct{   
       vertexnode adjlist[20]; /*���ͷ����˳���*/
       int n,e;  
}adjgraph;

int visited[20];

//��Ĵ���
void creatgraph(adjgraph *g, FILE *fp, int c){
    int i, j, k; //ѭ������
    edgenode *s, *s2; //�����ýڵ�
    fscanf(fp, "%d %d", &g->n, &g->e); // n������, e����

    //¼�����Ϣ
    for(i = 0;i < g->n; i++){
        fscanf(fp, "%1s", &g->adjlist[i].vertex); //%1s�൱��%c
        g->adjlist[i].firstedge = NULL; //�߱���Ϊ��
    }

    //¼�����Ϣ
    for(k=0; k<g->e; k++){
        fscanf(fp, "%d %d", &i, &j);
        s = (edgenode *)malloc(sizeof(edgenode)); //����ڵ���ʽ�ռ�
        s->adjvex = j;
        s->next = g->adjlist[i].firstedge;
        g->adjlist[i].firstedge = s;

        if(c == 0){ //��Ϊ������ͼ ������Ҫ������������
            // s = (edgenode *)malloc(sizeof(edgenode));   
            // s->adjvex = i; //�պ��������i j������
            // s->next = g->adjlist[j].firstedge;
            // g->adjlist[i].firstedge = s;      
            s2 = (edgenode*)malloc(sizeof(edgenode));
            s2->adjvex = i;
            s2->next = g->adjlist[j].firstedge;
            g->adjlist[j].firstedge = s2;
        }
    }		
}

//������ȱ���
void dfs(adjgraph g,int i)
{
    edgenode *p;
    printf(" %c ",g.adjlist[i].vertex);
    visited[i]=1;
    p=g.adjlist[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            dfs(g,p->adjvex);
        p=p->next;
    }		
} 
//������ȱ��� in
void previsited(adjgraph g) 
{
    int i;
    for(i=0;i<g.n;i++)
        visited[i]=0; //�����ó�δ����	
    for(i=0;i<g.n;i++)	
        if(!visited[i]) //���δ���� �����	
            dfs(g,i);
}

//�����������
void bfs(adjgraph g,int i) 
{
    int j;	
    edgenode *p;
    int queue[20];
    int front=0,rear=0;

    printf(" %c ",g.adjlist[i].vertex);
    visited[i]=1;
    queue[rear++]=i;

    while(rear>front)
    {
        j=queue[front++];
        p=g.adjlist[j].firstedge;
        while(p)
        {
            if(!visited[p->adjvex])
            {
                printf(" %c ",g.adjlist[p->adjvex].vertex);
                queue[rear++]=p->adjvex;	
                visited[p->adjvex]=1;
            }
            p=p->next;
        }         
    }		
}
//����������� in 
void prebfs(adjgraph g)
{
    int i;

    for(i=0;i<g.n;i++)
    visited[i]=0;

    for(i=0;i<g.n;i++)
    {
        if(!visited[i])	
        {
            //printf("---%d---\n",i);
            bfs(g,i);
        }
    }				
}

int main()
{
    FILE *fp;
    /**
     * ���������ı����ݣ����ϲ���������
     * 6 7
     * 012345
     * 0 1
     * 0 2
     * 1 3
     * 1 4
     * 2 5
     * 3 4
     * 4 5
    */
    fp = fopen("./data.txt", "r");//���·�� ����ǰ�ļ��У�����ڱ��ļ�
    if(fp){
        adjgraph g;
        creatgraph(&g, fp, 0);//0��������ͼ
        fclose(fp);

        printf("������ȱ��������");
        previsited(g) ;
        printf("\n");

        printf("������ȱ��������");
        prebfs(g);	
    }else{
        printf("file error!\n");
    }

    system("pause");
    return 0;
 }