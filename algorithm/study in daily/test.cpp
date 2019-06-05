
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#define M 25   //迷宫的规模
using namespace std;
 
class Grid{
public:
    bool cell, dig;
};
//迷宫格子类型，记录了是否被挖过
Grid maze[M][M];
stack<int> row_s, col_s;
//用来存放路径的栈
void Init(){
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            maze[i][j].dig=false;
            if(i%2!=0 && j%2!=0)
                maze[i][j].cell=true;
        }
    }
    row_s.push(1);    col_s.push(1);
    srand(time(0));
}
//初始化迷宫格子
int DirRand(){
    vector <int> dirlist;        //用来记录可选择的方向
    int result=0;
    int row=row_s.top(), col=col_s.top();
    //0 up, 1 down, 2 left, 3 right
    if(row-2>0 && !maze[row-2][col].dig) dirlist.push_back(0);
    if(row+2<M-1 && !maze[row+2][col].dig) dirlist.push_back(1);
    if(col-2>0 && !maze[row][col-2].dig) dirlist.push_back(2);
    if(col+2<M-1 && !maze[row][col+2].dig) dirlist.push_back(3);
    if(dirlist.size()==0) result=-1;
    else result=dirlist[rand()%((int)dirlist.size())];
    return result;
}
//判断周围情况，没有可挖的格子时返回-1
void GenMaze(){
    while(!row_s.empty() && !col_s.empty()){
        int dir=DirRand();
        int row=row_s.top(), col=col_s.top();
        if(dir!=-1){     //前进
            if(dir==0){
                maze[row-2][col].dig=maze[row-1][col].dig=true;
                row_s.push(row-2);  col_s.push(col);
            }else if(dir==1){
                maze[row+2][col].dig=maze[row+1][col].dig=true;
                row_s.push(row+2);  col_s.push(col);
            }else if(dir==2){
                maze[row][col-2].dig=maze[row][col-1].dig=true;
                row_s.push(row);    col_s.push(col-2);
            }else if(dir==3){
                maze[row][col+2].dig=maze[row][col+1].dig=true;
                row_s.push(row);    col_s.push(col+2);
            }
        }else{
            row_s.pop();    col_s.pop();        //后退
        }
    }
}
 
void OutMaze(){      //输出迷宫
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(maze[i][j].cell || maze[i][j].dig)
            cout<<"  ";
            else cout<<"##";        //为了保证对齐，墙壁和道路宽都是2个字符
        }
        cout<<endl;
    }
}
 
int main(){
    Init();
    GenMaze();
    OutMaze();
    system("pause");
    return 0;
}