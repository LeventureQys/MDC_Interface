#pragma once

#include "mdc_netserver_global.h"
#include "qobject.h"
#include "qsharedpointer.h"
#include "../Inc/QtUdpHandler.h"
#include "qnetworkinterface.h"
#include "../TCPServer/TCPServer.h"

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

    void sig_clentConnected(const QString &json);
    void sig_clientDisconnect(const QString &json);
    void sig_recvClnTCPMsg(const QByteArray& bytes);
    void sig_recvUDPClnMsg(const QByteArray& bytes);

private:

    void Init();
    bool initNetServer();
    bool initLocalLANInterface();

    QNetworkInterface local_network_interface; //����ѡ������
    Connection_Type Connection_Level = Connection_Type::Commend; //TCP������

    void em(const QString& function, const QString& strMessage); //������Ϣ

    qint32 current_port = 0;

};
