#include <iostream>
#include <opencv2\opencv.hpp>

#define PI 3.1415926

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {
	// VideoCapture video(0); // ����ͷ����
	// while (true){
	// 	Mat frame; // ֡
	// 	video >> frame; // ������
	// 	cvtColor(frame, frame, COLOR_RGB2GRAY);
	// 	namedWindow("frame", WINDOW_AUTOSIZE);
	// 	imshow("frame", frame);
	//
	// 	waitKey(30);
	// }

	// Mat src = imread("D:/lena.jpg", 1);
	// cvtColor(src, src, COLOR_BGR2GRAY); // ת��ɫ�ʿռ�
	// namedWindow("src", WINDOW_AUTOSIZE);
	// imshow("src", src);
	// waitKey(0);
	//
	// /**
	//  * ���Ĳ��(��)
	//  */
	// Mat dImg = Mat(src.rows, src.cols - 2, CV_8UC1);
	// for (int i = 0; i < src.rows; i++){
	// 	for (int j = 1; j < src.cols - 1; j++){
			// ÿ�ζ��������ļ���(��������)
	// 		dImg.at<uchar>(i, j - 1) =
	// 			src.at<uchar>(i, j + 1) - src.at<uchar>(i, j - 1);
	// 	}
	// }
	//
	// namedWindow("dst", WINDOW_AUTOSIZE);
	// imshow("dst", dImg);
	// waitKey(0);

	/**
	 * ��˹ģ��
	 */
	Mat src = imread("D:/lena.jpg", 1);
	cvtColor(src, src, COLOR_BGR2GRAY); // ת��ɫ�ʿռ�
	namedWindow("src", WINDOW_AUTOSIZE);
	imshow("src", src);
	// waitKey(0);

	//5x5 �����ģ��
	Mat model = Mat(5, 5, CV_64FC1);
	double sigma = 80; // ������
	for (int i = -2; i <= 2; i++){
		for(int j = -2; j <= 2; j++) {
			// ���˹��
			model.at<double>(i + 2, j + 2) =
				// ��̬�ֲ���ʽ
				exp(-(i * i + j * j) / (2 * sigma * sigma)) /
				(2 * PI * sigma * sigma);
		}
	}

	// ��˹�����ģ��
	double gaussSum = 0;
	gaussSum = sum(model).val[0]; // ���
	for (int i = 0; i < model.rows; i++){
		for (int j = 0; j < 5; j++) {
			model.at<double>(i, j) = model.at<double>(i, j) /
				gaussSum;
		}
	}

	// �������
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
	 * ��˹ģ��
	 * ԭͼ ���ͼ ����˴�С sigma
	 */
	GaussianBlur(src, dst, Size(15, 15), 200);
	/**
	 * ��˹ģ�����Ż��㷨
	 */

	namedWindow("gaussBlur", WINDOW_AUTOSIZE);
	imshow("gaussBlur", dst);

	waitKey(0);

	return 0;
}