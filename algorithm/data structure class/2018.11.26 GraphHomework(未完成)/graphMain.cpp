/**
 * 图的生成与遍历
 * language: C + STL author: xmmmmmovo
*/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct Node
{
    int dep = 0;
    char charctar = '\0';
    struct Node *next = NULL;
}node;
int nodeNum = 0, length = 0;
int i = 0;

void createGraph(FILE *fp){
    vector<node> fgraph;
    fscanf(fp, "%d %d", nodeNum, length);
    char *chars = new char[nodeNum];
    fscanf(fp,"%s", chars);
    for(i = 0;i < length;i++){
        fgraph.emplace_back();
    }

    fclose(fp);
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("./data.txt", "w");
    if (fp){
        createGraph(fp);
    }else{
        printf("open error!\n");
    }
    
    system("pause");
    return 0;
}