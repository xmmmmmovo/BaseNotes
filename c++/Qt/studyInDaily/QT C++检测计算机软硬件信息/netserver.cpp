#pragma execution_character_set("utf-8")
#include "netserver.h"
#include <QDebug>

PostNetServer::PostNetServer(QObject *parent) :
    QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &PostNetServer::replyFinished);

    m_pTimer = new QTimer(this);
    m_pTimer->setSingleShot(true);
    connect(m_pTimer, &QTimer::timeout,
            this, &PostNetServer::slotTimeOut);
}

void PostNetServer::post(const QString& strUrl, const QByteArray& strData)
{
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::SslV3);
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setSslConfiguration(config);
    request.setUrl(QUrl(strUrl));

    m_manager->post(request, strData);
}

void PostNetServer::post(const QString &strUrl, const QByteArray &strData, int timeout)
{
    m_pTimer->start(timeout);
    post(strUrl, strData);
}

void PostNetServer::replyFinished(QNetworkReply *reply)
{
    m_pTimer->stop();
    if(reply && reply->error() == QNetworkReply::NoError)
    {
        QByteArray data = reply->readAll();
        int len = data.size();
        emit this->response(len);
        emit this->receiveData(data);

        m_reply = data;
    }
    else
    {
        emit this->error((int)reply->error());
    }
    reply->deleteLater();
}

void PostNetServer::slotTimeOut()
{
    emit error(QNetworkReply::TimeoutError);
}


