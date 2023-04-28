#include "TCPServer.h"

TCPServer::TCPServer(QObject *parent)
	: QObject(parent)
{
	//TODO:Ӧ����Ҫ���һ�������ļ��ģ�Ŀǰ����
}

TCPServer::~TCPServer()
{

}

Connection_Type TCPServer::getConnectionType()
{
	return this->Connection_Level;
}

quint16 TCPServer::getServerPort()
{
	return this->current_port;
}

bool TCPServer::StartTCP(Connection_Type ConnectinoLevel)
{
	//��ʼ����ǰ�˿�
	switch (Connection_Level)
	{
	case Connection_Type::SelfCheck:
		this->current_port = tcp_port_selfcheck;
		break;
	case Connection_Type::Commend:
		this->current_port = tcp_port_commend;
		break;
	case Connection_Type::FileTransfer:
		this->current_port = tcp_port_filetransfer;
		break;
	default:
		this->current_port = tcp_port_commend;
		break;
	}

	this->Init();

	//�����̺߳�����
	this->ptr_thread.data()->start();

	return this->ptr_tcp.data()->Open(this->current_port);

}

void TCPServer::Close()
{
	this->ptr_tcp.data()->CloseAllConn();
	this->ptr_tcp.data()->Close();
	this->bln_init = false;
}

quint16 TCPServer::getConnectCount()
{
	return this->ptr_tcp.data()->ConnectCount();
}

void TCPServer::Init()
{
	if (!this->initLocalLANInterface()) {
		return;
	}

	if (ptr_tcp.isNull()) {
		this->ptr_tcp = QSharedPointer<QtTCPServerHandler>(new QtTCPServerHandler(this));
	}
	if (ptr_thread.isNull()) {
		this->ptr_thread = QSharedPointer<QThread>(new QThread(this));
	}

	//��ptr_tcp���õ�������thread��ȥ
	this->ptr_tcp->moveToThread(ptr_thread.data());

	//ע��
	this->initConnect();
	this->bln_init = true;
}

bool TCPServer::initConnect()
{
	
	connect(this->ptr_tcp.data(),
		SIGNAL(NewConn(const QString & clnAddr, const quint16 clnPort, const quint16 port)),
		this,
		SIGNAL(NewConn(const QString & clnAddr, const quint16 clnPort, const quint16 port))
		, Qt::QueuedConnection);

	connect(this->ptr_tcp.data(),
		SIGNAL(NewDisConn(const QString & clnAddr, const quint16 clnPort)),
		this,
		SIGNAL(NewDisConn(const QString & clnAddr, const quint16 clnPort))
		, Qt::QueuedConnection);

	connect(this->ptr_tcp.data(),
		SIGNAL(NewDisConnEx(const QString & clnAddr, const quint16 clnPort, QString errString)),
		this,
		SIGNAL(NewDisConnEx(const QString & clnAddr, const quint16 clnPort, QString errString))
		, Qt::QueuedConnection);

	connect(this->ptr_tcp.data(),
		SIGNAL(RecvClnMsg(const QString & clnAddr, const quint16 clnPort, const QByteArray & bytes)),
		this,
		SIGNAL(RecvClnMsg(const QString & clnAddr, const quint16 clnPort, const QByteArray & bytes))
		, Qt::QueuedConnection);


	return true;
}


bool TCPServer::initLocalLANInterface()
{
	QList<QNetworkInterface> network = QNetworkInterface::allInterfaces();    // ��ȡ���еĽӿ�
	foreach(QNetworkInterface net, network) {
		QNetworkInterface::InterfaceFlags flags = net.flags();
		QString netName = net.humanReadableName();

		QList<QNetworkAddressEntry> list = net.addressEntries(); // ��ȡIP��ַ�����������

		if (flags.testFlag(QNetworkInterface::IsLoopBack) ||
			!flags.testFlag(QNetworkInterface::IsRunning) ||
			netName.contains("VM")) {
			continue;
		}

		for (QNetworkAddressEntry address : list) {

			if (address.ip().protocol() == QAbstractSocket::IPv4Protocol) {
				qDebug() << "��������" << netName
					<< " IPv4��" << address.ip().toString()
					<< " �������룺" << address.netmask().toString();

				this->local_network_interface = address;
				qDebug() << "Init Local LAN Interfaces Success!";
				return true;
			}
		}
	}
	qDebug() << "Init Local LAN Interfaces Failed!";
	this->em("initLocalLANInterface", "Init Local LAN Interfaces Failed!");
	return false;
}

void TCPServer::em(const QString& function, const QString& strMessage) {
	emit this->ErrorMessage(function, strMessage);
}

void TCPServer::SendMsg(const QByteArray& bytes, QString clnAddr = "", quint16 clnPort = 0) {

}