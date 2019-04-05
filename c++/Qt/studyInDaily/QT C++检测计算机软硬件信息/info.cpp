#pragma execution_character_set("utf-8")

#include "info.h"
#include "checkdlg.h"
#include <QApplication>

#include <QHostAddress>
#include <QNetworkInterface>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSysInfo>
#include "QSettings"
#include "QDebug"
#include <QDesktopWidget>
#include <QFileInfoList>
#include <QDir>
#include <QLibrary>
#include <QTimer>
#include <QHostInfo>

#define GB (1024 * 1024 * 1024)
#define MB (1024 * 1024)
#define KB (1024)

Info *Info::instance()
{
    static Info instace;
    return &instace;
}

/*************************基本信息***************************/
Info::Info(QObject *parent)
    :QObject(parent),
      m_freeMem(0),
      m_totalMem(0),
      m_maxFreeDisk(0.0),
      m_cpuDescribe(""),
      m_memDescribe(""),
      m_osDescirbe(""),
      m_screenDescribe(""),
      m_diskDescribe(""),
      m_officeDecsribe("")
{
    ItemStatus status;
    QString describe;

    checkOffice(status, describe);
//    publicIp();
//    bool ok = ipLive();
//    int a = 10;
}

const QString Info::localmachineName()
{
    QString machineName = QHostInfo::localHostName();
    return machineName;
}

//IP地址
const QString Info::ip()
{
    QString ip="";

    QList<QNetworkInterface> interFaceList = QNetworkInterface::allInterfaces();
    for(int i=0; i< interFaceList.size(); i++)
    {
        QNetworkInterface interface = interFaceList.at(i);
        if(interface.flags().testFlag(QNetworkInterface::IsRunning))
        {
            QList<QNetworkAddressEntry> entryList = interface.addressEntries();
            foreach(QNetworkAddressEntry entry, entryList)
            {
                if(QAbstractSocket::IPv4Protocol == entry.ip().protocol() &&
                   entry.ip() != QHostAddress::LocalHost && entry.ip().toString().startsWith("192.168."))
                {
                    ip = entry.ip().toString();
                    break;
                }
            }
        }
    }

    return ip;
}

const QString Info::publicIp()
{
    QString strIp;
    QString webCode = getHtml("http://whois.pconline.com.cn/");

    if(!webCode.isEmpty())
    {
        QString web = webCode.replace(" ", "");
        web = web.replace("\r", "");
        web = web.replace("\n", "");
        QStringList list = web.split("<br/>");
        QString tar = list[3];
        QStringList ip = tar.split("=");
        strIp = ip[1];
    }
    else
        strIp="无法获取公网ip";


    return strIp;
}

const QString Info::diskId()
{
    QString diskId;
    QLibrary diskLib("diskid.dll");
    if (diskLib.load())
    {
        GetDiskIdFun GetDiskId = (GetDiskIdFun)diskLib.resolve("GetHardDriveSerialNumber");
        if (GetDiskId)
        {
            char diskIdBuff[255];
            int result = GetDiskId(diskIdBuff,255);
            if(result)
            {
                diskId = diskIdBuff;
            }
        }
        diskLib.unload();
    }

    return diskId;
}

const QString Info::mac()
{
    QString strMac;

    QList<QNetworkInterface> netList = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface item, netList)
    {
        if((QNetworkInterface::IsUp & item.flags()) && (QNetworkInterface::IsRunning & item.flags()))
        {
            if(strMac.isEmpty() || strMac < item.hardwareAddress())
            {
                strMac = item.hardwareAddress();
            }
        }
    }
    return strMac;
}

const QString& Info::cpuType()
{
    QSettings *CPU = new QSettings("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",QSettings::NativeFormat);
    m_cpuDescribe = CPU->value("ProcessorNameString").toString();
    delete CPU;

    return m_cpuDescribe;
}

const QString Info::dCard()
{
    QString dcard;
    QSettings *DCard = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\services\\nvlddmkm\\Device0",QSettings::NativeFormat);
    QString type = DCard->value("Device Description").toString();
    delete DCard;

    QString dType = type;
    dType.trimmed();
    if(!dType.isEmpty())
        dcard = dType;

    DCard = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\igfx\\Device0",QSettings::NativeFormat);
    type = DCard->value("Device Description").toString();
    delete DCard;

    dType = type;
    dType.trimmed();
    if(!dType.isEmpty())
        dcard = dcard + "\n" +dType;

    DCard = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\amdkmdap\\Device0",QSettings::NativeFormat);
    type = DCard->value("Device Description").toString();
    delete DCard;

    dType = type;
    dType.trimmed();
    if(!dType.isEmpty())
        dcard = dcard + "\n" +dType;

    dcard.trimmed();
    return dcard;
}

