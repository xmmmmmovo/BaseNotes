/*
 * http服务封装，用以支持带有超时的同步http申请
 * created by luowx on 2015-12-18
 */
#ifndef NETSERVER_H
#define NETSERVER_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>

/*
 * http post 数据到服务器
*/
class PostNetServer :public QObject
{
    Q_OBJECT
public:
    PostNetServer(QObject *parent = 0);
    void post(const QString& strUrl, const QByteArray& strData);
    void post(const QString& strUrl, const QByteArray& strData, int timeout);

    inline const QString& reply(){return m_reply;}
signals:
    void response(int len);
    void error(int errCode);
    void receiveData(QByteArray data);

public slots:
    void replyFinished(QNetworkReply *reply);
    void slotTimeOut();
private:
    QNetworkAccessManager *m_manager;
    QTimer *m_pTimer;
    QString m_url;
    QDateTime m_dateTime;

    QString m_reply;
};


#endif // NETSERVER_H
