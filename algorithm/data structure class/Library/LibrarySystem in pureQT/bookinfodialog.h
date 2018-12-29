#ifndef BOOKINFODIALOG_H
#define BOOKINFODIALOG_H

#include <QDialog>

namespace Ui {
class bookInfoDialog;
}

class bookInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bookInfoDialog(QWidget *parent = 0);
    ~bookInfoDialog();

private:
    Ui::bookInfoDialog *ui;
};

#endif // BOOKINFODIALOG_H
