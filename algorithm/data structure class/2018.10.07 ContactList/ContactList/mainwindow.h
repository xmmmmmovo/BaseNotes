#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QListWidget>
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

private slots:
    void on_contactList_itemDoubleClicked(QListWidgetItem *item);

private:
    typedef struct Contact
    {
        QString name;
        QString number;
    }contact;
    Ui::MainWindow *ui;
    List<Contact> list;

    void init();
    QListWidget *qlistwidget;
};

#endif // MAINWINDOW_H
