# QT笔记

### QT自学笔记 [自学视频](https://www.bilibili.com/video/av29338407)

## HelloQT

- 了解文件结构
- 了解基本的库函数
- 学习父对象

## SignalAndSlot

- 标准信号和槽
- 自定义槽函数
- 自定义信号

## QTCoordinate

- 带参数的自定义信号
- Lamda表达式

- 坐标系统

## QMainWindow

- 内存回收机制
- 菜单栏
- 工具栏
- 状态栏
- 核心控件
- 浮动窗口

## Dialog

- 模态对话框
- 非模态对话框
- 标准对话框
- 文件对话框

## Parts & Layouts

- 坐标系统
- 设计器（ui）
- 常用控件
- 布局
- 自定义控件
- qt样式表

## QFile & QDataStream

- 读写文件
- 数据流
- QBuffer

## DataBase

- 数据库增删改查
- QSQLITE
- 可视化数据库操作

## 未看集数

- 27
- 28-44
- 47
- 51-84
- 90-100

[保存应用程序设置（QSettings）](https://www.cnblogs.com/cy568searchx/p/3653390.html)

[Qt中QString,int,char,QByteArray之间相互转换](https://blog.csdn.net/ymc0329/article/details/7284514)

[Qt技巧：sqlite数据库 判断表是否存在](https://blog.csdn.net/imxiangzi/article/details/52612220)

## 关闭前的事件

```c++
#include <QEvent>
#include <QCloseEvent>//需要添加的头文件

//覆写关闭事件 实现关闭前保存
void MainWindow::closeEvent(QCloseEvent *event){
    if(infodialog.ifChanged){
        int ok = QMessageBox::warning(this,tr("确认保存!"),tr("您还有尚未保存的条目，请问是否保存！"),
            QMessageBox::Yes,QMessageBox::No);
        if(ok == QMessageBox::Yes){
            model->submitAll();//是则保存
            event->accept();
        }else{
            event->ignore();
        }
    }
}
```

