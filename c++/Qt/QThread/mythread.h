#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    //线程处理函数
    //不能之间调用 只能通过.start()调用
    //虚函数
    void run();

signals:
    void isDone();

public slots:
};

#endif // MYTHREAD_H
