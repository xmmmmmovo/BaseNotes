#ifndef LABELCLICK_H
#define LABELCLICK_H
#include <QLabel>

class LableClick: public QLabel
{

    Q_OBJECT
public:
    explicit LableClick(QWidget *parent = 0);
    LableClick(const QString &text, QWidget *parent=0);
signals:
    // 鼠标单击信号
    void clicked();

protected:
    // 鼠标单击事件
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // LABELCLICK_H
