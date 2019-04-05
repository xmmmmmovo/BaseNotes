#include "checkdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckDlg w;
    w.show();

    return a.exec();
}
