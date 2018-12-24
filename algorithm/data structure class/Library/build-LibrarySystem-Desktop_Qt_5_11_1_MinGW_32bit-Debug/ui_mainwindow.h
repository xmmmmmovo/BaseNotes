/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <lableclick.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainWindow;
    QFrame *loginFrame;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *usernameLineEdit;
    QSpacerItem *verticalSpacer;
    QLineEdit *userpasswordLineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *loginAndcancel;
    LableClick *loginLable;
    QSpacerItem *spacer;
    LableClick *quitLable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 446);
        MainWindow->setMinimumSize(QSize(750, 446));
        MainWindow->setMaximumSize(QSize(750, 446));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/actions/bookmark-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        mainWindow = new QWidget(MainWindow);
        mainWindow->setObjectName(QStringLiteral("mainWindow"));
        loginFrame = new QFrame(mainWindow);
        loginFrame->setObjectName(QStringLiteral("loginFrame"));
        loginFrame->setGeometry(QRect(450, 190, 250, 190));
        loginFrame->setFrameShape(QFrame::NoFrame);
        loginFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(loginFrame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        usernameLineEdit = new QLineEdit(loginFrame);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        usernameLineEdit->setFont(font);
        usernameLineEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(usernameLineEdit);

        verticalSpacer = new QSpacerItem(2, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        userpasswordLineEdit = new QLineEdit(loginFrame);
        userpasswordLineEdit->setObjectName(QStringLiteral("userpasswordLineEdit"));
        userpasswordLineEdit->setMinimumSize(QSize(0, 30));
        userpasswordLineEdit->setFont(font);
        userpasswordLineEdit->setEchoMode(QLineEdit::Password);
        userpasswordLineEdit->setDragEnabled(false);
        userpasswordLineEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(userpasswordLineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        loginAndcancel = new QHBoxLayout();
        loginAndcancel->setSpacing(6);
        loginAndcancel->setObjectName(QStringLiteral("loginAndcancel"));
        loginLable = new LableClick(loginFrame);
        loginLable->setObjectName(QStringLiteral("loginLable"));
        loginLable->setMinimumSize(QSize(89, 50));

        loginAndcancel->addWidget(loginLable);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        loginAndcancel->addItem(spacer);

        quitLable = new LableClick(loginFrame);
        quitLable->setObjectName(QStringLiteral("quitLable"));
        quitLable->setMinimumSize(QSize(89, 50));

        loginAndcancel->addWidget(quitLable);


        verticalLayout_2->addLayout(loginAndcancel);

        MainWindow->setCentralWidget(mainWindow);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        usernameLineEdit->setText(QString());
        usernameLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
#ifndef QT_NO_WHATSTHIS
        userpasswordLineEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        userpasswordLineEdit->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        userpasswordLineEdit->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        userpasswordLineEdit->setInputMask(QString());
        userpasswordLineEdit->setText(QString());
        userpasswordLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        loginLable->setText(QString());
        quitLable->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
