#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDataStream>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void writeData();
    void readData();
};

#endif // WIDGET_H
