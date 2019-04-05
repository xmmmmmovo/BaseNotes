#ifndef INFO_H
#define INFO_H

#include <QObject>
#include <QWidget>

enum ItemStatus;

class Info : public QObject
{
    Q_OBJECT
    typedef int (*GetDiskIdFun)(char*, int);
public:
    static Info* instance();
    Info(QObject *parent = 0);

public:
    //基本信息
    const QString localmachineName();//获取cpu 信息
    const QString& cpuType();//获取cpu 信息
    const QString dCard();//显卡信息
    const QString& memory();//内存信息
    const QString& osVersion();//操作系统信息
    const QString& screen();//屏幕分辨率信息
    const QString& disk();//硬盘信息
    const QString ip();//Ip信息

    //其他信息
    //获取硬盘号
    const QString diskId();
    //获取MAC地址
    const QString mac();
    //公网ip
    const QString publicIp();
    //判断是否在线
    bool ipLive();

    //逐项检测
    void checkCPU(ItemStatus &status, QString &describe);
    void checkMemory(ItemStatus &status, QString &describe);
    void checkOS(ItemStatus &status, QString &describe);
    void checkScreen(ItemStatus &status, QString &describe);
    void checkDisk(ItemStatus &status, QString &describe);
    void checkOffice(ItemStatus &status, QString &describe);
    void checkNet(ItemStatus &status, QString &describe);

private:
    QString getHtml(QString url);

private:
    float m_freeMem;
    float m_totalMem;
    double m_maxFreeDisk;//GB
    QSize m_maxScreenSize;

    //检查成功结果描述
    QString m_cpuDescribe;
    QString m_memDescribe;
    QString m_osDescirbe;
    QString m_screenDescribe;
    QString m_diskDescribe;
    QString m_officeDecsribe;
};

#endif // INFO_H
