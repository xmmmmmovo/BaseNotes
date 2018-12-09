/**
 * 最小生成树
 * language : c++ author : xmmmmmovo
 * 2018-12-09
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define INFIN -1 // 定义无穷为-1
#define MAX 20 // 定义最大节点是20个
using namespace std;

int i = 0, j = 0, k = 0; // 循环变量
typedef char vertextype; // 顶点类型
typedef int edgetype; // 权值类型
typedef struct
{
    vertextype vexs[MAX];
    edgetype edges[MAX][MAX];
    int nos, edgeNum; // 顶点, 边数
}Mgraph;

Mgraph *graph;

void create(int c){
    FILE *fp = fopen("./data.txt", "rw");
    int weight = 0;

    if(fp){
        fscanf(fp, "%d%d", &graph->nos, &graph->edgeNum); // 读取点跟边的数量
        for(i = 0;i < graph->nos;i++){
            fscanf(fp, "%1s", &graph->vexs[i]);
        }
        for(i = 0;i < graph->nos;i++){ 
            for(j = 0;j < graph->nos; j++){
                graph->edges[i][j] = i == j ? 0 : INFIN;
            }
        }
        for(k = 0;k < graph->edgeNum; k++){
            fscanf(fp, "%d%d%d", &i, &j, &weight);
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
    int begin, end; // 定点序号
    int length; // 边长
}edge;

void prim(){
    edge tree[MAX - 1];
    edge x;
    int d, min, j, k, s, v;

    for(v = 0; v < graph->nos; v++){
        tree[v - 1].begin = 0;
        tree[v - 1].end = v;
        tree[v - 1].length = graph->edges[0][v];
    }

    for(k = 0; k < graph->nos - 2; k++){
        min = tree[k].length;
        s = k;
        for(j = k + 1; j < graph->nos - 1; j++){
            if(tree[j].length < min){
                min = tree[j].length;
                s = j;
            }
        }
        v = tree[s].end; // 把min当成入点

        x = tree[s];
        tree[s] = tree[k];

        for(j = k + 1; j < graph->nos - 1; j++){
            d = graph->edges[v][tree[j].end];
            if(d < tree[j].length){
                tree[j].length = d;
                tree[j].begin = v;
            }
        }
    }
    printf("min生成树是:\n");
    for(j = 0; j < graph->nos - 1; j++){
        printf("%c --- %c %d\n", graph->vexs[tree[j].begin], 
        graph->vexs[tree[j].end], tree[j].length);

        printf("根节点是: %c\n", graph->vexs[0]);
    }
}

int main(int argc, char const *argv[])
{
    create(0);
    prim();

    system("pause");   
    return 0;
}