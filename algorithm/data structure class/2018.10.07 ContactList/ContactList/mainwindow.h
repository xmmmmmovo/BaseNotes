#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "unidirectionalLinkedlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    typedef struct Contact
    {
        QString name;
        QString number;
    }contact;
    Ui::MainWindow *ui;

    void init();
};

#endif // MAINWINDOW_H
