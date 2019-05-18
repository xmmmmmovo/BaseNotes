#include<iostream>
#include<string> 
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
using namespace std;

char p[100];
int m[100][100], s[100][100];
int n;
int w = 0;

void matrixchain()
{
	int i, r, j, k;
	memset(m, 0, sizeof(m));
	memset(s, 0, sizeof(s));//��ʼ������
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (r = 2; r <= n; r++)
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
}

void print(int i, int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
		return;
	}
	cout << "(";
	Sleep(1000);
	outtextxy(i * 120 + w * 5, 60, '<');
	outtextxy(j * 120 + 90 + w * 10, 60, '>');
	w++;
	print(i, s[i][j]);
	print(s[i][j] + 1, j);
	cout << ")";
}

int main()
{
	cout << "���������ĸ���n : " << endl;
	cin >> n;
	int i, j;
	cout << "����������ÿ����������������һ�������������" << endl;
	for (i = 0; i <= n; i++)
		cin >> p[i];
	initgraph(1400, 1400);   // ������ͼ���ڣ���СΪ 640x480 ����
	TCHAR s[100];
	for (int i = 1; i <= n; i++)
	{
		_stprintf(s, _T("%d"), i);
		outtextxy(i * 120 + 50, 60, 'A');
		outtextxy(i * 120 + 65, 60, '[');
		outtextxy(i * 120 + 70, 60, s);
		outtextxy(i * 120 + 80, 60, ']');
	}
	matrixchain();
	print(1, n);
	cout << endl;
	cout << "��С��������ֵΪ��" << m[1][n] << endl;
	_getch();
	closegraph();          // �رջ�ͼ����
	return 0;
}