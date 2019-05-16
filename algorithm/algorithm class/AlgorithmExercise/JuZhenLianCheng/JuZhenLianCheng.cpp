#include "pch.h"
#include <iostream>
#include <algorithm>
// 线性代数库
#include <armadillo>
#include <vector>
// #include <opencv2/opencv.hpp>

#define MAIN_WINDOW "矩阵连乘解决方案"

using namespace std;

// vector<arma::Mat<int>> mats; // 矩阵数组

int main(int argc, char* argv[]) {
	// cv::Size img_size(800, 640);
	// cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	// cv::namedWindow(MAIN_WINDOW, CV_WINDOW_AUTOSIZE);
	// cv::imshow(MAIN_WINDOW, show_img);

	arma::Mat<int> m1 = arma::randu(5, 1) * 10
		, m2 = arma::randu(1, 5) * 10;

	cout << m1 << endl;
	cout << m2 << endl;

	cout << m1 * m2 << endl;


	// 等待结束按键
	// cvWaitKey(0);
	return 0;
}
