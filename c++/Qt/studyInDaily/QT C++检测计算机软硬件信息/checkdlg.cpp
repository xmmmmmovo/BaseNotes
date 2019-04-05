#pragma execution_character_set("utf-8")
#include "checkdlg.h"
#include <info.h>
#include "ui_checkdlg.h"
#include "netserver.h"
#include <QtGui>
#include <QFileDialog>
#include <QJsonDocument>
#include <QVariantMap>
#include <QMessageBox>
#include <QTime>

CheckDlg::CheckDlg(QWidget *parent) :
    CommonMoveDialog(parent),
    ui(new Ui::CheckDlg),
    m_successCount(0),
    m_warningCount(0),
    m_failedCount(0)
{
    ui->setupUi(this);
    initData();
    initFrame();
    connection();
}

CheckDlg::~CheckDlg()
{
    delete ui;
}

void CheckDlg::initFrame()
{
    this->resize(580, 380);
    ui->allValueLabel->setText("0");
    ui->passValueLabel->setText("0");
    ui->warningValueLabel->setText("0");
    ui->faileValueLabel->setText("0");

    ui->finishedLabel->setVisible(false);
    ui->saveBtn->setEnabled(false);
    ui->uploadCheckBox->setEnabled(false);

    ui->progressBar->setValue(0);

    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->stackedWidget->setCurrentIndex(0);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Fixed);

    ui->tableWidget->horizontalHeader()->resizeSection(0, 20);
    ui->tableWidget->horizontalHeader()->resizeSection(1, 55);
    ui->tableWidget->horizontalHeader()->resizeSection(2, 80);

    ui->tableWidget->horizontalHeader()->setSectionsClickable(false);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_pItemDelegate = new ItemDelegate();
    ui->tableWidget->setItemDelegate(m_pItemDelegate);

    int rowCount = m_itemNames.size();
    ui->tableWidget->setRowCount(rowCount);
    for(int i=0; i<rowCount; i++)
    {
        QString data;
        QTableWidgetItem *item0 = new QTableWidgetItem();
        item0->setData(Qt::UserRole, Item_Status_Waitting);
        ui->tableWidget->setItem(i,1,item0);

        data = m_listItemsData.at(i).key;
        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setData(Qt::DisplayRole, data);
        item1->setData(Qt::UserRole, Item_Status_Waitting);
        ui->tableWidget->setItem(i,2,item1);

        data = m_itemsStatus[m_listItemsData.at(i).status];
        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setData(Qt::DisplayRole, data);
        item2->setData(Qt::UserRole, Item_Status_Waitting);
        ui->tableWidget->setItem(i,3,item2);
    }
}

void CheckDlg::connection()
{
    connect(ui->startCheckBtn, SIGNAL(clicked(bool)), this, SLOT(startChecking()));
    connect(ui->allLabel, SIGNAL(clicked()), this, SLOT(allLableClicked()));
    connect(ui->allValueLabel, SIGNAL(clicked()), this, SLOT(allLableClicked()));

    connect(ui->passLabel, SIGNAL(clicked()), this, SLOT(passLableClicked()));
    connect(ui->passValueLabel, SIGNAL(clicked()), this, SLOT(passLableClicked()));

    connect(ui->warningLabel, SIGNAL(clicked()), this, SLOT(warnningLableClicked()));
    connect(ui->warningValueLabel, SIGNAL(clicked()), this, SLOT(warnningLableClicked()));

    connect(ui->faileLabel, SIGNAL(clicked()), this, SLOT(failLabelClicked()));
    connect(ui->faileValueLabel, SIGNAL(clicked()), this, SLOT(failLabelClicked()));
}

