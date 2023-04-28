#pragma once
//Author:Leventure
//Date:2023.4.27
//Info:������һ�������̵߳�TCP���ӵĿ�
#include <QObject>
#include "qsharedpointer.h"
#include "../Inc/QtTCPServerHandler.h"
#include "qnetworkinterface.h"
#include "qthread.h"
//�����������ȼ�
enum class Connection_Type {
	SelfCheck = 0,          //�Լ�������߼�����
	Commend = 1,            //������
	FileTransfer = 2        //�ļ���
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
	// ������Ϣ
	// bytes����Ϣ����
	// clnAddr��Ŀ���ַ��������գ�����������ӵĿͻ��˷���
	// clnPort��Ŀ��ʹ�õĶ˿ڣ������0���������з��ϵ�ֵַ�Ŀͻ��˽��з���
	void SendMsg(const QByteArray& bytes, QString clnAddr = "", quint16 clnPort = 0);
signals:
	//���ʹ������
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
	//tcp�˿�
	const qint32 tcp_port_selfcheck = 5935; //�Լ�
	const qint32 tcp_port_commend = 5936;   //����
	const qint32 tcp_port_filetransfer = 5937; // �ļ���
	qint32 current_port = 5936;

	void em(const QString& function,const QString& strMessage);
	Connection_Type Connection_Level = Connection_Type::Commend;
	QSharedPointer<QtTCPServerHandler> ptr_tcp;
	QSharedPointer<QThread> ptr_thread;



};
