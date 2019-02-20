#include <iostream>
#include <opencv2\opencv.hpp>

#define PI 3.1415926

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {
	// VideoCapture video(0); // 摄像头对象
	// while (true){
	// 	Mat frame; // 帧
	// 	video >> frame; // 流输入
	// 	cvtColor(frame, frame, COLOR_RGB2GRAY);
	// 	namedWindow("frame", WINDOW_AUTOSIZE);
	// 	imshow("frame", frame);
	//
	// 	waitKey(30);
	// }

	// Mat src = imread("D:/lena.jpg", 1);
	// cvtColor(src, src, COLOR_BGR2GRAY); // 转换色彩空间
	// namedWindow("src", WINDOW_AUTOSIZE);
	// imshow("src", src);
	// waitKey(0);
	//
	// /**
	//  * 中心差分(锐化)
	//  */
	// Mat dImg = Mat(src.rows, src.cols - 2, CV_8UC1);
	// for (int i = 0; i < src.rows; i++){
	// 	for (int j = 1; j < src.cols - 1; j++){
			// 每次都进行中心计算(左右两个)
	// 		dImg.at<uchar>(i, j - 1) =
	// 			src.at<uchar>(i, j + 1) - src.at<uchar>(i, j - 1);
	// 	}
	// }
	//
	// namedWindow("dst", WINDOW_AUTOSIZE);
	// imshow("dst", dImg);
	// waitKey(0);

	/**
	 * 高斯模糊
	 */
	Mat src = imread("D:/lena.jpg", 1);
	cvtColor(src, src, COLOR_BGR2GRAY); // 转换色彩空间
	namedWindow("src", WINDOW_AUTOSIZE);
	imshow("src", src);
	// waitKey(0);

	//5x5 卷积核模板
	Mat model = Mat(5, 5, CV_64FC1);
	double sigma = 80; // 超参数
	for (int i = -2; i <= 2; i++){
		for(int j = -2; j <= 2; j++) {
			// 求高斯点
			model.at<double>(i + 2, j + 2) =
				// 正态分布公式
				exp(-(i * i + j * j) / (2 * sigma * sigma)) /
				(2 * PI * sigma * sigma);
		}
	}

	// 高斯卷积核模板
	double gaussSum = 0;
	gaussSum = sum(model).val[0]; // 求和
	for (int i = 0; i < model.rows; i++){
		for (int j = 0; j < 5; j++) {
			model.at<double>(i, j) = model.at<double>(i, j) /
				gaussSum;
		}
	}

	// 卷积操作
	Mat dst = Mat(src.rows - 4, src.cols - 4, CV_8UC1); // 5x5
	for (int i = 2; i < src.rows - 2; i++){
		for (int j = 2; j < src.cols - 2; j++) {
			double sum = 0;

			for (int m = 0; m < model.rows; m++) {
				for (int n = 0; n < model.cols; n++){
					sum += (double)src.at<uchar>(i + m - 2, j + n - 2) *
						model.at<double>(m, n);
				}
			}

			dst.at<uchar>(i - 2, j - 2) = (uchar)sum;
		}
	}

	/**
	 * 高斯模糊
	 * 原图 输出图 卷积核大小 sigma
	 */
	GaussianBlur(src, dst, Size(15, 15), 200);
	/**
	 * 高斯模型最优化算法
	 */

	namedWindow("gaussBlur", WINDOW_AUTOSIZE);
	imshow("gaussBlur", dst);

	waitKey(0);

	return 0;
}