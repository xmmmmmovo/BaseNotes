#include <opencv2/opencv.hpp>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <string>
#include <conio.h>

// #define MAIN_WINDOW "迷宫人"

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

// 正儿八经的生成迷宫
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
		case 0://上
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
		case 1://下
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
		case 2://左
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
		case 3://右
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
		if (up&&down&&right&&left)//如果当前访问节点四个方向都没有可拆的节点，回溯
		{
			if (!MazeStack.empty())
			{
				i = MazeStack.top().i;
				j = MazeStack.top().j;
				MazeStack.pop();
				setDirFalse(up, down, right, left);
			}
			else//如果栈为空的话就返回，此时迷宫矩阵已经创建完毕
			{
				return;
			}
		}
	}
}

/**
 * 生成迷宫
 * 这里的思路主要是挖格子
 */
void create_maze() {
	stack<m_Point> MazeStack;
	// 初始化
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
 * 手动走迷宫
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

// 主要的dfs方法
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
 * 自动走迷宫
 */
void auto_rounte() {
	// 访问过的节点
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
	cout << "请输入迷宫大小:" << endl;
	cin >> n;

	if (n % 2 == 0) {
		n--;
	}

	// 显示窗体
	// cv::Size img_size(800, 640);
	// cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	// cv::namedWindow(MAIN_WINDOW, CV_WINDOW_AUTOSIZE);
	// cv::imshow(MAIN_WINDOW, show_img);

	// 创建N x N大小的迷宫
	for (int i = 0; i < n; ++i) {
		Maze.push_back(vector<char>(n, '#'));
	}

	// 首先先生成迷宫
	create_maze();
	show_maze();
	auto_rounte();
	// if (human_rounte()) {
	// 	system("cls");
	// 	cout << "success!!!" << endl;
	// }


	// 因为命令提示框跟窗体是分离控制的
	// 需要用opencv的getchar
	// cvWaitKey(0);

	system("pause");
	return 0;
}
