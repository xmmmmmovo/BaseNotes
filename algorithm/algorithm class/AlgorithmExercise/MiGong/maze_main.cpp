#include <opencv2/opencv.hpp>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <string>
#include <conio.h>

// #define MAIN_WINDOW "�Թ���"

using namespace std;

int n = 0;
vector<vector<char>> Maze;


class m_Point
{
public:
	int i;
	int j;
	int state;

	m_Point(){}
	m_Point(int i, int j, int state) {
		this->i = i;
		this->j = j;
		this->state = state;
	}

	bool operator==(const m_Point& maze) {
		if (this->i == maze.i &&
			this->j == maze.j &&
			this->state == maze.state) {
			return true;
		}

		return false;
	}
};

void show_maze() {
	system("cls");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << Maze[i][j];
		}
		cout << endl;
	}
}

void setDirFalse(bool &up, bool &down, bool &right, bool &left) {
	up = false;
	down = false;
	right = false;
	left = false;
}

// �����˾��������Թ�
void generate_maze(stack<m_Point> &MazeStack
	, vector<vector<m_Point>> &matrix) {


	int i = 3, j = 3;
	matrix[i][j].state = 1;

	m_Point temp;
	temp.i = i;
	temp.j = j;
	temp.state = 1;
	bool up = false, down = false, right = false, left = false;

	while (true)
	{
		temp.i = i;
		temp.j = j;
		int randNum = rand() % 4;
		switch (randNum)
		{
		case 0://��
			if (!up&&i > 2 && matrix[i - 2][j].state == 0)
			{
				MazeStack.push(temp);
				matrix[i - 2][j].state = 1;
				matrix[i - 1][j].state = 1;
				i = i - 2;
				setDirFalse(up, down, right, left);
			}
			else
				up = true;
			break;
		case 1://��
			if (!down&&i < n - 3 && matrix[i + 2][j].state == 0)
			{
				MazeStack.push(temp);
				matrix[i + 2][j].state = 1;
				matrix[i + 1][j].state = 1;
				i = i + 2;
				setDirFalse(up, down, right, left);
			}
			else
				down = true;
			break;
		case 2://��
			if (!left&&j > 2 && matrix[i][j - 2].state == 0)
			{
				MazeStack.push(temp);
				matrix[i][j - 2].state = 1;
				matrix[i][j - 1].state = 1;
				j = j - 2;
				setDirFalse(up, down, right, left);
			}
			else
				left = true;
			break;
		case 3://��
			if (!right&&j < n - 3 && matrix[i][j + 2].state == 0)
			{
				MazeStack.push(temp);
				matrix[i][j + 2].state = 1;
				matrix[i][j + 1].state = 1;
				j = j + 2;
				setDirFalse(up, down, right, left);
			}
			else
				right = true;
			break;
		}
		if (up&&down&&right&&left)//�����ǰ���ʽڵ��ĸ�����û�пɲ�Ľڵ㣬����
		{
			if (!MazeStack.empty())
			{
				i = MazeStack.top().i;
				j = MazeStack.top().j;
				MazeStack.pop();
				setDirFalse(up, down, right, left);
			}
			else//���ջΪ�յĻ��ͷ��أ���ʱ�Թ������Ѿ��������
			{
				return;
			}
		}
	}
}

/**
 * �����Թ�
 * �����˼·��Ҫ���ڸ���
 */
void create_maze() {
	stack<m_Point> MazeStack;
	// ��ʼ��
	vector<vector<m_Point>> Maze_G;
	for (int i = 0; i < n; ++i) {
		// vector<m_Point> v;
		// for (int j = 0; j < n; ++j) {
		// 	m_Point mp(0, 0, 0);
		// 	v.push_back(mp);
		// }
		Maze_G.emplace_back(vector<m_Point>(n, m_Point(0, 0, 0)));
	}

	generate_maze(MazeStack, Maze_G);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (Maze_G[i][j].state == 1) {
				Maze[i][j] = '.';
			}
		}
	}
}

