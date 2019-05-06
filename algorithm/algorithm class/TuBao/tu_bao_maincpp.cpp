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

/**
 * 下面的是第一种穷举法
 * 时间为O(n^3)
 */
void algorithm1(vector<cv::Point>& points, cv::Mat& show_img) {
	cv::Mat fin_mat = show_img.clone(); // 复制
	size_t size = points.size();
	vector<pair<int, int>> pairs; // 标定起始点
	int a = 0, b = 0, c = 0, sign1 = 0, sign2 = 0;

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = i + 1; j < size; ++j) {
			a = points[j].y - points[i].y;
			b = points[i].x - points[j].x;
			c = (points[i].x * points[j].y) - (points[i].y * points[j].x);
			sign1 = 0;
			sign2 = 0;

			for (size_t k = 0; k < size; ++k) {
				if ((k == j) || (k == i)) {
					continue;
				}
				int temp = a * points[k].x + b * points[k].y;
				if (temp == c) {
					sign1++;
					sign2++;
				}
				if (temp > c) {
					sign1++;
				}
				if (temp < c) {
					sign2++;
				}
			}

			if (sign1 == (size - 2) || sign2 == (size - 2)) {
				pairs.push_back(make_pair(i, j));
			}

			cv::line(show_img, points[i], points[j],
				cv::Scalar(255, 0, 0), 2, CV_AA);
			cv::imshow(WINDOW_NAME, show_img);
			char c = cvWaitKey(100);
			if (c == 'q') {
				exit(0);
			}
		}
		show_img = fin_mat.clone();
	}

	for (int i = 0; i < pairs.size(); i++) {
		cv::line(show_img, points[pairs[i].first], points[pairs[i].second],
			cv::Scalar(0, 0, 255), 2, CV_AA);
		cvWaitKey(500);
		cv::imshow(WINDOW_NAME, show_img);
	}
	// cv::imshow(WINDOW_NAME, show_img);

	return;
}

/**
 * 下面的是第二种穷举法
 * 时间为O(n^2)
 */
void algorithm2(vector<cv::Point>& points, cv::Mat& show_img) {
	// lambda表达式
	auto p_tu = min_element(points.begin(), points.end(),
		[](cv::Point &p1, cv::Point &p2) {
		if (p1.x < p2.x) {
			return 1;
		}
		else if (p1.x > p2.x) {
			return 0;
		}
		else {
			return p1.y < p2.y ? 1 : 0;
		}
	});

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

	// 显示点
	cv::imshow(WINDOW_NAME, show_img);

	// 主算法
	algorithm1(points, show_img);

	// algorithm2(points, show_img);

	return;
}


int main(void) {
	// 凸包包含点
	vector<cv::Point> points;
	const int nums = 20;

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

	// 凸包主函数
	ConvexHull(points, show_img);

	// 等待结束按键
	cvWaitKey(0);
	return 0;
}
