#include "lableclick.h"
#include <QMouseEvent>

// mark: public:--------------------------------------------------
LableClick::LableClick(QWidget *parent) :
    QLabel(parent)
{
}

LableClick::LableClick(const QString &text, QWidget *parent) :
    QLabel(parent)
{
    setText(text);
}

// mark: protected:------------------------------------------------
void LableClick::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
        emit clicked();
}
