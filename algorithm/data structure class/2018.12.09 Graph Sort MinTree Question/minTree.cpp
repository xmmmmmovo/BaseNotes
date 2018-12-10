/**
 * 最小生成树
 * language : c author : xmmmmmovo
 * 2018-12-09
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define INFIN 5000 // 定义无穷为5000 
#define MAX 20 // 定义最大节点是20个
using namespace std;

int i = 0, j = 0, k = 0; // 循环变量
typedef char vertextype; // 顶点类型
typedef int edgetype; // 权值类型
typedef struct
{
    vertextype vexs[MAX]; // 点
    edgetype edges[MAX][MAX]; // 边
    int nos, edgeNum; // 顶点, 边数
}Mgraph;

Mgraph *graph = new Mgraph();

void create(int c){
    FILE *fp = fopen("./data.txt", "r");
    int weight = 0;

    if(fp){
        fscanf(fp, "%d %d", &graph->nos, &graph->edgeNum); // 读取点跟边的数量
        for(i = 0;i < graph->nos;i++){
            fscanf(fp, "%1s", &graph->vexs[i]);
        }

        for(i = 0;i < graph->nos;i++){ // 初始化矩阵
            for(j = 0;j < graph->nos; j++){
                graph->edges[i][j] = (i == j ? 0 : INFIN);
            }
        }

        for(k = 0;k < graph->edgeNum; k++){ // 进行文件读取输入
            fscanf(fp, "%d %d %d", &i, &j, &weight);
            graph->edges[i][j] = weight;
            if(c == 0)
                graph->edges[j][i] = weight;
        }
        fclose(fp);
    }else{
        graph->nos = 0;
    } 
}

typedef struct edgedata
{
    int begin, end; // 点序号
    int length; // 边长
}edge;

void prim(){
    edge tree[MAX - 1]; // 用来存树
    edge x;
    int d, min, j, k, s, v;

    for(v = 0; v < graph->nos - 1; v++){
        tree[v].begin = 0;
        tree[v].end = v + 1;
        tree[v].length = graph->edges[0][v + 1];
    }

    for(k = 0; k < graph->nos - 2; k++){
        min = tree[k].length;
        s = k;
        for(j = k + 1; j < graph->nos - 1; j++){ // 选取最短路径
            if(tree[j].length < min){
                min = tree[j].length;
                s = j;
            }
        }
        v = tree[s].end; // 入点就是最短路径点的末端点

        // 交换把最短路径放到第一点后面
        x = tree[s];
        tree[s] = tree[k];
        tree[k] = x;

        // 交换完k就是最短边
        for(j = k + 1; j < graph->nos - 1; j++){ // 更新两栖边的信息
            d = graph->edges[v][tree[j].end];
            if(d < tree[j].length){
                tree[j].length = d;
                tree[j].begin = v;
            }
        }
    } 
    printf("min is:\n");
    for(j = 0; j < graph->nos - 1; j++){
        printf("%c --- %c %d\n", graph->vexs[tree[j].begin], 
        graph->vexs[tree[j].end], tree[j].length);

        printf("root: %c\n", graph->vexs[0]);
    }
}

void kruskal(){
    
}

int main(int argc, char const *argv[])
{
    create(0);
    prim();

    system("pause");   
    return 0;
}