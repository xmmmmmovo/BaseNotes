#include "smallwidget.h"
//自定义布局
#include <QSpinBox>
#include <QSlider>
#include <QBoxLayout>

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);
}
