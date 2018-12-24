/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeWidget *bookTree;
    QHBoxLayout *horizontalLayout;
    QLabel *searchText;
    QLineEdit *searchLineEdit;
    QComboBox *choseSearchLabel;
    QSpacerItem *horizontalSpacer;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(900, 536);
        MainMenu->setMinimumSize(QSize(900, 536));
        MainMenu->setMaximumSize(QSize(900, 536));
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bookTree = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        bookTree->setHeaderItem(__qtreewidgetitem);
        bookTree->setObjectName(QStringLiteral("bookTree"));

        gridLayout->addWidget(bookTree, 1, 0, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        searchText = new QLabel(centralwidget);
        searchText->setObjectName(QStringLiteral("searchText"));
        searchText->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(searchText);

        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);

        choseSearchLabel = new QComboBox(centralwidget);
        choseSearchLabel->addItem(QString());
        choseSearchLabel->addItem(QString());
        choseSearchLabel->addItem(QString());
        choseSearchLabel->setObjectName(QStringLiteral("choseSearchLabel"));

        horizontalLayout->addWidget(choseSearchLabel);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        MainMenu->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainMenu);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainMenu->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", nullptr));
        searchText->setText(QApplication::translate("MainMenu", "\346\220\234\347\264\242\345\206\205\345\256\271", nullptr));
        choseSearchLabel->setItemText(0, QApplication::translate("MainMenu", "\344\271\246\347\261\215\345\220\215\347\247\260", nullptr));
        choseSearchLabel->setItemText(1, QApplication::translate("MainMenu", "\344\271\246\347\261\215\347\261\273\345\236\213", nullptr));
        choseSearchLabel->setItemText(2, QApplication::translate("MainMenu", "\344\271\246\347\261\215\347\274\226\345\217\267", nullptr));

        toolBar->setWindowTitle(QApplication::translate("MainMenu", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
