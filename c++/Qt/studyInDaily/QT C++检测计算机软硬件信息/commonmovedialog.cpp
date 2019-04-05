#include "commonmovedialog.h"
#include <QMouseEvent>

CommonMoveDialog::CommonMoveDialog(QWidget *parent) :
    QDialog(parent),m_bCouldMove(false)
{
}

CommonMoveDialog::~CommonMoveDialog()
{

}


void CommonMoveDialog::mousePressEvent(QMouseEvent * event)
{
    if(Qt::LeftButton == event->button())
    {
        m_bCouldMove = true;
        m_MousePressedPoint = event->pos();
    }
    QDialog::mousePressEvent(event);
}

void CommonMoveDialog::mouseReleaseEvent(QMouseEvent * event)
{
    if(Qt::LeftButton == event->button())
    {
        m_bCouldMove = false;
    }
    QDialog::mouseReleaseEvent(event);
}

void CommonMoveDialog::mouseMoveEvent(QMouseEvent * event)
{
    if(m_bCouldMove)
    {
        QPoint newPoint = this->pos() + event->pos() - m_MousePressedPoint;
        this->move(newPoint);
    }
    QDialog::mouseMoveEvent(event);
    event->accept();
}
