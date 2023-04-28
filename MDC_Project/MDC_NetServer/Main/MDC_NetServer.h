#pragma once

#include "mdc_netserver_global.h"
#include "qobject.h"
#include "qsharedpointer.h"
#include "qnetworkinterface.h"
#include "../TCPServer/TCPServer.h"
#include "../UDPServer/UDPServer.h"

class MDC_NETSERVER_EXPORT MDC_NetServer : public QObject
{

public:

    MDC_NetServer(QObject *parent);
    ~MDC_NetServer();

    void StartNet();
    void StopNet();

public slots:

    bool slot_SendTCP(const QByteArray& bytes);
    bool slot_SendUDP(const QByteArray& bytes);

signals:
    //void ErrorMessage(const QString& Module, const QString& Class, const QString& function, const QString& strMessage);
    void sig_clentConnected(const QString &json);
    void sig_clientDisconnect(const QString &json);
    void sig_recvClnTCPMsg(const QByteArray& bytes);
    void sig_recvUDPClnMsg(const QByteArray& bytes);
    void ErrorMessage(const QString& Module, const QString& Class, const QString& function, const QString& strMessage);
private slots:
    void em(const QString& function, const QString& strMessage);

private:
    bool bln_init = false;
    void Init();
    bool initNetServer();
    bool initServerConnect();
    //提供三个流
    QSharedPointer<TCPServer> ptr_tcp_selfcheck;
    QSharedPointer<TCPServer> ptr_tcp_commend;
    QSharedPointer<TCPServer> ptr_tcp_file;

    QSharedPointer<UDPServer> ptr_udpserver;

    Connection_Type Connection_Level = Connection_Type::Commend; //TCP流级别


    qint32 current_port = 0;

};