void CheckDlg::initData()
{
    m_itemNames.clear();
    m_itemNames.append("CPU处理器");
    m_itemNames.append("运行内存");
    m_itemNames.append("操作系统");
    m_itemNames.append("屏幕分辨率");
    m_itemNames.append("磁盘空间");
    m_itemNames.append("office");
    m_itemNames.append("网络带宽");

    m_itemsStatus.clear();
    m_itemsStatus.append("等待检测");
    m_itemsStatus.append("正在检测");
    m_itemsStatus.append("通过");
    m_itemsStatus.append("警告");
    m_itemsStatus.append("未通过");

    m_listItemsData.clear();
    for(int i=0; i<m_itemNames.size(); i++)
    {
        itemData data;
        data.key = m_itemNames.at(i);
        data.status = ItemStatus::Item_Status_Waitting;

        m_listItemsData.append(data);
    }
}

void CheckDlg::getInfo()
{
    QString machineName = Info::instance()->localmachineName();
    ui->computerValueLabel->setText(machineName);
    QString cpu = Info::instance()->cpuType();
    ui->cpuValueLabel->setText(cpu);
    QString strDcard = Info::instance()->dCard();
    ui->dCardValueLabel->setText(strDcard);
    QString disk = Info::instance()->disk();
    ui->diskValueLabel->setText(disk);
    QString mem = Info::instance()->memory();
    ui->memValueLabel->setText(mem);
    QString os = Info::instance()->osVersion();
    ui->osValueLabel->setText(os);
    QString screen = Info::instance()->screen();
    ui->screenValueLabel->setText(screen);

    int rowCount = ui->tableWidget->rowCount();
    ui->allValueLabel->setText(QString("%1").arg(rowCount));

    for(int i=0; i<m_listItemsData.length(); i++)
    {
        ItemStatus status;
        QString describe;
        if(m_listItemsData[i].key == "CPU处理器")
        {
            Info::instance()->checkCPU(status, describe);
        }
        else if(m_listItemsData[i].key == "运行内存")
        {
            Info::instance()->checkMemory(status, describe);
        }
        else if(m_listItemsData[i].key == "操作系统")
        {
            Info::instance()->checkOS(status, describe);
        }
        else if(m_listItemsData[i].key == "屏幕分辨率")
        {
            Info::instance()->checkScreen(status, describe);
        }
        else if(m_listItemsData[i].key == "磁盘空间")
        {
            Info::instance()->checkDisk(status, describe);
        }
        else if(m_listItemsData[i].key == "office")
        {
            Info::instance()->checkOffice(status, describe);
        }
        else if(m_listItemsData[i].key == "网络带宽")
        {
            Info::instance()->checkNet(status, describe);
        }

        m_listItemsData[i].status = status;
        m_listItemsData[i].describe = describe;

        int index = getRowIndex(m_listItemsData[i].key);

        if(Item_Status_Success == status)
        {
            successByIndex(index);
        }
        else if(Item_Status_Warning == status)
        {
            warningOrFailedByIndex(index, Item_Status_Warning, describe);
        }
        else if(Item_Status_Failed == status)
        {
            warningOrFailedByIndex(index, Item_Status_Failed, describe);
        }

        int percent = (i+1) * 100 / m_listItemsData.length();
        ui->progressBar->setValue(percent);
    }
    checkingFinished();
}

int CheckDlg::getRowIndex(const QString &key)
{
    int currentRow = -1;
    int rowCount = ui->tableWidget->rowCount();
    for(int i=0; i<rowCount; i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 2);
        QString name = item->text();
        if(key == name)
        {
            currentRow = i;
            break;
        }
    }

    return currentRow;
}

void CheckDlg::successByKey(const QString &key)
{
    successByIndex(getRowIndex(key));
}

void CheckDlg::successByIndex(int index)
{
    if(index >=  0 && index < ui->tableWidget->rowCount())
    {
        QTableWidgetItem *item1 = ui->tableWidget->item(index, 1);
        item1->setData(Qt::UserRole, Item_Status_Success);

        QTableWidgetItem *item2 = ui->tableWidget->item(index, 2);
        item2->setData(Qt::UserRole, Item_Status_Success);

        QTableWidgetItem *item3 = ui->tableWidget->item(index, 3);
        item3->setData(Qt::DisplayRole, m_itemsStatus[Item_Status_Success]);
        item3->setData(Qt::UserRole, Item_Status_Success);

        m_successCount++;
        ui->passValueLabel->setText(QString("%1").arg(m_successCount));
    }
}

