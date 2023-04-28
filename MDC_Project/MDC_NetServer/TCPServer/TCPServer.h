#pragma once
//Author:Leventure
//Date:2023.4.27
//Info:用于做一个独立线程的TCP连接的库
#include <QObject>
#include "qsharedpointer.h"
#include "../Inc/QtTCPServerHandler.h"
#include "qnetworkinterface.h"
#include "qthread.h"
//决定网络流等级
enum class Connection_Type {
	SelfCheck = 0,          //自检流，最高级命令
	Commend = 1,            //任务流
	FileTransfer = 2        //文件流
};

class TCPServer  : public QObject
{
	Q_OBJECT

public:
	TCPServer(QObject *parent);
	~TCPServer();
	bool StartTCP(Connection_Type ConnectinoLevel);
	Connection_Type getConnectionType();

	quint16 getServerPort();
	void Close();
	quint16 getConnectCount();
public slots:
	// 发送消息
	// bytes：消息内容
	// clnAddr：目标地址，如果传空，则对所有连接的客户端发送
	// clnPort：目标使用的端口，如果传0，则向所有符合地址值的客户端进行发送
	void SendMsg(const QByteArray& bytes, QString clnAddr = "", quint16 clnPort = 0);
signals:
	//发送错误代码
	void ErrorMessage(const QString& function, const QString& strMessage);

	void NewConn(const QString& clnAddr, const quint16 clnPort, const quint16 port);
	void NewDisConn(const QString& clnAddr, const quint16 clnPort);
	void NewDisConnEx(const QString& clnAddr, const quint16 clnPort, QString errString);
	void RecvClnMsg(const QString& clnAddr, const quint16 clnPort, const QByteArray& bytes);

	
private:
	bool bln_init = false;
	void Init();
	bool initLocalLANInterface();
	bool initConnect();

	QNetworkAddressEntry local_network_interface;
	//tcp端口
	const qint32 tcp_port_selfcheck = 5935; //自检
	const qint32 tcp_port_commend = 5936;   //命令
	const qint32 tcp_port_filetransfer = 5937; // 文件流
	qint32 current_port = 5936;

	void em(const QString& function,const QString& strMessage);
	Connection_Type Connection_Level = Connection_Type::Commend;
	QSharedPointer<QtTCPServerHandler> ptr_tcp;
	QSharedPointer<QThread> ptr_thread;



};
