/**
 * 图的生成和遍历
 * */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//#define m 20
typedef struct node{     //边结点
      int adjvex; //序号              
      struct node *next; //指向边下一个节点
}edgenode;
typedef struct vnode{       //头结点 
      char vertex;   
      edgenode *firstedge; 
}vertexnode;
typedef struct{   
       vertexnode adjlist[20]; /*存放头结点的顺序表*/
       int n,e;  
}adjgraph;

int visited[20];

//表的创建
void creatgraph(adjgraph *g, FILE *fp, int c){
    int i, j, k; //循环变量
    edgenode *s, *s2; //连接用节点
    fscanf(fp, "%d %d", &g->n, &g->e); // n顶点数, e边数

    //录入点信息
    for(i = 0;i < g->n; i++){
        fscanf(fp, "%1s", &g->adjlist[i].vertex); //%1s相当于%c
        g->adjlist[i].firstedge = NULL; //边表置为空
    }

    //录入边信息
    for(k=0; k<g->e; k++){
        fscanf(fp, "%d %d", &i, &j);
        s = (edgenode *)malloc(sizeof(edgenode)); //分配节点链式空间
        s->adjvex = j;
        s->next = g->adjlist[i].firstedge;
        g->adjlist[i].firstedge = s;

        if(c == 0){ //因为是无向图 所以需要进行逆向连接
            // s = (edgenode *)malloc(sizeof(edgenode));   
            // s->adjvex = i; //刚好与上面的i j反过来
            // s->next = g->adjlist[j].firstedge;
            // g->adjlist[i].firstedge = s;      
            s2 = (edgenode*)malloc(sizeof(edgenode));
            s2->adjvex = i;
            s2->next = g->adjlist[j].firstedge;
            g->adjlist[j].firstedge = s2;
        }
    }		
}

//深度优先遍历
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
//深度优先遍历 in
void previsited(adjgraph g) 
{
    int i;
    for(i=0;i<g.n;i++)
        visited[i]=0; //均设置成未遍历	
    for(i=0;i<g.n;i++)	
        if(!visited[i]) //如果未遍历 则遍历	
            dfs(g,i);
}

//广度优先搜索
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
//广度优先搜索 in 
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
     * 给出测试文本数据（书上测试用数据
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
    fp = fopen("./data.txt", "r");//相对路径 代表当前文件夹（相较于本文件
    if(fp){
        adjgraph g;
        creatgraph(&g, fp, 0);//0则是无向图
        fclose(fp);

        printf("深度优先遍历结果：");
        previsited(g) ;
        printf("\n");

        printf("广度优先遍历结果：");
        prebfs(g);	
    }else{
        printf("file error!\n");
    }

    system("pause");
    return 0;
 }