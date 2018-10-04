#include <QApplication>
#include <QWidget>//窗口控件基类
#include <QPushButton>//按钮

int main(int argc, char **argv){
    QApplication app(argc, argv);

    QWidget widget;
    widget.setWindowTitle(QString("Hello Qt"));


//    QPushButton button;
//    button.setText("test");
//    button.show();
//    /*
//     * 不指定父对象
//     * 单独窗口显示
//     * 指定后 父对象显示，子对象默认显示
//     * setParent()
//     * 通过构造函数传参
//    */

    QPushButton button;
    button.setText("test");
    button.setParent(&widget);
    button.move(100, 100);//移动坐标

    QPushButton button2(&widget);//构造参数传参
    button2.setText("test2");

    widget.show();
    app.exec();
    return 0;
}
