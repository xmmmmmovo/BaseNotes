#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
//数据流
#include <QDataStream>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_readFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open",
                                                "../", "TXT(*.txt)");
    if(!path.isEmpty()){
        QFile file(path);
        QByteArray array;

        bool isOpen = file.open(QIODevice::ReadOnly);
        if(isOpen){
            if(file.size() < 10000000){
                //默认只识别utf-8
                array = file.readAll();
            }else{
                while (!file.atEnd()) {
                    //单行读取
                    array += file.readLine();
                }
            }
            ui->textEdit->setText(array);
        }

        file.close();
    }
}

void MainWidget::on_writeFileButton_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");

    if(!path.isEmpty()){
        QFile file;
        file.setFileName(path);

        bool isOpen = file.open(QIODevice::WriteOnly);
        if(isOpen){
            QString str = ui->textEdit->toPlainText();
            //QString -> QByteArray
            file.write(str.toUtf8());

            //QString -> c++ string -> char *
            //file.write(str.toStdString().data());

            //转换为平台本地编码
            file.write(str.toLocal8Bit());

            //QString -> QByteArray
            //QString buf = "123";
            //QByteArray test = buf.toUtf8();//中文
            //test = buf.toLocal8Bit();//本地编码

            //QByteArray -> char *
            //char *b = test.data();
        }

        file.close();
    }
}
