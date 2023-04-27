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
// Qualifier: ����UDP��Ϣ
// Parameter: const QString & qsMsg		-- ��Ϣ����
// Parameter: const QString qsSendTo	-- ����Ŀ��˿ڣ�Ĭ�����Ѽ�����鲥���ַ
// Parameter: quint16 port				-- ����Ŀ��˿ڣ�Ĭ�����Ѱ󶨵��鲥��˿�
// Info:��Ҫ�ⲿ����Signals�������SendUdp�������ܿ��߳���ת
//************************************
	void SendUdp(const QByteArray& bytes, const QString& qsSendTo = "", quint16 port = 0);

	void em(const QString& function, const QString& strMessage);
signals:
	//���ʹ������
	void ErrorMessage(const QString& function, const QString& strMessage);
	void RecvedUdp(const QByteArray& bytes, const QString& qsFrom, const quint16 port);
	
private:
	void Init();
	void InitConnect();
	const QString str_GroupAddr = "224.114.114.123";
	const quint16 udp_port = 1145;	//udp�鲥��ַ
	QSharedPointer<QtUdpHandler> ptr_udp;
	QSharedPointer<QThread> ptr_thread;


};
