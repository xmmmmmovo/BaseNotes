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

#define MAIN_WINDOW_NAME "最近对解决方案"
#define SORT_WINDOW_NAME "排序算法可视化"

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

void CacuMinPoints(vector<cv::Point> &points, cv::Mat &show_image) {
	// 用于排序可视化
	cv::Mat sort_show_img(cv::Size(960, 480),
		CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(SORT_WINDOW_NAME, cv::WINDOW_AUTOSIZE);
	cv::imshow(SORT_WINDOW_NAME, sort_show_img);
	// lambda表达式
	// sort(points.begin(), points.end(), 
	// 	[](cv::Point p1, cv::Point p2) {
	// });

};

int main(int argc, char* argv[]) {
	// 最近对包含点
	vector<cv::Point> points;
	const int nums = 20;

	cv::Size img_size(800, 640);
	cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(MAIN_WINDOW_NAME, CV_WINDOW_AUTOSIZE);
	cv::imshow(MAIN_WINDOW_NAME, show_img);

	vector<int> x = RandomNums(0, 800, nums);
	vector<int> y = RandomNums(0, 640, nums);

	for (int i = 0; i < nums; ++i) {
		points.push_back(cv::Point(x[i], y[i])); // 插入点
	}
	// 输出随机点
	cout << points << endl;

	CacuMinPoints(points, show_img);

	cv::waitKey(0);
	return 0;
}
