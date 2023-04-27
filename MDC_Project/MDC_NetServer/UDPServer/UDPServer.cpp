#include "UDPServer.h"

UDPServer::UDPServer(QObject *parent)
	: QObject(parent)
{

}

UDPServer::~UDPServer()
{

}

bool UDPServer::StartNetwork()
{

	return false;
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




}

void UDPServer::InitConnect()
{
	connect(this->ptr_udp.data(),
		SIGNAL(RecvedUdp(const QByteArray & bytes, const QString & qsFrom, const quint16 port)),
		this,
		SIGNAL(RecvedUdp(const QByteArray & bytes, const QString & qsFrom, const quint16 port)));


}