bool in(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

/**
 * �ֶ����Թ�
 */
bool human_rounte() {
	char human = 'R';
	int x = 1, y = 1;
	int dx = 0, dy = 0;
	Maze[x][y] = human;
	show_maze();

	char ch;
	while (ch = getch()) {
		switch (ch) {
		case 'w':
			dx = x - 1, dy = y;
			if (in(dx, dy) && Maze[dx][dy] != '#') {
				Maze[dx][dy] = human;
				Maze[x][y] = '.';
				show_maze();
				// cvWaitKey(50);
				x = dx, y = dy;
			}

			if (x == n - 2 && y == n - 2) {
				return true;
			}
			break;
		case 's':
			dx = x + 1, dy = y;
			if (in(dx, dy) && Maze[dx][dy] != '#') {
				Maze[dx][dy] = human;
				Maze[x][y] = '.';
				show_maze();
				// cvWaitKey(50);
				x = dx, y = dy;
			}

			if (x == n - 2 && y == n - 2) {
				return true;
			}
			break;
		case 'a':
			dx = x, dy = y - 1;
			if (in(dx, dy) && Maze[dx][dy] != '#') {
				Maze[dx][dy] = human;
				Maze[x][y] = '.';
				show_maze();
				// cvWaitKey(50);
				x = dx, y = dy;
			}

			if (x == n - 2 && y == n - 2) {
				return true;
			}
			break;
		case 'd':
			dx = x, dy = y + 1;
			if (in(dx, dy) && Maze[dx][dy] != '#') {
				Maze[dx][dy] = human;
				Maze[x][y] = '.';
				show_maze();
				// cvWaitKey(50);
				x = dx, y = dy;
			}

			if (x == n - 2 && y == n - 2) {
				return true;
			}
			break;
		}
	}
	return false;
}

// ��Ҫ��dfs����
bool dfs(int x, int y, vector<vector<bool>> &vis) {
	if (x == n - 2 && y == n - 2) {
		return true;
	}

	vis[x][y] = 1;
	Maze[x][y] = 'm';

	int dx = x, dy = y + 1;
	if (in(dx, dy) && Maze[dx][dy] != '#' && !vis[dx][dy]) {
		show_maze();
		cvWaitKey(10);
		if (dfs(dx, dy, vis)) {
			return true;
		}
	}

	dx = x, dy = y - 1;
	if (in(dx, dy) && Maze[dx][dy] != '#' && !vis[dx][dy]) {
		show_maze();
		cvWaitKey(10);
		if (dfs(dx, dy, vis)) {
			return true;
		}
	}

	dx = x - 1, dy = y;
	if (in(dx, dy) && Maze[dx][dy] != '#' && !vis[dx][dy]) {
		show_maze();
		cvWaitKey(10);
		if (dfs(dx, dy, vis)) {
			return true;
		}
	}

	dx = x + 1, dy = y;
	if (in(dx, dy) && Maze[dx][dy] != '#' && !vis[dx][dy]) {
		show_maze();
		cvWaitKey(10);
		if (dfs(dx, dy, vis)) {
			return true;
		}
	}

	vis[x][y] = 0;
	Maze[x][y] = '.';
	// system("cls");
	show_maze();
	return false;
}

/**
 * �Զ����Թ�
 */
void auto_rounte() {
	// ���ʹ��Ľڵ�
	vector<vector<bool>> vis;
	for (int i = 0; i < n; ++i) {
		vis.push_back(vector<bool>(n, false));
	}

	if (dfs(1, 1, vis)) {
		show_maze();
	}
	else {
		cout << "can't reach!";
	}
}

int main(int argc, char* argv[]) {
	cout << "�������Թ���С:" << endl;
	cin >> n;

	if (n % 2 == 0) {
		n--;
	}

	// ��ʾ����
	// cv::Size img_size(800, 640);
	// cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	// cv::namedWindow(MAIN_WINDOW, CV_WINDOW_AUTOSIZE);
	// cv::imshow(MAIN_WINDOW, show_img);

	// ����N x N��С���Թ�
	for (int i = 0; i < n; ++i) {
		Maze.push_back(vector<char>(n, '#'));
	}

	// �����������Թ�
	create_maze();
	show_maze();
	auto_rounte();
	// if (human_rounte()) {
	// 	system("cls");
	// 	cout << "success!!!" << endl;
	// }


	// ��Ϊ������ʾ��������Ƿ�����Ƶ�
	// ��Ҫ��opencv��getchar
	// cvWaitKey(0);

	system("pause");
	return 0;
}
