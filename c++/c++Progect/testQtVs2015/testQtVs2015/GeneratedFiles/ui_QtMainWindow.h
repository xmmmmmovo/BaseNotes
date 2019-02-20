/********************************************************************************
** Form generated from reading UI file 'QtMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMAINWINDOW_H
#define UI_QTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtMainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtMainWindowClass)
    {
        if (QtMainWindowClass->objectName().isEmpty())
            QtMainWindowClass->setObjectName(QString::fromUtf8("QtMainWindowClass"));
        QtMainWindowClass->resize(600, 400);
        centralWidget = new QWidget(QtMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        QtMainWindowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtMainWindowClass->setStatusBar(statusBar);

        retranslateUi(QtMainWindowClass);

        QMetaObject::connectSlotsByName(QtMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtMainWindowClass)
    {
        QtMainWindowClass->setWindowTitle(QApplication::translate("QtMainWindowClass", "QtMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtMainWindowClass: public Ui_QtMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMAINWINDOW_H
