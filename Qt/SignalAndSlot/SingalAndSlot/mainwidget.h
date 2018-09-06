#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

//public slots:
    void mySlot();
    void changeWin();
    void dealSingal();
    void dealSlot(int, QString);

private:
QPushButton b1;
QPushButton *b2;
QPushButton b3;

SubWidget w;

};

#endif // MAINWIDGET_H
