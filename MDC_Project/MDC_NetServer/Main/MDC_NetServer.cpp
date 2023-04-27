#include "MDC_NetServer.h"

MDC_NetServer::MDC_NetServer(QObject *parent):QObject(parent)
{

}

MDC_NetServer::~MDC_NetServer() {

}

void MDC_NetServer::StartNet()
{
	//����������������:
	// ��ʼ��
	//1.����TCP����
	//2.����UDP�鲥
	//3.�������й㲥��ǰTCP����ĵ�ַ
	//4.�ȴ��ͻ�������


	



}
bool MDC_NetServer::initNetServer()
{

	return true;

}
void MDC_NetServer::em(const QString&function,const QString& strMessage)
{
	qDebug() << strMessage;
	//emit this->ErrorMessage("MDC_NetServer", "MDC_NetServer", function, strMessage);

}
void MDC_NetServer::Init() {


	if (!this->initLocalLANInterface()) return;

	if (!this->initNetServer()) return;
	
}
bool MDC_NetServer::initLocalLANInterface()
{
	QList<QNetworkInterface> network = QNetworkInterface::allInterfaces();    // ��ȡ���еĽӿ�
	foreach(QNetworkInterface net, network) {
		QNetworkInterface::InterfaceFlags flags = net.flags();
		QString netName = net.humanReadableName();

		QList<QNetworkAddressEntry> list = net.addressEntries(); // ��ȡIP��ַ�����������

		if(flags.testFlag(QNetworkInterface::IsLoopBack) ||
			!flags.testFlag(QNetworkInterface::IsRunning)||
			netName.contains("VM")) {
			continue;
		}

		for (QNetworkAddressEntry address: list) {

			if (address.ip().protocol() == QAbstractSocket::IPv4Protocol) {
				qDebug() << "��������" << netName
					<< " IPv4��" << address.ip().toString()
					<< " �������룺" << address.netmask().toString();

				this->local_network_interface = net;
				qDebug() << "Init Local LAN Interfaces Success!";
				return true;
			}
		}
	}
	qDebug() << "Init Local LAN Interfaces Failed!";
	this->em("initLocalLANInterface", "Init Local LAN Interfaces Failed!");
	return false;
}
;