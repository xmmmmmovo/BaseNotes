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
	Mat src = imread("D:/test.png");//ע��ָ���������
	Mat output_image;
	cvtColor(src, output_image, CV_BGR2HSV);//Դ��Ŀ���ɫ�ռ䶨�塣
	//д��ͼ��
	imwrite("D:/test2.png", output_image);
	img.load("D:/test2.png");
	painter.drawImage(0, 0, img);
}