#include <Windows.h>
const QString& Info::memory()
{
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx(&statex);
    m_totalMem = statex.ullTotalPhys  * 1.0/ GB;
    m_freeMem = statex.ullAvailPhys * 1.0 / GB;

    m_memDescribe = QString("可用 %1 GB / 共 %2 GB" ).
            arg(QString::asprintf("%.2f", m_freeMem)).arg(QString::asprintf("%.2f", m_totalMem));

    return m_memDescribe;
}

const QString& Info::osVersion()
{
    typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
    LPFN_ISWOW64PROCESS fnIsWow64Process;
    BOOL bIsWow64 = FALSE;
    fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress( GetModuleHandle(TEXT("kernel32")),"IsWow64Process");
    if (NULL != fnIsWow64Process)
    {
        fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
    }
    QString sysBit = "unknown";
    if(bIsWow64)
        sysBit = "64位";
    else
        sysBit = "32位";

    m_osDescirbe = QSysInfo::prettyProductName() + " " + sysBit;
    return m_osDescirbe;
}

const QString& Info::screen()
{
    m_screenDescribe = "";
    QList<QSize> screenSizeList;
    QList <int> screenCountList;

    for(int i=0; i<QApplication::desktop()->screenCount(); i++)
    {
        QRect screenRect = QApplication::desktop()->screenGeometry(i);
        QSize size(screenRect.width(), screenRect.height());

        bool bExist = false;
        for(int j=0; j<screenSizeList.length(); j++)
        {
            QSize existSize = screenSizeList.at(j);
            if(size == existSize)
            {
                screenCountList[j]++;
                bExist = true;
                break;
            }
        }

        if(!bExist)
        {
            screenSizeList.append(size);
            screenCountList.append(1);
        }
    }

    m_maxScreenSize = screenSizeList.at(0);
    for(int i=0; i<screenSizeList.length(); i++)
    {
        int width = screenSizeList.at(i).width();
        int height = screenSizeList.at(i).height();

        if(width > m_maxScreenSize.width() && height > m_maxScreenSize.height())
            m_maxScreenSize = screenSizeList.at(i);

        m_screenDescribe += QString ("(%1像素 x %2像素) x %3个").arg(width).arg(height).arg(screenCountList.at(i));
        if(i!= screenSizeList.length()-1)
            m_screenDescribe += "、 ";
    }

    return m_screenDescribe;
}

const QString& Info::disk()
{
    m_diskDescribe = "";
    QFileInfoList list = QDir::drives();
    foreach (QFileInfo dir, list)
    {
        QString dirName = dir.absolutePath();
        dirName.remove("/");
        LPCWSTR lpcwstrDriver = (LPCWSTR)dirName.utf16();
        ULARGE_INTEGER liFreeBytesAvailable, liTotalBytes, liTotalFreeBytes;
        if(GetDiskFreeSpaceEx(lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes) )
        {
            QString free = QString::number((double) liTotalFreeBytes.QuadPart / GB, 'f', 1);
            free += "G";
            QString all = QString::number((double) liTotalBytes.QuadPart / GB, 'f', 1);
            all += "G";

            QString str = QString("%1 %2/%3       ").arg(dirName, free, all);
            m_diskDescribe += str;

            double freeMem = (double) liTotalFreeBytes.QuadPart / GB;

            if(freeMem > m_maxFreeDisk)
                m_maxFreeDisk = freeMem;
        }
    }

    return m_diskDescribe;
}

/*************************逐项检测***************************/
void Info::checkCPU(ItemStatus &status, QString &describe)
{
    if(m_cpuDescribe.isEmpty())
        cpuType();

    status = Item_Status_Success;
    describe = m_cpuDescribe;
}

void Info::checkMemory(ItemStatus &status, QString &describe)
{
    if(m_totalMem <= 0)
        memory();

    int nMem = m_totalMem;
    if(nMem <= 2)
    {
        status = Item_Status_Failed;
        describe = "运行内存低于2G，不适合安装终端。";
    }
    else if(nMem > 2 && nMem <= 4)
    {
        status = Item_Status_Warning;
        describe = "运行内存低于4G，会造成终端运行效果较差。";
    }
    else
    {
        status = Item_Status_Success;
        describe = m_memDescribe;
    }

}