void CheckDlg::warningOrFailedByIndex(int index, const ItemStatus status, const QString &descirbe)
{
    if(index >=  0 && index < ui->tableWidget->rowCount())
    {
        QTableWidgetItem *item0 = ui->tableWidget->item(index, 1);
        item0->setData(Qt::UserRole, status);

        QTableWidgetItem *item1 = ui->tableWidget->item(index, 2);
        item1->setData(Qt::UserRole, status);

        QTableWidgetItem *item2 = ui->tableWidget->item(index, 3);
        item2->setData(Qt::DisplayRole, m_itemsStatus[status]);
        item2->setData(Qt::UserRole, status);

        //插入新行
        ui->tableWidget->insertRow(index+1);

        QTableWidgetItem *item5 = new QTableWidgetItem();
        item5->setData(Qt::UserRole, Item_Status_None);
        ui->tableWidget->setItem(index+1, 1, item5);

        QString msg = "描述: " + descirbe;
        QTableWidgetItem *item6 = new QTableWidgetItem();
        item6->setData(Qt::DisplayRole, msg);
        item6->setData(Qt::UserRole+1, "describe");
        ui->tableWidget->setItem(index+1, 2, item6);

        if(Item_Status_Warning == status)
        {
            m_warningCount++;
            ui->warningValueLabel->setText(QString("%1").arg(m_warningCount));
        }
        else if(Item_Status_Failed == status)
        {
            m_failedCount++;
            ui->faileValueLabel->setText(QString("%1").arg(m_failedCount));
        }
    }
}

void CheckDlg::checkingByIndex(int index)
{
    if(index >=  0 && index < ui->tableWidget->rowCount())
    {
        QTableWidgetItem *item0 = ui->tableWidget->item(index, 0);
        item0->setData(Qt::UserRole, true);

        QTableWidgetItem *item1 = ui->tableWidget->item(index, 1);
        item1->setData(Qt::UserRole, Item_Status_Success);

        QTableWidgetItem *item3 = ui->tableWidget->item(index, 3);
        QString data = m_itemsStatus[Item_Status_Checking];
        item3->setData(Qt::DisplayRole,data);
    }
}

void CheckDlg::checkingFinished()
{
    ui->progressBar->setValue(100);
    ui->finishedLabel->show();
    ui->checkingLabel->hide();
    ui->checkingValueLabel->hide();
    ui->progressBar->hide();

    ui->saveBtn->setEnabled(true);
    ui->uploadCheckBox->setEnabled(true);
}

void CheckDlg::generatReportData()
{
    //收集保存的数据
    QList<QVariant> resultList;

    //计算机名称
    QVariantMap map;
    map["项目"] = "计算机名称";
    map["检查结果"] = "通过";
    map["描述"] = Info::instance()->localmachineName();

    QVariant value;
    value.setValue(map);
    resultList.append(value);

    //显示的检查项
    for(int i=0; i<m_listItemsData.length(); i++)
    {
        itemData item = m_listItemsData.at(i);
        QVariantMap map;
        map["项目"] = item.key;
        map["检查结果"] = m_itemsStatus[item.status];
        map["描述"] = item.describe;

        QVariant value;
        value.setValue(map);
        resultList.append(value);
    }

    //显卡
    map["项目"] = "显卡";
    map["检查结果"] = "通过";
    map["描述"] = Info::instance()->dCard().trimmed();

    value.setValue(map);
    resultList.append(value);

    //硬盘号
    map["项目"] = "硬盘号";
    map["检查结果"] = "通过";
    map["描述"] = Info::instance()->diskId();
    value.setValue(map);
    resultList.append(value);

    //内网ip
    map["项目"] = "内网ip";
    map["检查结果"] = "通过";
    map["描述"] = Info::instance()->ip();
    value.setValue(map);
    resultList.append(value);

    //外网ip
    map["项目"] = "公网ip";
    map["检查结果"] = "通过";
    map["描述"] = Info::instance()->publicIp();
    value.setValue(map);
    resultList.append(value);

    //是否可以在线
    QString describe = Info::instance()->ipLive() ? "网络正常" : "网络状况较差或者无法直接连接外网";
    map["项目"] = "是否在线";
    map["检查结果"] = "通过";
    map["描述"] = describe;
    value.setValue(map);
    resultList.append(value);

    QVariantMap map1;
    map1["mac"] = Info::instance()->mac();
    map1["items"] = resultList;

    QJsonDocument jsonDocument = QJsonDocument::fromVariant(map1);
    m_data =jsonDocument.toJson();
}

