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

// ����
double distance(const cv::Point &A, const cv::Point &B)
{
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

typedef struct PointAns {
	cv::Point p1;
	cv::Point p2;
	double distance;
	PointAns(cv::Point &p1_i, cv::Point &p2_i, double dis)
	: p1(p1_i), p2(p2_i), distance(dis) { }	
	PointAns(){ }
}p_ans;

// �ϲ�
p_ans merge(vector<cv::Point> & points, double dis, int mid
	, cv::Mat &show_image, int mid_width, p_ans ans)
{
	// ��ͼ
	cv::line(show_image
		, cv::Point(mid_width - dis, 0)
		, cv::Point(mid_width - dis, show_image.size().height)
		, cv::Scalar(0, 0, 255), 2, CV_AA);
	cv::line(show_image 
		, cv::Point(mid_width + dis, 0)
		, cv::Point(mid_width + dis, show_image.size().height)
		, cv::Scalar(0, 0, 255), 2, CV_AA);
	cv::imshow(MAIN_WINDOW_NAME, show_image);
	cvWaitKey(500);


	vector<cv::Point> left, right;
	// �Ѽ��������߷��������ĵ�(���η�Χ)
	for (int i = 0; i < points.size(); ++i)  
	{
		if (points[i].x - points[mid].x <= 0 && points[i].x - points[mid].x > -dis)
			left.push_back(points[i]);
		else if (points[i].x - points[mid].x > 0 && points[i].x - points[mid].x < dis)
			right.push_back(points[i]);
	}

	// lambda���ʽ(�����ϵ�������)
	sort(right.begin(), right.end(), [](const cv::Point &A, const cv::Point &B) {
		return A.y < B.y;
	});

	for (int i = 0, index; i < left.size(); ++i)  // ������ߵĵ㼯�ϣ����ұ߷��������ļ������
	{
		for (index = 0; index < right.size() && left[i].y < right[index].y; ++index);

		for (int j = 0; j < 7 && index + j < right.size(); ++j)  // �����ұ������Ͻ��6����
		{
			if (distance(left[i], right[j + index]) < dis) {
				dis = distance(left[i], right[j + index]);
				ans.p1 = left[i];
				ans.p2 = right[j + index];
				ans.distance = dis;
				cv::line(show_image, ans.p1, ans.p2
					, cv::Scalar(255, 0, 255), 2, CV_AA);
				cv::imshow(MAIN_WINDOW_NAME, show_image);
				cvWaitKey(300);
			}
		}
	}

	return ans;
}

// mat��Ϊ����ֵ��ֵ���Բ��������ô���
p_ans CacuMinPoints(vector<cv::Point> &points, cv::Mat show_image, int mid_width) {
	/*
	 * �������жϱ߽�����
	 */
	// ������������С
	if (points.size() == 2)

		return p_ans(points[0], points[1], distance(points[0], points[1]));  // ������

	// ���ﷵ������������С
	if (points.size() == 3) {
		p_ans p1(points[0], points[1], distance(points[0], points[1]));
		p_ans p2(points[0], points[2], distance(points[0], points[2]));
		p_ans p3(points[1], points[2], distance(points[1], points[2]));

		if (p2.distance < p3.distance) {
			if (p1.distance < p2.distance) {
				return p1;
			} else {
				return p2;
			}
		} else {
			if (p1.distance < p3.distance) {
				return p1;
			} else {
				return p3;
			}
		}
	}

	cv::line(show_image, cv::Point(mid_width, 0)
		, cv::Point(mid_width, show_image.size().height),
		cv::Scalar(255, 0, 0), 2, CV_AA);
	cv::imshow(MAIN_WINDOW_NAME, show_image);
	cvWaitKey(300);

	// ȡ�е㲢��ʼ��c++11
	int mid = (points.size() >> 1) - 1;
	double dis = 0;
	p_ans d1, d2, ans;
	vector<cv::Point> left(points.begin(), points.begin() + mid + 1)
					, right(points.begin() + mid + 1, points.end());

	// ÿ�μ���һ��
	d1 = CacuMinPoints(left, show_image.clone(), 
		(0 + mid_width)/2);
	d2 = CacuMinPoints(right, show_image.clone(), 
		(mid_width + show_image.size().width)/2);
	// ȡ��С��distance
	if (d1.distance < d2.distance) {
		dis = d1.distance;
		ans = d1;
	} else {
		dis = d2.distance;
		ans = d2;
	}

	// ���ǰ���ص�
	cv::line(show_image, ans.p1, ans.p2
		, cv::Scalar(255, 255, 255), 2, CV_AA);
	cv::imshow(MAIN_WINDOW_NAME, show_image);

	return merge(points, dis, mid, show_image, mid_width, ans);
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

	// ������ǵ�������
	// points.push_back(cv::Point(12, 1));
	// points.push_back(cv::Point(125, 10));
	// points.push_back(cv::Point(7, 88));
	// points.push_back(cv::Point(2, 555));
	// points.push_back(cv::Point(213, 122));

	sort(points.begin(), points.end(), 
		[](const cv::Point &A, const cv::Point &B) {
		return A.x < B.x;
	});
	cout << points << endl;

	// ���Ƶ�
	for (auto& point : points) {
		cv::circle(show_img, point, 2, cv::Scalar(0, 255, 255), -1, CV_AA);
	}

	// ��ʾ��
	cv::imshow(MAIN_WINDOW_NAME, show_img);
	p_ans ans = CacuMinPoints(points, show_img.clone(), show_img.size().width / 2);
	cout << ans.distance << endl;
	cv::line(show_img, ans.p1, ans.p2
		, cv::Scalar(0, 0, 255), 2, CV_AA);
	// ���ǰ���ص�
	cv::imshow(MAIN_WINDOW_NAME, show_img);

	cv::waitKey(0);
	return 0;
}