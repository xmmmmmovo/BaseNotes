#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string"
#include "malloc.h"
#include "iostream"
#define ok 1
#define error 0
#define overflow -1
#define LIST_INIT_SIZE 100
#define LISTINCREAMENT 10 

using namespace std;
typedef char **huffmancode;
huffmancode hc;

typedef struct{
	unsigned int data;
	int parent, lchild, rchild;
}htnode, *huffmantree;
huffmantree ht;

void printHuffmanTree(huffmantree HT, char ch[],int a){
printf("\n");
printf("data, weight, parent, lchild, rchild\n");
for (int i = 0; i < 2 * a - 1; i++){
if (i >= a){
printf("   , %5d, %5d, %5d, %5d\n", HT[i].data, HT[i].parent, HT[i].lchild, HT[i].rchild);
}
else{
printf("  %c, %5d, %5d, %5d, %5d\n", ch[i], HT[i].data, HT[i].parent, HT[i].lchild, HT[i].rchild);
}
}
printf("\n");
}

void select(huffmantree HT, int k, int &s1, int &s2){
//假设s1对应的权值总是<=s2对应的权值
unsigned int tmp = 10000, tmpi = 0;
for (int i = 0; i < k; i++){
	if (!HT[i].parent){//parent必须为0
		if (tmp > HT[i].data){
			tmp = HT[i].data;//tmp最后为最小的data
			tmpi = i;
		}
	}
}
s1 = tmpi;

tmp = 10000;
tmpi = 0;
for (int i = 0; i < k; i++){
if ((!HT[i].parent) && i != s1){//parent为0
if (tmp > HT[i].data){
tmp = HT[i].data;
tmpi = i;
}
}
}
s2 = tmpi;
}
void createHuffmanTree(huffmantree &HT, int *w, int n){
if (n <= 1)
return;
//对树赋初值
for (int i = 0; i <= n; i++){//HT前n个分量存储叶子节点，他们均带有权值
HT[i].data = w[i];
HT[i].lchild = 0;
HT[i].parent = 0;
HT[i].rchild = 0;
}
for (int i=n; i < 2*n-1; i++){//HT后m-n个分量存储中间结点，最后一个分量显然是整棵树的根节点
HT[i].data = 0;
HT[i].lchild = 0;
HT[i].parent = 0;
HT[i].rchild = 0;
}
//开始构建哈夫曼树，即创建HT的后m-n个结点的过程，直至创建出根节点。用哈夫曼算法
for (int i = n ; i < 2*n-1; i++){
int s1, s2;
select(HT, i , s1, s2);//在HT[1...i-1]里选择parent为0的且权值最小的2结点，其序号分别为s1,s2，parent不为0说明该结点已经参与构造了，故不许再考虑
HT[s1].parent = i;
HT[s2].parent = i;
HT[i].lchild = s1;
HT[i].rchild = s2;
HT[i].data = HT[s1].data + HT[s2].data;
}
}

void encodingHuffmanCode(huffmantree HT, int a){
char *tmp;
tmp=(char *)malloc(a*sizeof(char *));
tmp[a - 1] = '\0';//编码的结束符
int start, c, f;
for (int i = 0; i < a; i++){//对于第i个待编码字符即第i个带权值的叶子节点
start = a - 1;//编码生成以后，start将指向编码的起始位置
c = i;
f = HT[i].parent;
while (f){//f!=0,即f不是根节点的父节点
if (HT[f].lchild == c){
tmp[--start] = '0';
}
else{
tmp[--start] = '1';
}
c = f;
f = HT[f].parent;
}
hc[i] = (char *)malloc((a - start)*sizeof(char));//每次tmp的后n-start个位置有编码存在
strcpy(hc[i], &tmp[start]);//将tmp的后n-start个元素分给H[i]指向的的字符串
}
}

void printHuffmanCoding(huffmancode HC, char *ch,int a){
printf("\n");
for (int i = 0; i < a; i++){
printf("%c:%s\n", ch[i], HC[i]);
}
printf("\n");
}

void creat(int &a, char *b){
int q[LIST_INIT_SIZE];
cout << "请输入您要创建的哈夫曼树字符个数：";
cin >> a;
for (int i = 0; i < a; i++){
cin >> b[i];
}
for (int i = 0; i < a - 1; i++){
for (int j = i + 1; j < a;){
if (b[i] == b[j]){
for (int q = j; q < a - 1; q++){
b[q] = b[q + 1];
}
a--;
}
else
j++;
}
}
cout << "经检验您输入未重复的字符" << a << "个" << "\n";
cout << "请您输入这些字符的权值：" << "\n";
for (int i = 0; i < a; i++){
cout << "请输入字符" << b[i] << "的权值";
cin >> q[i];
}
cout << "开始创建！" << "\n";
cout << "开始申请空间！" << "\n";
ht = (htnode*)malloc((2 * a - 1)*sizeof(huffmantree));
if (!ht){
cout << "申请失败！" << "\n";
exit(overflow);
}
else
createHuffmanTree(ht, q, a);
cout << "创建成功！" << "\n";
printHuffmanTree(ht, b, a);
cout << "开始编码！" << "\n";
hc = (huffmancode)malloc(a*sizeof(char*));
encodingHuffmanCode(ht, a);
cout << "编码完毕!开始打印编码表！" << "\n";
printHuffmanCoding(hc, b, a);
cout << "打印完毕！";
}

void DeCoding(huffmantree HT, int n, char *ch){
int len, i = 0, p;
int k1, k2;
char str[1000];
cout << "Enter a seious of 01 code " << endl;
cin >> str;
len = strlen(str);
cout << len << endl;
cout << "The relevant chars is :" << endl;
for (i = 0; i < len;++i){
p = 2 * n - 1;
while (HT[p].lchild != 0 || HT[p].rchild != 0){
if (str[i] == '0'){
p = HT[p].lchild;
}
if (str[i] == '1'){ 
p = HT[p].rchild;
}

}
if (p < n){
cout << ch[p];
i--;
}

}
cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
int a;
char b[LIST_INIT_SIZE];
creat(a, b);
DeCoding(ht, a, b);
return 0;
}