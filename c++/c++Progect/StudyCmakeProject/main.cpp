/**
 * author: xmmmmmovo
 * generation time: 2019/05/05
 * filename: main.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char const *argv[]) {
    cv::namedWindow("test", cv::WINDOW_AUTOSIZE);
    cv::Mat m = cv::imread("D:\\AndroidLabtest\\notes\\c++\\c++Progect\\StudyCmakeProject\\testpic.jpg", 
                            cv::IMREAD_COLOR);
    cv::imshow("test", m);
    cv::waitKey(0);

    // system("pause");
    return 0;
}