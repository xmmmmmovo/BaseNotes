#include "bookinfodialog.h"
#include "ui_bookinfodialog.h"

/**
  书籍添加及修改dialog
*/
bookInfoDialog::bookInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookInfoDialog)
{
    ui->setupUi(this);
}

bookInfoDialog::~bookInfoDialog()
{
    delete ui;
}
