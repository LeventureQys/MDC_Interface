#include "UDPServer.h"

UDPServer::UDPServer(QObject *parent)
	: QObject(parent)
{
	 //TODO:应该是要添加一个配置文件的，目前留空

}

UDPServer::~UDPServer()
{

}
void UDPServer::SendUdp(const QByteArray& bytes, const QString& qsSendTo, quint16 port) {
	if (!this->bln_init) {
		this->em("SendUdp", "not init yet");
		return;
	}
	this->ptr_udp.data()->SendUdp(bytes, qsSendTo, port);
}

bool UDPServer::StartNetwork()
{
	this->Init();
	return this->ptr_udp.data()->JoinGroup(this->str_GroupAddr, this->udp_port);
}

bool UDPServer::StopNetwork()
{
	this->bln_init = false;
	return this->ptr_udp.data()->LeaveGroup(this->str_GroupAddr);
}

void UDPServer::em(const QString& function, const QString& strMessage) {
	emit this->ErrorMessage(function, strMessage);
}

void UDPServer::Init()
{
	if (this->ptr_udp.isNull())
		this->ptr_udp = QSharedPointer<QtUdpHandler>(new QtUdpHandler(this));

	if (this->ptr_thread.isNull())
		this->ptr_thread = QSharedPointer<QThread>(new QThread(this));

	this->ptr_udp->moveToThread(this->ptr_thread.data());
	this->ptr_thread.data()->start();
	this->bln_init = true;
}

void UDPServer::InitConnect()
{
	connect(this->ptr_udp.data(),
		SIGNAL(RecvedUdp(const QByteArray & bytes, const QString & qsFrom, const quint16 port)),
		this,
		SIGNAL(RecvedUdp(const QByteArray & bytes, const QString & qsFrom, const quint16 port)));
}

