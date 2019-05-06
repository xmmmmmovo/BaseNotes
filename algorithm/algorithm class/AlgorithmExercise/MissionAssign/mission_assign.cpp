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

#define MAIN_WINDOW_NAME "�������������"
// ����
const int nums = 20;

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

	// ��������
	cout << needs_money;

	MissionAssign(needs_money, show_img);

	cv::waitKey(0);
	return 0;
}
