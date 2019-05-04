#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    b4.setParent(this);
    b4.setText("切换到主窗口");

    connect(&b4, &QPushButton::released, this, &SubWidget::sendSlot);
    resize(400, 400);
}

void SubWidget::sendSlot(){
//    emit mySignal();
//    emit mySignal(250, "我是子窗口");
}
