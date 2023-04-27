#pragma once

#include <QObject>
#include "qsharedpointer.h"
#include "../Inc/QtUdpHandler.h"
#include "qthread.h"
class UDPServer  : public QObject
{
	Q_OBJECT

public:


	UDPServer(QObject *parent);
	~UDPServer();

	bool StartNetwork();
	bool StopNetwork();


public slots:
//************************************
// Method:    SendUdp
// FullName:  QtUdpHandler::SendUdp
// Access:    public 
// Returns:   void
// Qualifier: 发送UDP消息
// Parameter: const QString & qsMsg		-- 消息内容
// Parameter: const QString qsSendTo	-- 发送目标端口，默认是已加入的组播组地址
// Parameter: quint16 port				-- 发送目标端口，默认是已绑定的组播组端口
// Info:需要外部发送Signals来给这个SendUdp来令其能跨线程运转
//************************************
	void SendUdp(const QByteArray& bytes, const QString& qsSendTo = "", quint16 port = 0);

	void em(const QString& function, const QString& strMessage);
signals:
	//发送错误代码
	void ErrorMessage(const QString& function, const QString& strMessage);
	void RecvedUdp(const QByteArray& bytes, const QString& qsFrom, const quint16 port);
	
private:
	void Init();
	void InitConnect();
	const QString str_GroupAddr = "224.114.114.123";
	const quint16 udp_port = 1145;	//udp组播地址
	QSharedPointer<QtUdpHandler> ptr_udp;
	QSharedPointer<QThread> ptr_thread;


};
