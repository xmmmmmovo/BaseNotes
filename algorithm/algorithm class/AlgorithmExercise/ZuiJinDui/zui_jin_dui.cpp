// ����console
// #pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <vector>
#include <cstdlib>
// �㷨��
#include <algorithm>
#include <ctime>
// opencvͷ�ļ�
#include <opencv2/opencv.hpp>
// �������ͷ�ļ�
#include <random>

using namespace std;

#define MAIN_WINDOW_NAME "����Խ������"
#define SORT_WINDOW_NAME "�����㷨���ӻ�"

/**
 * ����ȡ�����
 * ���ַ���ֻ������ȡ�������
 */
vector<int> RandomNums(const int& min, const int& max, const int& nums) {
	vector<int> temp;

	for (int i = min; i < max; ++i) {
		temp.push_back(i + 1);
	}

	// ����64λ÷���㷨������������沥��
	random_device rd;
	mt19937_64 g(rd());

	// ������ɢ�л�
	shuffle(temp.begin(), temp.end(), g);
	temp.resize(nums); // ���Ʒ�������

	return temp;
}

void CacuMinPoints(vector<cv::Point> &points, cv::Mat &show_image) {
	// ����������ӻ�
	cv::Mat sort_show_img(cv::Size(960, 480),
		CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(SORT_WINDOW_NAME, cv::WINDOW_AUTOSIZE);
	cv::imshow(SORT_WINDOW_NAME, sort_show_img);
	// lambda���ʽ
	// sort(points.begin(), points.end(), 
	// 	[](cv::Point p1, cv::Point p2) {
	// });

};

int main(int argc, char* argv[]) {
	// ����԰�����
	vector<cv::Point> points;
	const int nums = 20;

	cv::Size img_size(800, 640);
	cv::Mat show_img(img_size, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::namedWindow(MAIN_WINDOW_NAME, CV_WINDOW_AUTOSIZE);
	cv::imshow(MAIN_WINDOW_NAME, show_img);

	vector<int> x = RandomNums(0, 800, nums);
	vector<int> y = RandomNums(0, 640, nums);

	for (int i = 0; i < nums; ++i) {
		points.push_back(cv::Point(x[i], y[i])); // �����
	}
	// ��������
	cout << points << endl;

	CacuMinPoints(points, show_img);

	cv::waitKey(0);
	return 0;
}