void Info::checkOS(ItemStatus &status, QString &describe)
{
    QSettings *os = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",QSettings::NativeFormat);
    float version = os->value("CurrentVersion").toFloat();
    delete os;
    if(version < 6.0)
    {
        status = Item_Status_Failed;
        describe = "操作系统低于windows 7 ,不能正常安装终端";
    }
    else
    {
        status = Item_Status_Success;
        if(m_osDescirbe.isEmpty())
            describe = osVersion();
        else
            describe = m_osDescirbe;
    }
}

void Info::checkScreen(ItemStatus &status, QString &describe)
{
    if(m_maxScreenSize.width() <= 0 || m_maxScreenSize.height() << 0)
        screen();

    if(m_maxScreenSize.width() < 1366 || m_maxScreenSize.height() < 800)
    {
        status = Item_Status_Warning;
        describe = "屏幕分辨率较低，不能获取最佳体验效果。";
    }
    else
    {
        status = Item_Status_Success;
        describe = m_screenDescribe;
    }
}

void Info::checkDisk(ItemStatus &status, QString &describe)
{
    if(m_maxFreeDisk <= 0)
        disk();

    if(m_maxFreeDisk < 5)
    {
        status = Item_Status_Failed;
        describe = "磁盘空间不足，不能安装终端。";
    }
    else if(m_maxFreeDisk >= 5 && m_maxFreeDisk < 10)
    {
        status = Item_Status_Warning;
        describe = "磁盘空间紧张，可能会影响用户体验。";
    }
    else
    {
        status = Item_Status_Success;
        describe = m_diskDescribe;
    }
}

void Info::checkOffice(ItemStatus &status, QString &describe)
{
    QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\excel.exe", QSettings::NativeFormat);
    QString path = settings.value("Path").toString();
    if(!path.isEmpty())
    {
        QSettings versionSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Classes\\Excel.Application\\CurVer", QSettings::NativeFormat);
        QString version = versionSettings.value(".").toString();
        if(!version.isEmpty())
        {
            version = version.split(".").last();
            int versionNum = version.toInt();
            switch (versionNum)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    m_officeDecsribe = "Office 95以前版本";
                    break;
                case 6:
                    m_officeDecsribe = "Office 95";
                    break;
                case 8:
                    m_officeDecsribe = "Office 97";
                    break;
                case 9:
                    m_officeDecsribe = "Office 2000";
                    break;
                case 10:
                    m_officeDecsribe = "Office XP";
                    break;
                case 11:
                    m_officeDecsribe = "Office 2003";
                    break;
                case 12:
                    m_officeDecsribe = "Office 2007";
                    break;
                case 13:
                case 14:
                    m_officeDecsribe = "Office 2010";
                    break;
                case 15:
                    m_officeDecsribe = "Office 2013";
                    break;
                case 16:
                case 17:
                case 18:
                case 19:
                    m_officeDecsribe = "Office 2013以后版本";
                    break;
            default:
                break;
            }

            if(versionNum >= 13)//office 2010
            {
                status = Item_Status_Success;
                describe = "已安装Office 版本：" + m_officeDecsribe;
            }
            else
            {
                status = Item_Status_Warning;
                describe = "建议安装Microsoft Offce2010以上版本，否者无法使用Excel插件等功能。";
            }
        }
        else
        {
            status = Item_Status_Warning;
            describe = "建议安装Microsoft Offce2010以上版本，否者无法使用Excel插件等功能。";
        }
    }
    else
    {
        status = Item_Status_Warning;
        describe = "建议安装Microsoft Offce2010以上版本，否者无法使用Excel插件等功能。";
    }
}

void Info::checkNet(ItemStatus &status, QString &describe)
{
    if(ipLive())//网络畅通
    {
        status = Item_Status_Success;
        describe = "网络畅通";
    }
    else
    {
        status = Item_Status_Failed;
        describe = "网络状况较差或者无法直接连接外网";
    }
}

//获取网页所有源代码
QString Info::getHtml(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
    QByteArray responseData;
    QEventLoop eventLoop;
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);

    connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
    connect(timer, SIGNAL(timeout()), &eventLoop, SLOT(quit()));

    timer->start(300);
    eventLoop.exec();
    responseData = reply->readAll();

    delete timer;

    return QString(responseData);
}

//判断IP地址及端口是否在线
bool Info::ipLive()
{
    //能接通百度IP说明可以通外网
    QTcpSocket tcpClient;
    tcpClient.abort();
    tcpClient.connectToHost("202.108.22.5", 80);
    //100毫秒没有连接上则判断不在线
    return tcpClient.waitForConnected(100);
}
