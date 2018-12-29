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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QAction *openBookLib;
    QAction *addBook;
    QAction *deleteAllSameBook;
    QAction *deleteThisBook;
    QAction *lendThisBook;
    QAction *backThisBook;
    QAction *saveAsFile;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *searchText;
    QLineEdit *searchLineEdit;
    QComboBox *choseSearchLabel;
    QSpacerItem *verticalSpacer;
    QTreeWidget *bookTree;
    QTextBrowser *bookInfo;
    QTreeView *treeView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(900, 536);
        MainMenu->setMinimumSize(QSize(900, 536));
        MainMenu->setMaximumSize(QSize(900, 536));
        openBookLib = new QAction(MainMenu);
        openBookLib->setObjectName(QStringLiteral("openBookLib"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/actions/fileopen.png"), QSize(), QIcon::Normal, QIcon::On);
        openBookLib->setIcon(icon);
        addBook = new QAction(MainMenu);
        addBook->setObjectName(QStringLiteral("addBook"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/actions/add.png"), QSize(), QIcon::Normal, QIcon::On);
        addBook->setIcon(icon1);
        deleteAllSameBook = new QAction(MainMenu);
        deleteAllSameBook->setObjectName(QStringLiteral("deleteAllSameBook"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/actions/edit-delete.png"), QSize(), QIcon::Normal, QIcon::On);
        deleteAllSameBook->setIcon(icon2);
        deleteThisBook = new QAction(MainMenu);
        deleteThisBook->setObjectName(QStringLiteral("deleteThisBook"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/actions/gtk-remove.png"), QSize(), QIcon::Normal, QIcon::On);
        deleteThisBook->setIcon(icon3);
        lendThisBook = new QAction(MainMenu);
        lendThisBook->setObjectName(QStringLiteral("lendThisBook"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/actions/stock_right.png"), QSize(), QIcon::Normal, QIcon::On);
        lendThisBook->setIcon(icon4);
        backThisBook = new QAction(MainMenu);
        backThisBook->setObjectName(QStringLiteral("backThisBook"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/actions/object-rotate-left.png"), QSize(), QIcon::Normal, QIcon::On);
        backThisBook->setIcon(icon5);
        saveAsFile = new QAction(MainMenu);
        saveAsFile->setObjectName(QStringLiteral("saveAsFile"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/actions/filesaveas.png"), QSize(), QIcon::Normal, QIcon::On);
        saveAsFile->setIcon(icon6);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        bookTree = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        bookTree->setHeaderItem(__qtreewidgetitem);
        bookTree->setObjectName(QStringLiteral("bookTree"));

        gridLayout->addWidget(bookTree, 0, 0, 3, 1);

        bookInfo = new QTextBrowser(centralwidget);
        bookInfo->setObjectName(QStringLiteral("bookInfo"));

        gridLayout->addWidget(bookInfo, 2, 1, 1, 1);

        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout->addWidget(treeView, 3, 0, 1, 1);

        MainMenu->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainMenu);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainMenu->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(openBookLib);
        toolBar->addAction(saveAsFile);
        toolBar->addSeparator();
        toolBar->addAction(addBook);
        toolBar->addAction(deleteAllSameBook);
        toolBar->addAction(deleteThisBook);
        toolBar->addSeparator();
        toolBar->addAction(lendThisBook);
        toolBar->addAction(backThisBook);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", nullptr));
        openBookLib->setText(QApplication::translate("MainMenu", "\346\211\223\345\274\200\345\233\276\344\271\246\347\263\273\347\273\237\346\226\207\344\273\266", nullptr));
        addBook->setText(QApplication::translate("MainMenu", "\346\267\273\345\212\240\344\271\246\347\261\215", nullptr));
        deleteAllSameBook->setText(QApplication::translate("MainMenu", "\345\210\240\351\231\244\346\225\264\347\261\273\344\271\246\347\261\215", nullptr));
        deleteThisBook->setText(QApplication::translate("MainMenu", "\345\210\240\351\231\244\346\255\244\346\234\254\344\271\246", nullptr));
        lendThisBook->setText(QApplication::translate("MainMenu", "\345\207\272\345\200\237\346\255\244\347\261\273\344\271\246", nullptr));
        backThisBook->setText(QApplication::translate("MainMenu", "\345\275\222\350\277\230\346\255\244\347\261\273\344\271\246", nullptr));
        saveAsFile->setText(QApplication::translate("MainMenu", "\346\255\244\347\263\273\347\273\237\345\217\246\345\255\230\344\270\272", nullptr));
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
