#include "clickablelabel.h"
#include <QMouseEvent>
#include <QPainter>
#include <QFont>

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent)
{
}


void ClickableLabel::mouseReleaseEvent(QMouseEvent* event)
{
    if(Qt::LeftButton == event->button())
    {
        emit clicked();
    }
}