void CheckDlg::uploadReportData()
{
    if(m_data.isEmpty())
        generatReportData();

    QString data = m_data;
    data.remove("\n");
    data.remove(" ");

    m_data = data.toUtf8();

    QString strUrl = "https://172.17.20.171/xhs_admin/index.php/manage/Test_report/add_test_report";

    connect(this,SIGNAL(uploadFinished()),
            &m_eventLoop, SLOT(quit()));
    QTimer timer;
    connect(&timer, &QTimer::timeout, &m_eventLoop, &QEventLoop::quit);
    timer.setInterval(5000);//最多等待3S
    timer.setSingleShot(true);

    PostNetServer postNetServer;
    connect(&postNetServer, SIGNAL(receiveData(QByteArray)), this, SLOT(postReceiveData(QByteArray)));
    connect(&postNetServer, SIGNAL(error(int)), this, SLOT(postError(int)));

    postNetServer.post(strUrl, m_data);

    timer.start();

    m_eventLoop.exec();
}

void CheckDlg::refreshResult(ItemStatus status)
{
    ui->tableWidget->clearContents();
    int rowCount = 0;
    if(Item_Status_Success == status)
    {
        if(0 >= m_successCount)
            return;

        rowCount = m_successCount;
    }
    else if(Item_Status_Warning == status)
    {
        if(0 >= m_warningCount)
            return;

        rowCount = m_successCount;
    }
    else if(Item_Status_Failed == status)
    {
        if(0 >= m_failedCount)
            return;

        rowCount = m_successCount;
    }
    else
    {
        rowCount = m_listItemsData.length();
    }

    ui->tableWidget->setRowCount(rowCount);

    int index = 0;
    for(int i=0; i<m_listItemsData.length(); i++)
    {
        if(Item_Status_Success == status)
        {
            if(Item_Status_Success == m_listItemsData[i].status)
            {
                QString data;
                QTableWidgetItem *item0 = new QTableWidgetItem();
                item0->setData(Qt::UserRole, Item_Status_Success);
                ui->tableWidget->setItem(index, 1, item0);

                data = m_listItemsData[i].key;
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setData(Qt::DisplayRole, data);
                item1->setData(Qt::UserRole, Item_Status_Success);
                ui->tableWidget->setItem(index, 2, item1);

                data = m_itemsStatus[Item_Status_Success];
                QTableWidgetItem *item2 = new QTableWidgetItem();
                item2->setData(Qt::DisplayRole, data);
                item2->setData(Qt::UserRole, Item_Status_Success);
                ui->tableWidget->setItem(index, 3, item2);

                index++;
            }
        }
        else if(Item_Status_Warning == status)
        {
            if(Item_Status_Warning == m_listItemsData[i].status)
            {
                QString data;
                QTableWidgetItem *item0 = new QTableWidgetItem();
                item0->setData(Qt::UserRole, Item_Status_Warning);
                ui->tableWidget->setItem(index, 1, item0);

                data = m_listItemsData[i].key;
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setData(Qt::DisplayRole, data);
                item1->setData(Qt::UserRole, Item_Status_Warning);
                ui->tableWidget->setItem(index, 2, item1);

                data = m_itemsStatus[Item_Status_Warning];
                QTableWidgetItem *item2 = new QTableWidgetItem();
                item2->setData(Qt::DisplayRole, data);
                item2->setData(Qt::UserRole, Item_Status_Warning);
                ui->tableWidget->setItem(index, 3, item2);

                index++;

                //插入新行
                ui->tableWidget->insertRow(index);

                QTableWidgetItem *item5 = new QTableWidgetItem();
                item5->setData(Qt::UserRole, Item_Status_None);
                ui->tableWidget->setItem(index, 1, item5);

                QString msg = "描述: " + m_listItemsData[i].describe;
                QTableWidgetItem *item6 = new QTableWidgetItem();
                item6->setData(Qt::DisplayRole, msg);
                item6->setData(Qt::UserRole+1, "describe");
                ui->tableWidget->setItem(index, 2, item6);

                index++;
            }
        }
        else if(Item_Status_Failed == status)
        {
            if(Item_Status_Failed == m_listItemsData[i].status)
            {
                QString data;
                QTableWidgetItem *item0 = new QTableWidgetItem();
                item0->setData(Qt::UserRole, Item_Status_Failed);
                ui->tableWidget->setItem(index, 1, item0);

                data = m_listItemsData[i].key;
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setData(Qt::DisplayRole, data);
                item1->setData(Qt::UserRole, Item_Status_Failed);
                ui->tableWidget->setItem(index, 2, item1);

                data = m_itemsStatus[Item_Status_Failed];
                QTableWidgetItem *item2 = new QTableWidgetItem();
                item2->setData(Qt::DisplayRole, data);
                item2->setData(Qt::UserRole, Item_Status_Failed);
                ui->tableWidget->setItem(index, 3, item2);

                index++;

                //插入新行
                ui->tableWidget->insertRow(index);

                QTableWidgetItem *item5 = new QTableWidgetItem();
                item5->setData(Qt::UserRole, Item_Status_None);
                ui->tableWidget->setItem(index, 1, item5);

                QString msg = "描述: " + m_listItemsData[i].describe;
                QTableWidgetItem *item6 = new QTableWidgetItem();
                item6->setData(Qt::DisplayRole, msg);
                item6->setData(Qt::UserRole+1, "describe");
                ui->tableWidget->setItem(index, 2, item6);

                index++;
            }
        }
        else
        {
            if(Item_Status_Success == m_listItemsData[i].status)
            {
                QString data;
                QTableWidgetItem *item0 = new QTableWidgetItem();
                item0->setData(Qt::UserRole, Item_Status_Success);
                ui->tableWidget->setItem(index, 1, item0);

                data = m_listItemsData[i].key;
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setData(Qt::DisplayRole, data);
                item1->setData(Qt::UserRole, Item_Status_Success);
                ui->tableWidget->setItem(index, 2, item1);

                data = m_itemsStatus[Item_Status_Success];
                QTableWidgetItem *item2 = new QTableWidgetItem();
                item2->setData(Qt::DisplayRole, data);
                item2->setData(Qt::UserRole, Item_Status_Success);
                ui->tableWidget->setItem(index, 3, item2);

                index++;
            }
            else if(Item_Status_Warning == m_listItemsData[i].status)
            {
                QString data;
                QTableWidgetItem *item0 = new QTableWidgetItem();
                item0->setData(Qt::UserRole, Item_Status_Warning);
                ui->tableWidget->setItem(index, 1, item0);

                data = m_listItemsData[i].key;
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setData(Qt::DisplayRole, data);
                item1->setData(Qt::UserRole, Item_Status_Warning);
                ui->tableWidget->setItem(index, 2, item1);

                data = m_itemsStatus[Item_Status_Warning];
                QTableWidgetItem *item2 = new QTableWidgetItem();
                item2->setData(Qt::DisplayRole, data);
                item2->setData(Qt::UserRole, Item_Status_Warning);
                ui->tableWidget->setItem(index, 3, item2);

                index++;

                //插入新行
                ui->tableWidget->insertRow(index);

                QTableWidgetItem *item5 = new QTableWidgetItem();
                item5->setData(Qt::UserRole, Item_Status_None);
                ui->tableWidget->setItem(index, 1, item5);

                QString msg = "描述: " + m_listItemsData[i].describe;
                QTableWidgetItem *item6 = new QTableWidgetItem();
                item6->setData(Qt::DisplayRole, msg);
                item6->setData(Qt::UserRole+1, "describe");
                ui->tableWidget->setItem(index, 2, item6);

                index++;
            }
            else if(Item_Status_Failed == m_listItemsData[i].status)
            {
                QString data;
                QTableWidgetItem *item0 = new QTableWidgetItem();
                item0->setData(Qt::UserRole, Item_Status_Failed);
                ui->tableWidget->setItem(index, 1, item0);

                data = m_listItemsData[i].key;
                QTableWidgetItem *item1 = new QTableWidgetItem();
                item1->setData(Qt::DisplayRole, data);
                item1->setData(Qt::UserRole, Item_Status_Failed);
                ui->tableWidget->setItem(index, 2, item1);

                data = m_itemsStatus[Item_Status_Failed];
                QTableWidgetItem *item2 = new QTableWidgetItem();
                item2->setData(Qt::DisplayRole, data);
                item2->setData(Qt::UserRole, Item_Status_Failed);
                ui->tableWidget->setItem(index, 3, item2);

                index++;

                //插入新行
                ui->tableWidget->insertRow(index);

                QTableWidgetItem *item5 = new QTableWidgetItem();
                item5->setData(Qt::UserRole, Item_Status_None);
                ui->tableWidget->setItem(index, 1, item5);

                QString msg = "描述: " + m_listItemsData[i].describe;
                QTableWidgetItem *item6 = new QTableWidgetItem();
                item6->setData(Qt::DisplayRole, msg);
                item6->setData(Qt::UserRole+1, "describe");
                ui->tableWidget->setItem(index, 2, item6);

                index++;
            }

        }
    }
}

