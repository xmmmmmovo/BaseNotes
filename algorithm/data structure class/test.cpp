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
//����s1��Ӧ��Ȩֵ����<=s2��Ӧ��Ȩֵ
unsigned int tmp = 10000, tmpi = 0;
for (int i = 0; i < k; i++){
	if (!HT[i].parent){//parent����Ϊ0
		if (tmp > HT[i].data){
			tmp = HT[i].data;//tmp���Ϊ��С��data
			tmpi = i;
		}
	}
}
s1 = tmpi;

tmp = 10000;
tmpi = 0;
for (int i = 0; i < k; i++){
if ((!HT[i].parent) && i != s1){//parentΪ0
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
//��������ֵ
for (int i = 0; i <= n; i++){//HTǰn�������洢Ҷ�ӽڵ㣬���Ǿ�����Ȩֵ
HT[i].data = w[i];
HT[i].lchild = 0;
HT[i].parent = 0;
HT[i].rchild = 0;
}
for (int i=n; i < 2*n-1; i++){//HT��m-n�������洢�м��㣬���һ��������Ȼ���������ĸ��ڵ�
HT[i].data = 0;
HT[i].lchild = 0;
HT[i].parent = 0;
HT[i].rchild = 0;
}
//��ʼ��������������������HT�ĺ�m-n�����Ĺ��̣�ֱ�����������ڵ㡣�ù������㷨
for (int i = n ; i < 2*n-1; i++){
int s1, s2;
select(HT, i , s1, s2);//��HT[1...i-1]��ѡ��parentΪ0����Ȩֵ��С��2��㣬����ŷֱ�Ϊs1,s2��parent��Ϊ0˵���ý���Ѿ����빹���ˣ��ʲ����ٿ���
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
tmp[a - 1] = '\0';//����Ľ�����
int start, c, f;
for (int i = 0; i < a; i++){//���ڵ�i���������ַ�����i����Ȩֵ��Ҷ�ӽڵ�
start = a - 1;//���������Ժ�start��ָ��������ʼλ��
c = i;
f = HT[i].parent;
while (f){//f!=0,��f���Ǹ��ڵ�ĸ��ڵ�
if (HT[f].lchild == c){
tmp[--start] = '0';
}
else{
tmp[--start] = '1';
}
c = f;
f = HT[f].parent;
}
hc[i] = (char *)malloc((a - start)*sizeof(char));//ÿ��tmp�ĺ�n-start��λ���б������
strcpy(hc[i], &tmp[start]);//��tmp�ĺ�n-start��Ԫ�طָ�H[i]ָ��ĵ��ַ���
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
cout << "��������Ҫ�����Ĺ��������ַ�������";
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
cout << "������������δ�ظ����ַ�" << a << "��" << "\n";
cout << "����������Щ�ַ���Ȩֵ��" << "\n";
for (int i = 0; i < a; i++){
cout << "�������ַ�" << b[i] << "��Ȩֵ";
cin >> q[i];
}
cout << "��ʼ������" << "\n";
cout << "��ʼ����ռ䣡" << "\n";
ht = (htnode*)malloc((2 * a - 1)*sizeof(huffmantree));
if (!ht){
cout << "����ʧ�ܣ�" << "\n";
exit(overflow);
}
else
createHuffmanTree(ht, q, a);
cout << "�����ɹ���" << "\n";
printHuffmanTree(ht, b, a);
cout << "��ʼ���룡" << "\n";
hc = (huffmancode)malloc(a*sizeof(char*));
encodingHuffmanCode(ht, a);
cout << "�������!��ʼ��ӡ�����" << "\n";
printHuffmanCoding(hc, b, a);
cout << "��ӡ��ϣ�";
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