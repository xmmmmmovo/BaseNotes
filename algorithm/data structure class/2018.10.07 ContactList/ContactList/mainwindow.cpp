#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QString>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    qlistwidget = ui->contactList;
    qlistwidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    qlistwidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_contactList_itemDoubleClicked(QListWidgetItem *item)
{

}
