// ����console
// #pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
// opencvͷ�ļ�
#include <opencv2/opencv.hpp>
// �������ͷ�ļ�
#include <random>

#define WINDOW_NAME "͹���������"

using namespace std;
/**
 * ����ȡ�����
 * ���ַ���ֻ������ȡ�������
 */
vector<int> RandomNums(const int& min, const int& max, const int& nums) {
	vector<int> temp;

	for (int i = min; i < max; ++i) {
		temp.push_back(i + 1);
	}

	// ����64λ÷���㷨������������沥��q
	random_device rd;
	mt19937_64 g(rd());

	// ������ɢ�л�
	shuffle(temp.begin(), temp.end(), g);
	temp.resize(nums); // ���Ʒ�������

	return temp;
}

/**
 * ������ǵ�һ����ٷ�
 * ʱ��ΪO(n^3)
 */
void algorithm1(vector<cv::Point>& points, cv::Mat& show_img) {
	cv::Mat fin_mat = show_img.clone(); // ����
	size_t size = points.size();
	vector<pair<int, int>> pairs; // �궨��ʼ��
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
			char c = cvWaitKey(50);
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
 * �������QuickHull(δ���)
 */
void algorithm2(vector<cv::Point>& points, cv::Mat& show_img) {

	return;
}

/**
 * ����͹����������(������)
 */
void ConvexHull(vector<cv::Point>& points, cv::Mat& show_img) {
	vector<cv::Point> ans;

	for (auto& point : points) {
		// ���Ƶ�
		cv::circle(show_img, point, 2, cv::Scalar(0, 255, 255), -1, CV_AA);
	}

	// ��ʾ��
	cv::imshow(WINDOW_NAME, show_img);

	// �㷨1
	algorithm1(points, show_img);

	// �㷨2
	// algorithm2(points, show_img);

	return;
}


int main(void) {
	// ͹��������
	vector<cv::Point> points;
	const int nums = 20;

	cv::Size img_size(800, 640);
	cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);
	cv::imshow(WINDOW_NAME, show_img);

	vector<int> x = RandomNums(0, 800, nums);
	vector<int> y = RandomNums(0, 640, nums);

	for (int i = 0; i < nums; ++i) {
		points.push_back(cv::Point(x[i], y[i])); // �����
	}
	// ��������
	cout << points << endl;

	// ͹��������
	ConvexHull(points, show_img);

	// �ȴ���������
	cvWaitKey(0);
	return 0;
}
