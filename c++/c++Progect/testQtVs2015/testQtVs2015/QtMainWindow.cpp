#include "QtMainWindow.h"
#include <qpainter.h>
#include <opencv2/opencv.hpp>

using namespace cv;

QtMainWindow::QtMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void QtMainWindow::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	Mat src = imread("D:/test.png");//注意分隔符！！！
	Mat output_image;
	cvtColor(src, output_image, CV_BGR2HSV);//源和目标彩色空间定义。
	//写出图像。
	imwrite("D:/test2.png", output_image);
	img.load("D:/test2.png");
	painter.drawImage(0, 0, img);
}
