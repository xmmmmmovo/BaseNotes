/**
 * 最小生成树
 * language : c author : xmmmmmovo
 * 2018-12-09
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstdbool>

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
    /**
     * 实验用数据
     * 
     * 6 10
     * ABCDEF
     * 0 1 10
     * 0 2 12
     * 0 4 15
     * 1 2 7
     * 1 3 5
     * 1 5 6
     * 2 4 12
     * 2 5 8
     * 3 5 6
     * 4 5 10
    */
    FILE *fp = fopen("./dataw.txt", "r");
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
    printf("min tree by prim is:\n");
    for(j = 0; j < graph->nos - 1; j++){
        printf("%c --- %c %d\n", graph->vexs[tree[j].begin], 
        graph->vexs[tree[j].end], tree[j].length);

        printf("root: %c\n", graph->vexs[0]);
    }
}

// 未优化快排
void qSort(edge edges[], int lo, int hi){
    edge x;
    int i = 0, j = 0, flag = 1;
    if(lo < hi){
        i = lo;
        j = hi;
        x = edges[i];
        while(i < j){
            while(i < j && x.length < edges[j].length)
                j--;
            if(i < j)
                edges[i++] = edges[j];
            while(i < j && x.length > edges[i].length)
                i++;
            if(i < j)
                edges[j--] = edges[i]; 
        }
        edges[i] = x;
        qSort(edges, lo, i - 1);
        qSort(edges, i + 1, hi);
    }
}

void getEdges(edge *edges){
    int i = 0, j = 0, k = 0;
    for(i = 0;i < graph->nos;i++){
        for(j = 0; j < i; j++){
            if(graph->edges[i][j] != 0 && graph->edges[i][j] < INFIN){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k++].length = graph->edges[i][j];
            }
        }
    }
}

void kruskal(){
    int i = 0, j = 0, k = 0, ltfl = 0;
    int cnvx[MAX]; // 寄存器
    edge edges[MAX * MAX]; // 存放所有边
    edge tree[MAX]; // 存放树信息
    getEdges(edges);
    qSort(edges, 0, graph->edgeNum - 1); // 升序排序

    for(i = 0;i < graph->edgeNum;i++){
        cnvx[i] = i; // 初始化
    }

    for(i = 0;i < graph->nos - 1;i++){
        while(cnvx[edges[k].begin] == cnvx[edges[k].end]){
            k++;
        }
        tree[i] = edges[k];
        ltfl = cnvx[edges[k].end];
        for(j = 0; j < graph->nos; j++){
            if(cnvx[j] == ltfl){
                cnvx[j] = cnvx[edges[k].begin];
            }
        }
        k++;
    }

    printf("min tree by kruskal is\n");
    for(j = 0; j < graph->nos - 1; j++){
        printf("%c --- %c %d\n", graph->vexs[tree[j].begin], 
        graph->vexs[tree[j].end], tree[j].length);
    }
}

typedef int path[MAX];
typedef int dist[MAX];
path p;
dist d;
// 单源最短路径
void dijkstra(int v0){
    bool finals[MAX];
    int i = 0, j = 0, k = 0, v = 0, min = 0, x = 0;
    // 1.初始化集合S与距离向量d
    for(v = 0; v < graph->nos; v++){
        finals[v] = false;
        d[v] = graph->edges[v0][v];
        p[v] = (d[v] < INFIN && d[v] != 0 ? v0 : -1); //-1代表无前驱节点
    }
    finals[v0] = true;
    d[v0] = 0; // 初始只有v0一个节点
    // 2.依次找出n-1个节点加入S中
    for(i = 0;i < graph->nos - 1;i++){ // 因为v0已经存在了所以-1个节点
        min = INFIN;
        for(k = 0; k < graph->nos; k++){
            if(!finals[k] && d[k] < min){
                v = k;
                min = d[k];
            }
        }
        printf("%c --- %d\n", graph->vexs[v], min);
        if(min == INFIN){
            return;
        }
        finals[v] = true;
        // 修改S与V-S中各节点的距离
        for(k = 0; k < graph->nos; k++){
            if(!finals[k] && (min + graph->edges[v][k] < d[k])){
                d[k] = min + graph->edges[v][k];
                p[k] = v;
            }
        }
    }
}

void print_gpd(path p, dist d){
    int st[MAX], i = 0, pre = 0, top = -1;
    for(i = 0;i < graph->nos;i++){
        printf("\ndistance: %d, path:", d[i]);
        st[++top] = i;
        pre = p[i];
        while(pre != -1){
            st[++top] = pre;
            pre = p[pre];
        }
        while(top > 0){
            printf("%d", st[top--]);
        }
    }
}

typedef int dist1[MAX][MAX];
typedef int path1[MAX][MAX];
path1 p1;
dist1 d1;
// 所有顶点对的最短路径
void Floyd(){
    int i = 0, j = 0, k = 0;
    for(i = 0;i < graph->nos;i++){
        for(j = 0; j < graph->nos; j++){
            d1[i][j] = graph->edges[i][j];
            p1[i][j] = (i != j && d1[i][j] < INFIN ? i : -1);
        }
    }
    for(k = 0; k < graph->nos; k++){
        for(i = 0;i < graph->nos;i++){
            if(d1[i][j] > (d1[i][k] + d1[i][j])){
                d1[i][j] = d1[i][k] + d1[i][j];
                p1[i][j] = k;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int v0 = 0;

    create(0);
    prim();
    printf("\n");
    kruskal();
    printf("\n");
    scanf("%d", &v0);
    dijkstra(v0);
    print_gpd(p, d);
    printf("\n");
    Floyd();
    for(i = 0; i < graph->nos; i++){
        printf("%d", i);
        print_gpd(p1[i], d1[i]);
        printf("\n");
    }

    system("pause");   
    return 0;
}