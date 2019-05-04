// 隐藏console
// #pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
// opencv头文件
#include <opencv2/opencv.hpp>

#define WINDOW_NAME "凸包解决方案"

using namespace std;

/**
 * 用于取随机数
 * 这种方案只能用于取整数随机
 */
vector<int> RandomNums(const int& min, const int& max, const int& nums) {
	vector<int> temp;

	for (int i = min; i < max; ++i) {
		temp.push_back(i + 1);
	}

	// 将数组散列化
	random_shuffle(temp.begin(), temp.end());
	temp.resize(nums); // 限制返回数组

	return temp;
}

bool cmp(cv::Point &p1, cv::Point &p2) {
	if (p1.x < p2.x) {
		return 1;
	} else if (p1.x > p2.x) {
		return 0;
	} else {
		return p1.y < p2.y ? 1 : 0;
	}
}

/**
 * 下面的是第一种穷举法
 * 时间为O(n^3)
 */
void algorithm1(vector<cv::Point>& points, cv::Mat& show_img) {
	vector<cv::Point> ans;
	size_t size = points.size();
	int minus = 0;

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = i + 1; j < size; ++j) {
			for (size_t k = 0; k < size; ++k) {
				minus = 0;
				int x1 = points[i].x;
				int y1 = points[i].y;
				int x2 = points[j].x;
				int y2 = points[j].y;
				int x3 = points[k].x;
				int y3 = points[k].y;

				if ((x1 * y2 + x3 * y1 + x2 * y3
					- x3 * y2 - x2 * y1 - x1 * y3) < 0) {
					minus++;
				}
			}

			if (minus == 0 || minus == size - 1) {
				ans.push_back(points[i]);
				ans.push_back(points[j]);
				break;
			}
		}
	}

	cout << ans;

	for (int i = 0; i < ans.size(); i+=2) {
		cv::line(show_img, ans[i], ans[i + 1], 
			cv::Scalar(0, 0, 255), 2, CV_AA);
	}
	cv::imshow(WINDOW_NAME, show_img);

	return;
}

/**
 * 下面的是第二种穷举法
 * 时间为O(n^2)
 */
void algorithm2(vector<cv::Point>& points, cv::Mat& show_img) {
	auto p_tu = min_element(points.begin(), points.end(), cmp);
	auto p_temp = p_tu;
	
	do {
		for (auto &point : points) {
			if (point == *p_temp) {
			}
		}
	} while (p_temp != p_tu);
	
	return;
}

/**
 * 绘制凸包的主函数(暴力法)
 */
void ConvexHull(vector<cv::Point>& points, cv::Mat& show_img) {
	vector<cv::Point> ans;

	for (auto& point : points) {
		// 绘制点
		cv::circle(show_img, point, 2, cv::Scalar(0, 255, 255), -1, CV_AA);
	}

	cv::imshow(WINDOW_NAME, show_img);

	// cv::Mat mat = show_img.clone();
	// cv::line(show_img, points[0], points[1], cv::Scalar(0, 0, 255), 2, CV_AA);
	// cv::imshow(WINDOW_NAME, show_img);

	algorithm1(points, show_img);

	return;
}


int main(void) {
	// 凸包包含点
	vector<cv::Point> points;
	const int nums = 5;

	cv::Size img_size(800, 640);
	cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);
	cv::imshow(WINDOW_NAME, show_img);

	vector<int> x = RandomNums(0, 800, nums);
	vector<int> y = RandomNums(0, 640, nums);

	for (int i = 0; i < nums; ++i) {
		points.push_back(cv::Point(x[i], y[i])); // 插入点
	}
	// 输出随机点
	cout << points << endl;
	ConvexHull(points, show_img);

	// 等待结束按键
	cvWaitKey(0);
	return 0;
}