void CheckDlg::startChecking()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->resize(1200, 800);
    getInfo();
}

//关闭对话框
void CheckDlg::on_closeBtn_clicked()
{
    this->hide();
    if(ui->uploadCheckBox->isChecked())
        uploadReportData();

    this->accept();
}

//保存结果到本地
void CheckDlg::on_saveBtn_clicked()
{
    if(m_data.isEmpty())
        generatReportData();

    QDate data = QDate::currentDate();
    QString name = data.toString("yyyyMMdd");
    QTime time = QTime::currentTime();
    name += time.toString("hhmm") + "检测结果.txt";

    //写入结果到本地文件
    QString fileName = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0) + "/" + name;
    QFile file(fileName);
    if(file.open(QFile::WriteOnly))
    {
        QString data = m_data;
        data.replace("\n", "\r\n");
        file.write(data.toUtf8());
        file.close();

        QMessageBox::information(this,"","已保存至桌面！");
    }
}

void CheckDlg::allLableClicked()
{
    refreshResult(Item_Status_None);
}

void CheckDlg::passLableClicked()
{
    refreshResult(Item_Status_Success);
}

void CheckDlg::warnningLableClicked()
{
    refreshResult(Item_Status_Warning);
}

void CheckDlg::failLabelClicked()
{
    refreshResult(Item_Status_Failed);
}

void CheckDlg::postReceiveData(QByteArray data)
{
    int a = 10;
    emit uploadFinished();
}

void CheckDlg::postFinished(int len)
{
    int a = 10;
    emit uploadFinished();
}

void CheckDlg::postError(int errCode)
{
    int a = 10;
    emit uploadFinished();
}
