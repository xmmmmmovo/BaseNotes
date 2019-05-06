// 隐藏console
// #pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <vector>
#include <cstdlib>
// 算法库
#include <algorithm>
#include <ctime>
// opencv头文件
#include <opencv2/opencv.hpp>
// 随机引擎头文件
#include <random>

using namespace std;

#define MAIN_WINDOW_NAME "任务分配解决方案"
// 人数
const int nums = 20;

/**
 * 用于取随机数
 * 这种方案只能用于取整数随机
 */
vector<int> RandomNums(const int& min, const int& max, const int& nums) {
	vector<int> temp;

	for (int i = min; i < max; ++i) {
		temp.push_back(i + 1);
	}

	// 采用64位梅林算法进行随机数引擎播种
	random_device rd;
	mt19937_64 g(rd());

	// 将数组散列化
	shuffle(temp.begin(), temp.end(), g);
	temp.resize(nums); // 限制返回数组

	return temp;
}

ostream& operator<< (ostream &o, const vector<int> &v) {
	for (const auto &value : v) {
		o << value << endl;
	}
}

void MissionAssign(vector<int> &needs_money, cv::Mat &show_img) {
	vector<int>	person_number;
	for (int i = 1; i <= nums; ++i) {
		person_number.push_back(i);
	}
}

int main(int argc, char* argv[]) {
	cv::Size img_size(800, 640);
	cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(MAIN_WINDOW_NAME, CV_WINDOW_AUTOSIZE);
	cv::imshow(MAIN_WINDOW_NAME, show_img);

	vector<int> needs_money = RandomNums(12, 450, nums);

	// 输出随机点
	cout << needs_money;

	MissionAssign(needs_money, show_img);

	cv::waitKey(0);
	return 0;
}
