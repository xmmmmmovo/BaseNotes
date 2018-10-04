#include "mainwidget.h"
#include <QPushButton>
#include "mybutton.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    /*对于父窗口（主窗口），坐标相对于屏幕
     *原点：相对于屏幕左上角
     * x：向右为正
     * y：向下为正
    */
    move(100, 100);//移动窗口


}

MainWidget::~MainWidget()
{

}
