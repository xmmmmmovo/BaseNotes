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

// 距离
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

// 合并
p_ans merge(vector<cv::Point> & points, double dis, int mid
	, cv::Mat &show_image, int mid_width, p_ans ans)
{
	// 绘图
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
	// 搜集左右两边符合条件的点(矩形范围)
	for (int i = 0; i < points.size(); ++i)  
	{
		if (points[i].x - points[mid].x <= 0 && points[i].x - points[mid].x > -dis)
			left.push_back(points[i]);
		else if (points[i].x - points[mid].x > 0 && points[i].x - points[mid].x < dis)
			right.push_back(points[i]);
	}

	// lambda表达式(按从上到下排序)
	sort(right.begin(), right.end(), [](const cv::Point &A, const cv::Point &B) {
		return A.y < B.y;
	});

	for (int i = 0, index; i < left.size(); ++i)  // 遍历左边的点集合，与右边符合条件的计算距离
	{
		for (index = 0; index < right.size() && left[i].y < right[index].y; ++index);

		for (int j = 0; j < 7 && index + j < right.size(); ++j)  // 遍历右边坐标上界的6个点
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

// mat因为是右值赋值所以不能用引用传参
p_ans CacuMinPoints(vector<cv::Point> &points, cv::Mat show_image, int mid_width) {
	/*
	 * 首先先判断边界条件
	 */
	// 返回两个点最小
	if (points.size() == 2)

		return p_ans(points[0], points[1], distance(points[0], points[1]));  // 两个点

	// 这里返回三个点中最小
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

	// 取中点并初始化c++11
	int mid = (points.size() >> 1) - 1;
	double dis = 0;
	p_ans d1, d2, ans;
	vector<cv::Point> left(points.begin(), points.begin() + mid + 1)
					, right(points.begin() + mid + 1, points.end());

	// 每次减少一半
	d1 = CacuMinPoints(left, show_image.clone(), 
		(0 + mid_width)/2);
	d2 = CacuMinPoints(right, show_image.clone(), 
		(mid_width + show_image.size().width)/2);
	// 取最小的distance
	if (d1.distance < d2.distance) {
		dis = d1.distance;
		ans = d1;
	} else {
		dis = d2.distance;
		ans = d2;
	}

	cv::line(show_image, ans.p1, ans.p2
		, cv::Scalar(255, 255, 255), 2, CV_AA);
	// 算是半个回调
	cv::imshow(MAIN_WINDOW_NAME, show_image);

	return merge(points, dis, mid, show_image, mid_width, ans);
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

	// 下面的是调试样例
	// points.push_back(cv::Point(12, 1));
	// points.push_back(cv::Point(125, 10));
	// points.push_back(cv::Point(7, 88));
	// points.push_back(cv::Point(2, 555));
	// points.push_back(cv::Point(213, 122));

	sort(points.begin(), points.end(), [](const cv::Point &A, const cv::Point &B) {
		return A.x < B.x;
	});
	cout << points << endl;

	for (auto& point : points) {
		// 绘制点
		cv::circle(show_img, point, 2, cv::Scalar(0, 255, 255), -1, CV_AA);
	}

	// 显示点
	cv::imshow(MAIN_WINDOW_NAME, show_img);
	p_ans ans = CacuMinPoints(points, show_img.clone(), show_img.size().width / 2);
	cout << ans.distance << endl;
	cv::line(show_img, ans.p1, ans.p2
		, cv::Scalar(0, 0, 255), 2, CV_AA);
	// 算是半个回调
	cv::imshow(MAIN_WINDOW_NAME, show_img);

	cv::waitKey(0);
	return 0;
}