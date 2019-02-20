#pragma once

#include <QtWidgets/QMainWindow>
#include <qimage.h>
#include "ui_QtMainWindow.h"

class QtMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QtMainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtMainWindowClass ui;
	void paintEvent(QPaintEvent * event);

	QImage img;
};
