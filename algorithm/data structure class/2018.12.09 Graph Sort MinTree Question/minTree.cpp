/**
 * ��С������
 * language : c author : xmmmmmovo
 * 2018-12-09
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define INFIN 5000 // ��������Ϊ5000 
#define MAX 20 // �������ڵ���20��
using namespace std;

int i = 0, j = 0, k = 0; // ѭ������
typedef char vertextype; // ��������
typedef int edgetype; // Ȩֵ����
typedef struct
{
    vertextype vexs[MAX]; // ��
    edgetype edges[MAX][MAX]; // ��
    int nos, edgeNum; // ����, ����
}Mgraph;

Mgraph *graph = new Mgraph();

void create(int c){
    FILE *fp = fopen("./data.txt", "r");
    int weight = 0;

    if(fp){
        fscanf(fp, "%d %d", &graph->nos, &graph->edgeNum); // ��ȡ����ߵ�����
        for(i = 0;i < graph->nos;i++){
            fscanf(fp, "%1s", &graph->vexs[i]);
        }

        for(i = 0;i < graph->nos;i++){ // ��ʼ������
            for(j = 0;j < graph->nos; j++){
                graph->edges[i][j] = (i == j ? 0 : INFIN);
            }
        }

        for(k = 0;k < graph->edgeNum; k++){ // �����ļ���ȡ����
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
    int begin, end; // �����
    int length; // �߳�
}edge;

void prim(){
    edge tree[MAX - 1]; // ��������
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
        for(j = k + 1; j < graph->nos - 1; j++){ // ѡȡ���·��
            if(tree[j].length < min){
                min = tree[j].length;
                s = j;
            }
        }
        v = tree[s].end; // ���������·�����ĩ�˵�

        // ���������·���ŵ���һ�����
        x = tree[s];
        tree[s] = tree[k];
        tree[k] = x;

        // ������k������̱�
        for(j = k + 1; j < graph->nos - 1; j++){ // �������ܱߵ���Ϣ
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