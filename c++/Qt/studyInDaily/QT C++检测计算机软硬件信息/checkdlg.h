#ifndef CHECKDLG_H
#define CHECKDLG_H

#include <QDialog>
#include <QEventLoop>
#include "commonmovedialog.h"
#include "itemdelegate.h"

namespace Ui {
class CheckDlg;
}

enum ItemStatus
{
    Item_Status_Waitting = 0,//等待检测
    Item_Status_Checking = 1,//正在检测
    Item_Status_Success = 2,//通过
    Item_Status_Warning = 3,//警告
    Item_Status_Failed = 4,//未通过
    Item_Status_None = 5//不显示
};

typedef struct
{
    QString key;//
    QString describe;//未通过（警告）描述
    ItemStatus status;//状态
}itemData;

class CheckDlg : public CommonMoveDialog
{
    Q_OBJECT

public:
    explicit CheckDlg(QWidget *parent = 0);
    ~CheckDlg();
private:
    void initFrame();
    void connection();
    void initData();
    void getInfo();
    int getRowIndex(const QString &key);
    void successByKey(const QString &key);//检查成功
    void successByIndex(int index);//检查成功
    void warningOrFailedByIndex(int index, const ItemStatus status, const QString &descirbe="检查不通过，请查找具体原因！");//警告或失败
    void checkingByIndex(int index);//正在检测

    void checkingFinished();//检测完成

    void generatReportData();//生成报告数据

    void uploadReportData();//上传报告

    void refreshResult(ItemStatus status);

signals:
    //上传成功信号
    void uploadFinished();

private slots:
    void startChecking();
    void on_closeBtn_clicked();

    void on_saveBtn_clicked();
    void allLableClicked();
    void passLableClicked();
    void warnningLableClicked();
    void failLabelClicked();

public slots:
    void postReceiveData(QByteArray data);
    void postFinished(int len);
    void postError(int errCode);

private:
    Ui::CheckDlg *ui;
    ItemDelegate *m_pItemDelegate;
    QStringList m_itemNames;//所有检查项名称（key）
    QStringList m_itemsStatus;
    QList <itemData> m_listItemsData;
    int m_successCount;
    int m_warningCount;
    int m_failedCount;

    QByteArray m_data;
    QEventLoop m_eventLoop;


};

#endif // CHECKDLG_H
