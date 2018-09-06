#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // MYLABEL_H
